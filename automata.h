#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <QBrush>
#include <QWidget>

class Automata : public QWidget{
Q_OBJECT

public:
    Automata(QWidget *parent = 0);
   ~Automata();

    int getSize(){ return m_nSize; }
    short getRule(){ return m_nRule; }
    int getTime(){ return m_nTime; }

    void setSize(int s){ m_nSize = s; }
    void setRule(short r){ m_nRule = r; }
    void setTime(int t){ m_nTime = t; }
    void setTape(bool*);

signals:
    void endEvolve(QVector<int>);

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private:
    bool rule(bool, bool, bool);

    int m_nSize;
    short m_nRule;
    int m_nTime;
    bool **m_bTape;
    QBrush m_whiteBrush;
    QBrush m_blackBrush;
};

#endif // AUTOMATA_H
