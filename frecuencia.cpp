#include "frecuencia.h"

#include <QPainter>

#include <iostream>
using namespace std;

Frecuencia::Frecuencia(QWidget *parent) : QWidget(parent){
    m_vFreq.clear();

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

void Frecuencia::setData(QVector<int> d){
    m_vFreq.clear();
    for(int i=0;i<d.size();i++)
        m_vFreq.append(d[i]);
    update();
}

void Frecuencia::paintEvent(QPaintEvent *){
    double tamX = (width() - 20.0) / m_vFreq.size();
    double tamY = (height() - 20.0) / m_nMaxOnes;

    QPainter painter(this);
    painter.setPen(QPen(Qt::black));
    painter.drawLine(10, 0, 10, height());
    painter.drawLine(0, height()-10, width(), height()-10);

    if( m_nMaxOnes > 0 ){
        painter.setPen(palette().dark().color());
        for(int i=10;i<=m_nMaxOnes;i+=10)
            painter.drawLine(10, height()-10-i*tamY, width(), height()-10-i*tamY);
    }

    painter.setPen(QPen(Qt::blue));
    for(int i=1;i<m_vFreq.size();i++){
        painter.drawLine((i-1) * tamX + 10, height() - 10 - m_vFreq[i-1] * tamY,
                         i * tamX + 10, height() - 10 - m_vFreq[i] * tamY);
    }
}
