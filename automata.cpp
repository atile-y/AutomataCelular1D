#include "automata.h"

#include <iostream>
using namespace std;

Automata::Automata(QWidget *parent) : QWidget(parent){
    memset(m_bAutomata, 0, sizeof(bool)*MAX_TIME*762);

    m_nIdx = 0;
    m_bRunning = false;
    m_whiteBrush = QBrush(Qt::white);
    m_blackBrush = QBrush(Qt::black);

    m_qPainter = new QPainter(this);

    m_qTimer = new QTimer(this);
    connect(m_qTimer, SIGNAL(timeout()), this, SLOT(step()));

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

Automata::~Automata(){
    delete m_qTimer;
}

void Automata::setSize(int s){
    int oldSize = m_nSize;

    m_nSize = s;

    for(int i=oldSize;i<m_nSize;i++)
        m_bAutomata[0][i] = false;

    reset();
}

void Automata::setRule(short r){
    m_nRule = r;
    reset();
}

void Automata::setTime(long long t){
    m_llnTime = t;
    if( m_nIdx > m_llnTime )
        pause();
}

void Automata::setTape(bool *arr){
    for(int i=0;i<m_nSize;i++)
        m_bAutomata[0][i] = arr[i];

    reset();
}

void Automata::reset(){
    pause();

    for(long long int t=1;t<=m_nIdx;t++)
        for(int i=1;i<m_nSize;i++)
            m_bAutomata[t][i] = false;

    m_nIdx = 0;
}

void Automata::play(){
    cout << "Play [" << (m_bRunning?"Running]\n":"Not Running] -> ");
    if( !m_bRunning ){
        cout << "Running" << endl;
        m_bRunning = true;
        m_qTimer->start(10);
    }
}

void Automata::pause(){
    cout << "Pause [" << (m_bRunning?"Running] -> ":"Not Running]\n");
    if( m_bRunning ){
        cout << "Not Running" << endl;
        m_bRunning = false;
        m_qTimer->stop();
    }
}

void Automata::paintEvent(QPaintEvent *){
    double tam = ((double)width()) / m_nSize;

    m_qPainter->

//    for(long long int t=0;t<=m_nIdx;t++){
        for(int i=0;i<m_nSize;i++){
            painter->save();
            painter->translate(i*tam, m_nIdx*tam);
            if( m_bAutomata[m_nIdx][i] ){
                painter->setBrush(m_blackBrush);
                painter->setPen(QPen(Qt::black));
            }
            else{
                painter->setBrush(m_whiteBrush);
                painter->setPen(QPen(Qt::white));
            }
            painter->drawRect(0, 0, tam, tam);
            painter->restore();
        }
  //  }
}

void Automata::step(){
    int numOnes = 0;

    for(int i=0;i<m_nSize;i++){
        m_bAutomata[m_nIdx+1][i] = rule(m_bAutomata[m_nIdx][(i+m_nSize-1)%m_nSize],
                                        m_bAutomata[m_nIdx][i],
                                        m_bAutomata[m_nIdx][(i+1)%m_nSize]);
        if( m_bAutomata[m_nIdx+1][i] )
            numOnes++;
    }

    emit newStep(numOnes);
    m_nIdx++;
    if( m_nIdx == m_llnTime )
        pause();
    update();
}

bool Automata::rule(bool a, bool b, bool c){
    int bit = 4*a + 2*b + c;

    return ((1<<bit) & m_nRule) != 0;
}
