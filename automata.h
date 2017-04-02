#ifndef AUTOMATA_H
#define AUTOMATA_H

#define STOP    1
#define PAUSE   2
#define PLAY    3

#include <QOpenGLWidget>
#include <QThread>
#include <QVector>

#include "worker.h"

class Automata : public QOpenGLWidget{
    Q_OBJECT

public:
    explicit Automata(QWidget *parent = 0);
    ~Automata();

    uint getSize(){ return m_nSize; }
    ushort getRule(){ return m_nRule; }
    ulong getTime(){ return m_nTime; }
    ushort getState(){ return m_nState; }
    bool *getInitTape();

    void setSize(uint);
    void setRule(ushort r){ m_nRule = r; }
    void setTime(ulong t){ m_nTime = t; }
    void setTape(bool*);

    void play();
    void pause();
    void reset();

    bool saveTape(QString);
    bool readTape(QString);

public slots:
    void Idle();
    void addState(bool *);

signals:
    void newStep(uint);
    void evolve(bool *, uint);
    void endTime();

protected:
    void initializeGL();
    void resizeGL(int, int);
    void paintGL();

    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void wheelEvent(QWheelEvent *);

private:
    uint m_nSize;
    ushort m_nRule;
    ulong m_nTime;
    ushort m_nState;
    bool m_bFirstDisplay;
    bool m_bClick;
    double m_nScale;
    double m_nZoom;
    int m_nScroll;
    QPointF m_pOldM;
    QPointF m_pMouse;
    QPointF m_pMove;
    QVector<bool*> m_vTape;
    Worker *m_Work;
    QThread *m_Thread;
};

#endif // AUTOMATA_H
