#include "frecuencia.h"

#include <QDebug>
#include <QTimer>
#include <GL/glu.h>

Frecuencia::Frecuencia(QWidget *parent) : QOpenGLWidget(parent){
    setWindowFlags(Qt::Window);
    setWindowTitle(tr("Diagrama de Frecuencia"));
    setMinimumWidth(400);
    setMinimumHeight(400);
    resize(500, 500);
    move(550, 400);

    m_bFirstDisplay = false;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Idle()));
    timer->start(20);
}

Frecuencia::~Frecuencia(){
    while( !children().isEmpty() )
        delete children()[0];
}

void Frecuencia::reset(){
    m_vFreq.clear();
    m_bFirstDisplay = true;
}

void Frecuencia::Idle(){
    update();
}

void Frecuencia::addFrequency(uint v){
    m_vFreq.append(v);
}

void Frecuencia::initializeGL(){
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void Frecuencia::resizeGL(int width, int height){
    GLdouble bot = -(m_nMaxOnes/18.0), top = m_nMaxOnes*19.0/18.0;
    GLdouble left = bot, right = top;
    GLdouble midX = (right-left)/2.0, midY = (top-bot)/2.0;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(left, right, bot, top);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(midX, midY, 10, midX, midY, 0, 0, 1, 0);
}

void Frecuencia::paintGL(){
    if( m_bFirstDisplay ){
        GLdouble bot = -(m_nMaxOnes/18.0), top = m_nMaxOnes*19.0/18.0;
        GLdouble left = bot, right = top;
        GLdouble midX = (right-left)/2.0, midY = (top-bot)/2.0;

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(left, right, bot, top);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        gluLookAt(midX, midY, 10, midX, midY, 0, 0, 1, 0);
        m_bFirstDisplay = false;
    }

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_LINES);
        glVertex2i(0, 0);
        glVertex2i(0, m_nMaxOnes);
        glVertex2i(0, 0);
        glVertex2i(m_nTime == 0 ? m_vFreq.size() : m_nTime, 0);
    glEnd();

    glColor3f(0.7, 0.3, 0.3);
    glPointSize(2.0);
    if( !m_vFreq.isEmpty() ){
        glBegin(GL_POINTS);
            glVertex2i(0, m_vFreq.at(0));
        glEnd();
    }
    for(int i=1;i<m_vFreq.size();i++){
        glColor3f(0.7, 0.3, 0.3);
        glBegin(GL_POINTS);
            glVertex2i(i, m_vFreq.at(i));
        glEnd();
        glColor3f(0.3, 0.3, 0.7);
        glBegin(GL_LINES);
            glVertex2i(i-1, m_vFreq.at(i-1));
            glVertex2i(i, m_vFreq.at(i));
        glEnd();
    }
}
