#include "frecuencia.h"

#include <QPainter>

#include <iostream>
using namespace std;

Frecuencia::Frecuencia(QWidget *parent) : QWidget(parent){
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

int Frecuencia::getFrequency(long long int i){
    if( i < 0 || i >= m_vFreq.size() )
        return -1;
    return m_vFreq[i];
}

void Frecuencia::setTime(long long int t){
    m_llnTime = t;

    if( m_llnTime < m_vFreq.size() )
        m_vFreq.resize(m_llnTime);
}

void Frecuencia::setMaxOnes(int m){
    m_nMaxOnes = m;
    reset();
}

void Frecuencia::setFrequency(long long int i, int v){
    if( i < 0 || i >= m_vFreq.size() )
        return;
    m_vFreq[i] = v;
}

void Frecuencia::reset(){
    m_vFreq.clear();
}

void Frecuencia::addFrequency(int v){
    m_vFreq.append(v);
}

void Frecuencia::paintEvent(QPaintEvent *){
    double tam = (height() - 10) / m_nMaxOnes;

    QPainter painter(this);

    painter.setPen(QPen(Qt::black));
    painter.drawLine(10, 0, 10, height());
    painter.drawLine(0, height()-10, width(), height()-10);

    painter.setPen(QPen(Qt::red));
    for(int i=0;i<m_vFreq.size();i++)
        painter.drawPoint(10 + i*tam, (height() - 10) - m_vFreq[i]*tam);
}
