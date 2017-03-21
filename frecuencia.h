#ifndef FRECUENCIA_H
#define FRECUENCIA_H

#include <QOpenGLWidget>

class Frecuencia : public QOpenGLWidget{
    Q_OBJECT

public:
    explicit Frecuencia(QWidget *parent = 0);
    ~Frecuencia();

    uint getMaxOnes(){ return m_nMaxOnes; }

    void setTime(ulong t){ m_nTime = t; }
    void setMaxOnes(uint m){ m_nMaxOnes = m; }

    void reset();

public slots:
    void Idle();
    void addFrequency(uint);

protected:
    void initializeGL();
    void resizeGL(int, int);
    void paintGL();

private:
    ulong m_nTime;
    uint m_nMaxOnes;
    QVector<uint> m_vFreq;
    bool m_bFirstDisplay;
};

#endif // FRECUENCIA_H
