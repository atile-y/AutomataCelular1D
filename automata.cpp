#include "automata.h"

#include <QPainter>

#include <iostream>
using namespace std;

Automata::Automata(QWidget *parent) : QWidget(parent){
    m_nSize = 300;
    m_nRule = 90;
    m_nPercentOnes = 50;
    m_bTape = new bool*[2];
    m_bTape[0] = new bool[300];
    m_bTape[1] = new bool[300];
    m_nIdx = 0;

    m_uidDist = std::uniform_int_distribution<int>(0, 299);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedHeight(351);
    setFixedWidth(351);

    m_whiteBrush = QBrush(Qt::white);
    m_blackBrush = QBrush(Qt::black);
}

Automata::~Automata(){
    delete []m_bTape;
}

bool Automata::getCell(int i){
    if( i < 0 || i >= m_nSize )
        return false;
    return m_bTape[0][i];
}

void Automata::setSize(int s){
    m_nSize = s;
    m_nIdx = 0;

    delete m_bTape[0];
    delete m_bTape[1];

    m_bTape[0] = new bool[m_nSize];
    m_bTape[1] = new bool[m_nSize];
}

void Automata::setCell(int i, bool v){
    if( i < 0 || i >= m_nSize )
        return;

    m_bTape[0][i] = v;
    m_nIdx = 0;
    update();
}

void Automata::setTape(bool *arr){
    for(int i=0;i<m_nSize;i++)
        m_bTape[0][i] = arr[i];

    m_nIdx = 0;
    update();
}

void Automata::paintEvent(QPaintEvent *){
    double tam = (width() - 1.0) / m_nSize;

    QPainter painter(this);

    for(int t=0;t<m_nSize;t++){
        for(int i=0;i<m_nSize;i++){
            painter.save();
            painter.translate(i*tam, t*tam);
            if( m_bTape[m_nIdx][i] ){
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
        updateTape();
    }
}

void Automata::updateTape(){
    for(int i=0;i<m_nSize;i++)
        m_bTape[(m_nIdx+1)%2][i] = rule(m_bTape[m_nIdx][(i+m_nSize-1)%m_nSize], m_bTape[m_nIdx][i], m_bTape[m_nIdx][(i+1)%m_nSize]);
    m_nIdx = (m_nIdx+1)%2;
}

bool Automata::rule(bool a, bool b, bool c){
    int bit = 4*a + 2*b + c;

    return ((1<<bit) & m_nRule) != 0;
}
