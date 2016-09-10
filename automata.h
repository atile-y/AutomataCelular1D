#ifndef AUTOMATA_H
#define AUTOMATA_H

#define MAX_TIME 100000

#include <QBrush>
#include <QPainter>
#include <QTimer>
#include <QWidget>

class Automata : public QWidget{
Q_OBJECT

public:
    Automata(QWidget *parent = 0);
   ~Automata();

    int getSize(){ return m_nSize; }
    short getRule(){ return m_nRule; }
    long long int getTime(){ return m_llnTime; }

    void setSize(int);
    void setRule(short);
    void setTime(long long int);
    void setTape(bool*);

signals:
    void newStep(int);

public slots:
    void reset();
    void play();
    void pause();

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private slots:
    void step();

private:
    bool rule(bool, bool, bool);

    int m_nSize;
    short m_nRule;
    long long int m_llnTime;
    bool m_bAutomata[MAX_TIME][762];
    short m_nIdx;
    bool m_bRunning;
    QBrush m_whiteBrush;
    QBrush m_blackBrush;
    QPainter *m_qPainter;
    QTimer *m_qTimer;
};

#endif // AUTOMATA_H
