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

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Idle()));
    timer->start(20);
}

Frecuencia::~Frecuencia(){
    qInfo() << "Frecuencia Destructor begin";
    while( !children().isEmpty() )
        delete children()[0];
    qInfo() << "Frecuencia Destructor end";
}

void Frecuencia::reset(){
    m_vFreq.clear();
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
    gluLookAt(0, 0, 50, 0, 0, 0, 0, 1, 0);
}

void Frecuencia::resizeGL(int width, int height){
    GLdouble w = width, h = height;
    GLdouble right = m_nTime*5.0/4.0, bot = -m_nMaxOnes*5.0/4.0;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, right, bot, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(right/2, bot/2, 10, right/2, bot/2, 0, 0, 1, 0);
}

void Frecuencia::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_LINE_STRIP);
        glVertex2i(1, 1);
        glVertex2i(3, 2);
        glVertex2i(5, 5);
    glEnd();
}
