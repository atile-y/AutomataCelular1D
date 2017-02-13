#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject{
    Q_OBJECT

public:
    Worker(ushort = 0, ulong = 500);

    void setRule(ushort r){ m_nRule = r; }
    void setDelay(ulong d){ m_nDelay = d; }

signals:
    void add(bool *);

public slots:
    void evolve(bool *, uint);

private:
    bool rule(bool, bool, bool);

    ushort m_nRule;
    ulong m_nDelay;
};

#endif // WORKER_H
