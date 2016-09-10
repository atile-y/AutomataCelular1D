#ifndef FRECUENCIA_H
#define FRECUENCIA_H

#include <QWidget>

class Frecuencia : public QWidget
{
    Q_OBJECT
public:
    explicit Frecuencia(QWidget *parent = 0);

    void setMaxOnes(int m){ m_nMaxOnes = m; }

public slots:
    void setData(QVector<int>);

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private:
    int m_nMaxOnes;
    QVector<int> m_vFreq;
};

#endif // FRECUENCIA_H
