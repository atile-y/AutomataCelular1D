#ifndef FRECUENCIA_H
#define FRECUENCIA_H

#include <QWidget>

class Frecuencia : public QWidget
{
    Q_OBJECT
public:
    Frecuencia(QWidget *parent = 0);

    long long int getTime(){ return m_llnTime; }
    int getMaxOnes(){ return m_nMaxOnes; }
    int getFrequency(long long int);

    void setTime(long long int);
    void setMaxOnes(int);
    void setFrequency(long long int, int);

public slots:
    void reset();
    void addFrequency(int);

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private:
    long long int m_llnTime;
    int m_nMaxOnes;
    QVector<int> m_vFreq;
};

#endif // FRECUENCIA_H
