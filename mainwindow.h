#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "automata.h"
#include "frecuencia.h"

#include <QMainWindow>
#include <QLineEdit>
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
    void resizeEvent(QResizeEvent*);

private slots:
    void on_lengthLineEdit_editingFinished();
    void on_ruleLineEdit_editingFinished();
    void on_timeLineEdit_editingFinished();
    void on_randomPushButton_clicked();

private:
    Ui::MainWindow *ui;
    Automata *automata;
    Frecuencia *frecuencia;
    QTableWidgetItem *protoItem;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> dist;
};

#endif // MAINWINDOW_H
