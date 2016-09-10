#include "automata.h"

#include <QPainter>

#include <iostream>
using namespace std;

Automata::Automata(QWidget *parent) : QWidget(parent){
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    m_whiteBrush = QBrush(Qt::white);
    m_blackBrush = QBrush(Qt::black);
}

Automata::~Automata(){
    delete []m_bTape;
}

void Automata::setTape(bool *arr){
    QVector<int> freq;
    int numOnes = 0;
    m_bTape = new bool*[m_nTime];

    m_bTape[0] = new bool[m_nSize];
    for(int i=0;i<m_nSize;i++){
        m_bTape[0][i] = arr[i];
        if( m_bTape[0][i] )
            numOnes++;
    }
    freq.append(numOnes);

    for(int i=1;i<m_nTime;i++){
        m_bTape[i] = new bool[m_nSize];
        numOnes = 0;
        for(int j=0;j<m_nSize;j++){
            m_bTape[i][j] = rule(m_bTape[i-1][(j+m_nSize-1)%m_nSize],
                                 m_bTape[i-1][j],
                                 m_bTape[i-1][(j+1)%m_nSize]);
            if( m_bTape[i][j] )
                numOnes++;
        }
        freq.append(numOnes);
    }

    emit endEvolve(freq);
    update();
}

void Automata::paintEvent(QPaintEvent *){
    double tam = ((double)width()) / m_nSize;
    QPainter painter(this);

    for(int t=0;t<m_nTime;t++){
        for(int i=0;i<m_nSize;i++){
            painter.save();
            painter.translate(i*tam, t*tam);
            if( m_bTape[t][i] ){
                painter.setBrush(m_blackBrush);
                painter.setPen(QPen(Qt::black));
            }
            else{
                painter.setBrush(m_whiteBrush);
                painter.setPen(QPen(Qt::white));
            }
            painter.drawRect(0, 0, tam, tam);
            painter.restore();
        }
    }
}

bool Automata::rule(bool a, bool b, bool c){
    int bit = 4*a + 2*b + c;

    return ((1<<bit) & m_nRule) != 0;
}
