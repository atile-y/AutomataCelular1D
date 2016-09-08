#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <QBrush>
#include <QWidget>

#include <random>

class Automata : public QWidget{
Q_OBJECT

public:
    Automata(QWidget *parent = 0);
   ~Automata();

    int getSize(){ return m_nSize; }
    short getRule(){ return m_nRule; }
    long long int getTime(){ return m_llnTime; }
    short getPercentOnes(){ return m_nPercentOnes; }
    bool getCell(int);

    void setSize(int);
    void setRule(short r){ m_nRule = r; }
    void setTime(long long int t){ m_llnTime = t; }
    void setPercentOnes(short p){ m_nPercentOnes = p; }
    void setCell(int, bool);
    void setTape(bool*);

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private:
    void updateTape();
    bool rule(bool, bool, bool);

    int m_nSize;
    short m_nRule;
    long long int m_llnTime;
    bool **m_bTape;
    short m_nPercentOnes;
    short m_nIdx;
    std::default_random_engine m_dreGenerator;
    std::uniform_int_distribution<int> m_uidDist;
    QBrush m_whiteBrush;
    QBrush m_blackBrush;
};

#endif // AUTOMATA_H
