#include "universescanner.h"

#include <QDebug>
#include <QImage>
#include <QPainter>
#include <QPen>

#include <chrono>
#include <random>

UniverseScanner::UniverseScanner(uint size, QString path){
    m_nSize = size;
    m_strPath = path;

    for(int i=0;i<3;i++){
        m_Tape[i] = new bool[m_nSize];
        memset(m_Tape[i], 0, m_nSize);
    }
    m_Tape[0][m_nSize/2] = true;
    m_Freq[0] = 1;
    m_Desc[0] = "central";
    m_Desc[1] = "50p";
    m_Desc[2] = "10p";

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> dist(0, m_nSize-1);

    // Cinta inicial con una densidad al 50%
    double numOnes = 50.0 * m_nSize / 100.0;
    uint m = (uint)numOnes, j;
    std::uniform_real_distribution<double> d(0.0, 1.0);

    if( d(generator) < numOnes - m )
        m++;

    for(uint i=0;i<m;i++){
        do j = dist(generator);
        while( m_Tape[1][j] );
        m_Tape[1][j] = true;
    }

    m_Freq[1] = m;

    // Cinta inicial con una densidad al 10%
    dist.reset();
    d.reset();
    numOnes = 10.0 * size / 100.0;
    m = (uint)numOnes;

    if( d(generator) < numOnes - m )
        m++;

    for(uint i=0;i<m;i++){
        do j = dist(generator);
        while( m_Tape[2][j] );
        m_Tape[2][j] = true;
    }

    m_Freq[2] = m;
}

UniverseScanner::~UniverseScanner(){
    for(int i=0;i<3;i++)
        delete m_Tape[i];
}

void UniverseScanner::scan(int m){
    QImage *autoImg, *freqImg;
    bool tape[2][m_nSize];
    uchar *row, n = 0;
    uint col, f;
    double med, var;
    QVector<int> rules;
    QVector<uint> freq;
    QPainter freqPaint;

    QPen black;
    black.setWidth(2);
    black.setColor(Qt::black);

    QPen gray;
    gray.setWidth(1);
    gray.setColor(Qt::gray);

    QPen blue;
    blue.setWidth(1);
    blue.setColor(QColor(0, 102, 255));

    QPen green;
    green.setWidth(2);
    green.setColor(QColor(0, 153, 51));

    QPen red;
    red.setWidth(2);
    red.setColor(QColor(204, 0, 0));

    if( m == TODAS )
        for(int i=0;i<256;i++)
            rules.append(i);
    else if( m == EQUIVALENTES ){
        for(int i=0;i<=15;i++)
            rules.append(i);
        rules << 18 << 19;
        for(int i=22;i<=46;i++)
            if( i != 31 && i != 39 )
                rules.append(i);
        rules << 50 << 51 << 54 << 56 << 57 << 58 << 60 << 62;
        rules << 72 << 73 << 74 << 76 << 77 << 78 << 90 << 94;
        rules << 104 << 105 << 106 << 108 << 110 << 122;
        for(int i=126;i<=142;i+=2)
            rules.append(i);
        for(int i=146;i<=172;i+=2)
            if( i != 148 && i != 158 && i != 166 )
                rules.append(i);
        rules << 178 << 184 << 200 << 204 << 232;
    }

    autoImg = new QImage(m_nSize, m_nSize, QImage::Format_Mono);
    autoImg->setColorTable(QVector<QRgb>() << qRgb(255, 255, 255) << qRgb(0, 0, 0));

    freqImg = new QImage(2*m_nSize+20, 2*m_nSize+50, QImage::Format_RGB32);

    for(int r : rules){
        emit startRule(r);

        for(int j=0;j<3;j++){
            freqImg->fill(QColor(255, 255, 255));
            freqPaint.begin(freqImg);
            freqPaint.setPen(black);
            freqPaint.drawLine(10, 40, 10, 2*m_nSize + 40);
            freqPaint.drawLine(10, 2*m_nSize + 40, 2*m_nSize + 10, 2*m_nSize + 40);
            freqPaint.setPen(gray);
            for(uint i=m_nSize/10;i<m_nSize;i+=m_nSize/10){
                freqPaint.drawLine(2*i + 10, 40, 2*i + 10, 2*m_nSize + 40);
                freqPaint.drawLine(10, 2*m_nSize + 40 - 2*i,
                                   2*m_nSize + 10, 2*m_nSize + 40 - 2*i);
            }

            freq.clear();
            med = 0;

            row = autoImg->scanLine(0);
            col = f = 0;
            for(uint i=0;i<m_nSize;i++){
                tape[0][i] = m_Tape[j][i];
                if( i%8 == 0 ){
                    if( i != 0 )
                        row[col++] = n;
                    n = tape[0][i];
                }
                else
                    n = 2*n + tape[0][i];

                if( tape[0][i] )
                    f++;
            }
            row[col] = m_nSize%8 == 0 ? n : n<<(8-m_nSize%8);
            freq.append(f);
            med += f;

            freqPaint.setPen(blue);
            for(uint i=1;i<m_nSize;i++){
                row = autoImg->scanLine(i);
                col = f = 0;
                for(uint k=0;k<m_nSize;k++){
                    tape[i%2][k] = rule(tape[(i+1)%2][(k+m_nSize-1)%m_nSize],
                                        tape[(i+1)%2][k],
                                        tape[(i+1)%2][(k+1)%m_nSize], r);

                    if( k%8 == 0 ){
                        if( k != 0 )
                            row[col++] = n;
                        n = tape[i%2][k];
                    }
                    else
                        n = 2*n + tape[i%2][k];

                    if( tape[i%2][k] )
                        f++;
                }
                row[col] = m_nSize%8 == 0 ? n : n<<(8-m_nSize%8);
                freqPaint.drawLine(2*(i-1) + 10, 2*m_nSize + 40 - 2*freq.last(),
                                   2*i + 10, 2*m_nSize + 40 - 2*f);

                freq.append(f);
                med += f;
            }
            med /= m_nSize;
            var = 0;
            for(uint i=0;i<m_nSize;i++)
                var += pow(freq.at(i) - med, 2);
            var /= m_nSize;

            freqPaint.setPen(green);
            freqPaint.drawLine(10, 2*m_nSize + 40 - 2*med,
                               2*m_nSize + 10, 2*m_nSize + 40 - 2*med);
            freqPaint.drawText(m_nSize - 110, 25, QString("Media: %1").arg(med));
            freqPaint.setPen(red);
            if( var < m_nSize ){
                freqPaint.drawLine(10, 2*m_nSize + 40 - 2*var,
                                   2*m_nSize + 10, 2*m_nSize + 40 - 2*var);
            }
            freqPaint.drawText(m_nSize + 20, 25, QString("Varianza: %1").arg(var));

            freqPaint.setPen(black);
            freqPaint.drawText(20, 25, QString("Celúlas: %1").arg(m_nSize));

            freqPaint.end();

            autoImg->save(m_strPath + QString("/R%1_%2.png").arg(r).arg(m_Desc[j]));
            freqImg->save(m_strPath + QString("/R%1_%2_F.png").arg(r).arg(m_Desc[j]));
        }
    }

    emit endScanning();
}

bool UniverseScanner::rule(bool a, bool b, bool c, int r){
    int bit = 4*a + 2*b + c;

    return ((1<<bit) & r) != 0;
}
