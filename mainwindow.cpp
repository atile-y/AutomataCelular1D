#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QIntValidator *v = new QIntValidator(1, 10000, this);
    ui->lengthLineEdit->setValidator(v);

    v = new QIntValidator(0, 255, this);
    ui->ruleLineEdit->setValidator(v);

    v = new QIntValidator(this);
    v->setBottom(0);
    ui->timeLineEdit->setValidator(v);

    v = new QIntValidator(0, 100, this);
    ui->percentLineEdit->setValidator(v);

    protoItem = new QTableWidgetItem(tr("0"));
    protoItem->setTextAlignment(Qt::AlignCenter);

    automata = new Automata(this);
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(automata);
    ui->evolutionGroupBox->setLayout(vbox);

    frecuencia = new Frecuencia(this);
    vbox = new QVBoxLayout;
    vbox->addWidget(frecuencia);
    ui->frequencyGroupBox->setLayout(vbox);

    on_lengthLineEdit_editingFinished();
    on_ruleLineEdit_editingFinished();
    on_timeLineEdit_editingFinished();

    bool t[automata->getSize()];
    for(bool &i : t)
        i = false;
    automata->setTape(t);

    connect(automata, SIGNAL(endEvolve(QVector<int>)),
            frecuencia, SLOT(setData(QVector<int>)));
}

MainWindow::~MainWindow(){
    delete ui;
    delete automata;
    delete frecuencia;
}

void MainWindow::on_lengthLineEdit_editingFinished(){
    int pos = 0;
    QString str = ui->lengthLineEdit->text();
    QIntValidator *v = (QIntValidator*)ui->lengthLineEdit->validator();

    if( v->validate(str, pos) != QValidator::Acceptable ){
        ui->lengthLineEdit->setText(QString::number(automata->getSize()));
        return;
    }

    cout << "str.toInt() : " << str.toInt() << endl;
    automata->setSize(str.toInt());
    cout << "automata->getSize() : " << automata->getSize() << endl;
    frecuencia->setMaxOnes(automata->getSize());
    dist = std::uniform_int_distribution<int>(0, automata->getSize()-1);

    int oldSize = ui->tapeTableWidget->columnCount();
    ui->tapeTableWidget->setColumnCount(automata->getSize());

    for(int i=oldSize;i<automata->getSize();i++)
        ui->tapeTableWidget->setItem(0, i, protoItem->clone());
}

void MainWindow::on_ruleLineEdit_editingFinished(){
    int pos = 0;
    QString str = ui->ruleLineEdit->text();
    QIntValidator *v = (QIntValidator*)ui->ruleLineEdit->validator();

    if( v->validate(str, pos) != QValidator::Acceptable ){
        ui->ruleLineEdit->setText(QString::number(automata->getRule()));
        return;
    }

    automata->setRule(str.toInt());
}

void MainWindow::on_timeLineEdit_editingFinished(){
    int pos = 0;
    QString str = ui->timeLineEdit->text();
    QIntValidator *v = (QIntValidator*)ui->timeLineEdit->validator();

    if( v->validate(str, pos) != QValidator::Acceptable ){
        ui->timeLineEdit->setText(QString::number(automata->getTime()));
        return;
    }

    automata->setTime(str.toInt());
}

void MainWindow::on_randomPushButton_clicked(){
    int size = automata->getSize();
    for(int i=0;i<size;i++)
        ui->tapeTableWidget->item(0, i)->setText(tr("0"));

    int percent = ui->percentLineEdit->text().toInt();
    int numOnes = percent * size / 100;
    int j;
    for(int i=0;i<numOnes;i++){
        do j = dist(generator);
        while( ui->tapeTableWidget->item(0, j)->text() == "1" );
        ui->tapeTableWidget->item(0, j)->setText(tr("1"));
    }
}

void MainWindow::on_runPushButton_clicked(){
    bool tape[automata->getSize()];
    for(int i=0;i<automata->getSize();i++)
        tape[i] = ui->tapeTableWidget->item(0, i)->text() == "1";
    automata->setTape(tape);
}
