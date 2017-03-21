#ifndef UNIVERSESCANNER_H
#define UNIVERSESCANNER_H

#define TODAS           1
#define EQUIVALENTES    2

#include <QObject>

class UniverseScanner : public QObject{
    Q_OBJECT

public:
    UniverseScanner(uint, QString);
    ~UniverseScanner();

signals:
    void startRule(int);
    void endScanning();

public slots:
    void scan(int);

private:
    bool rule(bool, bool, bool, int);

    uint m_nSize;
    QString m_strPath;
    bool *m_Tape[3];
    uint m_Freq[3];
    QString m_Desc[3];
};

#endif // UNIVERSESCANNER_H
