#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "automata.h"
#include "frecuencia.h"

#include <QLabel>
#include <QMainWindow>
#include <QTableWidgetItem>

#include <random>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void on_lengthLineEdit_editingFinished();
    void on_ruleLineEdit_editingFinished();
    void on_timeLineEdit_editingFinished();
    void on_playPushButton_clicked();
    void on_pausePushButton_clicked();
    void on_stopPushButton_clicked();
    void on_percentLineEdit_editingFinished();
    void on_percentHorizontalSlider_valueChanged(int);

private:
    void initTape();

    Ui::MainWindow *ui;
    Automata *automata;
    Frecuencia *frecuencia;
    QTableWidgetItem *protoItem;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> dist;
    double m_nPercent;
    QLabel *statusLabel;
};

#endif // MAINWINDOW_H
