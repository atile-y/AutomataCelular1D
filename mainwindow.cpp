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

    automata = new Automata(this);
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(automata);
    ui->evolutionGroupBox->setLayout(vbox);

    protoItem = new QTableWidgetItem(tr("0"));
    protoItem->setTextAlignment(Qt::AlignCenter);

    dist = std::uniform_int_distribution<int>(0, automata->getSize()-1);
    setTape();

    connect(ui->tapeTableWidget, SIGNAL(cellChanged(int,int)),
            this, SLOT(cell_changed(int,int)));
}

MainWindow::~MainWindow(){
    delete ui;
    delete automata;
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
    dist = std::uniform_int_distribution<int>(0, automata->getSize()-1);
    setTape();
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

    automata->setTime(str.toLongLong());
}

void MainWindow::on_percentLineEdit_editingFinished(){
    int pos = 0;
    QString str = ui->percentLineEdit->text();
    QIntValidator *v = (QIntValidator*)ui->percentLineEdit->validator();

    if( v->validate(str, pos) != QValidator::Acceptable ){
        ui->percentLineEdit->setText(QString::number(automata->getRule()));
        return;
    }

    automata->setPercentOnes(str.toInt());
}

void MainWindow::setTape(){
    disconnect(ui->tapeTableWidget, SIGNAL(cellChanged(int,int)),
            this, SLOT(cell_changed(int,int)));

    int oldSize = ui->tapeTableWidget->columnCount();
    bool tape[automata->getSize()];

    ui->tapeTableWidget->setColumnCount(automata->getSize());
    ui->tapeTableWidget->updateGeometry();

    for(int i=0;i<oldSize && i<automata->getSize();i++)
        tape[i] = ui->tapeTableWidget->item(0, i)->text() == "1";

    for(int i=oldSize;i<automata->getSize();i++){
        ui->tapeTableWidget->setItem(0, i, protoItem->clone());
        tape[i] = false;
    }
    connect(ui->tapeTableWidget, SIGNAL(cellChanged(int,int)),
            this, SLOT(cell_changed(int,int)));

    automata->setTape(tape);
}

void MainWindow::on_randomPushButton_clicked(){
    int size = automata->getSize();
    for(int i=0;i<size;i++)
        ui->tapeTableWidget->item(0, i)->setText(tr("0"));

    int numOnes = automata->getPercentOnes() * size / 100;
    int j;
    for(int i=0;i<numOnes;i++){
        do j = dist(generator);
        while( ui->tapeTableWidget->item(0, j)->text() == "1" );
        ui->tapeTableWidget->item(0, j)->setText(tr("1"));
    }

    bool tape[automata->getSize()];
    for(int i=0;i<automata->getSize();i++)
        tape[i] = ui->tapeTableWidget->item(0, i)->text() == "1";
    automata->setTape(tape);
}

void MainWindow::cell_changed(int row, int col){
    if( row != 0 || ui->tapeTableWidget->item(row, col) == NULL )
        return;

    automata->setCell(col, ui->tapeTableWidget->item(0, col)->text() == "1");

    bool tape[automata->getSize()];
    for(int i=0;i<automata->getSize();i++)
        tape[i] = ui->tapeTableWidget->item(row, i)->text() == "1";
    automata->setTape(tape);
}
