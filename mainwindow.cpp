#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QIntValidator *v = new QIntValidator(1, 762, this);
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
    on_lengthLineEdit_editingFinished();
    on_ruleLineEdit_editingFinished();
    on_timeLineEdit_editingFinished();

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(automata, 0, Qt::AlignCenter);
    ui->evolutionGroupBox->setLayout(vbox);

    frecuencia = new Frecuencia(this);
    vbox = new QVBoxLayout;
    vbox->addWidget(frecuencia, 0, Qt::AlignCenter);
    ui->frequencyGroupBox->setLayout(vbox);

    connect(ui->stopPushButton, SIGNAL(clicked()), automata, SLOT(reset()));
    connect(ui->stopPushButton, SIGNAL(clicked()), frecuencia, SLOT(reset()));
    connect(ui->playPushButton, SIGNAL(clicked()), automata, SLOT(play()));
    connect(ui->pausePushButton, SIGNAL(clicked()), automata, SLOT(pause()));
    connect(automata, SIGNAL(newStep(int)), frecuencia, SLOT(addFrequency(int)));
}

MainWindow::~MainWindow(){
    delete ui;
    delete automata;
}

void MainWindow::resizeEvent(QResizeEvent *){
    ui->evolutionGroupBox->resize((width()-60)/2+1, height()-209);

    ui->frequencyGroupBox->resize((width()-60)/2+1, height()-209);
    ui->frequencyGroupBox->move(width()/2+10, 170);

    int size;
    if( ui->evolutionGroupBox->width() + 20 < ui->evolutionGroupBox->height() )
        size = ui->evolutionGroupBox->width() - 20;
    else
        size = ui->evolutionGroupBox->height() - 40;
    automata->setFixedSize(size, size);
    frecuencia->setFixedSize(size, size);
}

void MainWindow::on_lengthLineEdit_editingFinished(){
    int pos = 0;
    QString str = ui->lengthLineEdit->text();
    QIntValidator *v = (QIntValidator*)ui->lengthLineEdit->validator();

    if( v->validate(str, pos) != QValidator::Acceptable ){
        ui->lengthLineEdit->setText(QString::number(automata->getSize()));
        return;
    }

    automata->setSize(str.toInt());
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
    frecuencia->reset();
}

void MainWindow::on_timeLineEdit_editingFinished(){
    int pos = 0;
    QString str = ui->timeLineEdit->text();
    QIntValidator *v = (QIntValidator*)ui->timeLineEdit->validator();

    if( v->validate(str, pos) != QValidator::Acceptable ){
        ui->timeLineEdit->setText(QString::number(automata->getTime()));
        return;
    }

    automata->setTime(str.toLongLong());
    frecuencia->setTime(automata->getTime());
}

void MainWindow::on_randomPushButton_clicked(){
    int size = automata->getSize();
    bool tape[size];

    for(int i=0;i<size;i++){
        ui->tapeTableWidget->item(0, i)->setText(tr("0"));
        tape[i] = false;
    }

    int percent = ui->percentLineEdit->text().toInt();
    int numOnes = percent * size / 100;
    int j;
    for(int i=0;i<numOnes;i++){
        do j = dist(generator);
        while( ui->tapeTableWidget->item(0, j)->text() == "1" );
        ui->tapeTableWidget->item(0, j)->setText(tr("1"));
        tape[j] = true;
    }

    automata->setTape(tape);
    frecuencia->reset();
}
