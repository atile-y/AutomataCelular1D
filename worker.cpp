#include "worker.h"

#include <QThread>

Worker::Worker(ushort r){
    m_nRule = r;
}

void Worker::evolve(bool *t, uint s){
    bool r[s];

    for(uint i=0;i<s;i++)
        r[i] = rule(t[(i+s-1)%s], t[i], t[(i+1)%s]);

    emit add(r);
}

bool Worker::rule(bool a, bool b, bool c){
    int bit = 4*a + 2*b + c;

    return ((1<<bit) & m_nRule) != 0;
}
