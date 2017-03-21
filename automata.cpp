#include "automata.h"

#include <QDebug>
#include <QMouseEvent>
#include <QTimer>
#include <GL/glu.h>

Automata::Automata(QWidget *parent) : QOpenGLWidget(parent){
    setWindowFlags(Qt::Window);
    setWindowTitle(tr("Automata"));
    setMinimumWidth(400);
    setMinimumHeight(400);
    resize(500, 500);
    move(25, 400);

    m_nState = STOP;
    m_Work = NULL;
    m_Thread = NULL;
    m_bFirstDisplay = false;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Idle()));
    timer->start(20);
}

Automata::~Automata(){
    while( !children().isEmpty() )
        delete children()[0];

    if( m_Thread != NULL ){
        m_Thread->quit();
        m_Thread->wait();
        delete m_Thread;
        if( m_Work != NULL )
            delete m_Work;
    }
}

void Automata::setSize(uint s){
    m_nSize = s;
    m_nScale = ((double)m_nSize) / this->width();
}

void Automata::setTape(bool *arr){
    reset();

    m_vTape.clear();
    bool *t = new bool[m_nSize];

    for(uint i=0;i<m_nSize;i++)
        t[i] = arr[i];

    m_vTape.append(t);
}

void Automata::play(){
    if( m_nState == STOP ){
        reset();
        m_bFirstDisplay = true;

        m_Thread = new QThread;
        m_Work = new Worker(m_nRule);
        m_Work->moveToThread(m_Thread);

        connect(this, SIGNAL(evolve(bool*,uint)), m_Work, SLOT(evolve(bool*,uint)));
        connect(m_Work, SIGNAL(add(bool*)), this, SLOT(addState(bool*)));

        m_Thread->start();

        if( m_vTape.isEmpty() ){
            bool *t = new bool[m_nSize];
            m_vTape.append(t);
        }

        emit evolve(m_vTape.last(), m_nSize);
    }
    else if( m_nState == PAUSE )
        emit evolve(m_vTape.last(), m_nSize);

    m_nState = PLAY;
    update();
}

void Automata::pause(){
    m_nState = PAUSE;
}

void Automata::reset(){
    if( m_Thread != NULL ){
        m_Thread->quit();
        m_Thread->wait();
        delete m_Thread;
        m_Thread = NULL;
        if( m_Work != NULL ){
            delete m_Work;
            m_Work = NULL;
        }
    }

    m_nState = STOP;
}

void Automata::Idle(){
    update();
}

void Automata::addState(bool *s){
    bool *t = new bool[m_nSize];
    uint f = 0;

    for(uint i=0;i<m_nSize;i++){
        t[i] = s[i];
        if( t[i] )
            f++;
    }

    m_vTape.append(t);

    if( (uint)m_vTape.size() >= m_nTime && m_nTime > 0 ){
        m_nState = PAUSE;
        emit endTime();
    }

    if( m_nState == PLAY )
        emit evolve(t, m_nSize);
    emit newStep(f);
}

void Automata::initializeGL(){
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void Automata::resizeGL(int width, int height){
    GLdouble w = width, h = height;
    GLdouble right = m_nSize, bot = -h*m_nSize/w;

    m_nScale = ((double)m_nSize) / w;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, right, bot, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(right/2, bot/2, 10, right/2, bot/2, 0, 0, 1, 0);
}

void Automata::paintGL(){
    if( m_bFirstDisplay ){
        GLdouble w = this->width(), h = this->height();
        GLdouble right = m_nSize, bot = -h*m_nSize/w;

        m_nScale = ((double)m_nSize) / w;
        m_nZoom = 1.0;

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, right, bot, 0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        gluLookAt(right/2, bot/2, 10, right/2, bot/2, 0, 0, 1, 0);
        m_pMove = QPoint();
        m_nScroll = 0;
        m_bFirstDisplay = false;
    }

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(0.0f, 0.0f, 0.0f);

    glTranslatef(-m_pMove.x(), m_pMove.y(), 0.0f);
    glScaled(m_nZoom, m_nZoom, 0.0);

    for(int i=0;i<m_vTape.size();i++){
        for(uint j=0;j<m_nSize;j++){
            if( m_vTape.at(i)[j] ){
                glBegin(GL_TRIANGLE_STRIP);
                    glVertex2i(j, -i-1);
                    glVertex2i(j, -i);
                    glVertex2i(j+1, -i-1);
                    glVertex2i(j+1, -i);
                glEnd();
            }
        }
    }
}

void Automata::mouseMoveEvent(QMouseEvent *event){
    if( !m_bClick )
        return;

    m_pMove += (m_pOldM - event->screenPos()) * m_nScale;
    m_pOldM = event->screenPos();
}

void Automata::mousePressEvent(QMouseEvent *event){
    if( event->button() != Qt::LeftButton )
        return;

    m_bClick = true;
    m_pOldM = event->screenPos();
}

void Automata::mouseReleaseEvent(QMouseEvent *event){
    if( event->button() != Qt::LeftButton )
        return;

    m_bClick = false;
}

void Automata::wheelEvent(QWheelEvent *event){
    int base = 120;
    int scroll = event->pixelDelta().y();

    if( scroll == 0 )
        scroll = event->angleDelta().y();

    m_nScroll += scroll;

    scroll = m_nScroll / base;
    m_nScroll = m_nScroll % base;

    if( scroll > 0 )
        m_nZoom *= (2 * scroll);
    else if( scroll < 0 )
        m_nZoom /= (2 * -scroll);
}
