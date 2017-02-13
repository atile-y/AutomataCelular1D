#include "worker.h"

#include <QThread>
#include <QTime>

Worker::Worker(ushort r, ulong d){
    m_nRule = r;
    m_nDelay = d;
}

void Worker::evolve(bool *t, uint s){
    QTime ini;
    ini.start();

    bool r[s];

    for(uint i=0;i<s;i++)
        r[i] = rule(t[(i+s-1)%s], t[i], t[(i+1)%s]);

    int lap = ini.elapsed();
    if( m_nDelay - lap > 0 )
        QThread::msleep(m_nDelay - lap);
    emit add(r);
}

bool Worker::rule(bool a, bool b, bool c){
    int bit = 4*a + 2*b + c;

    return ((1<<bit) & m_nRule) != 0;
}
