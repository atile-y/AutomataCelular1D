#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCloseEvent>
#include <QDebug>

#include <chrono>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    generator = std::default_random_engine(seed);

    m_nPercent = ui->percentHorizontalSlider->value()/10.0;
    ui->percentLineEdit->setText(QString::number(m_nPercent));

    ui->tapeTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    protoItem = new QTableWidgetItem(tr("0"));
    protoItem->setTextAlignment(Qt::AlignCenter);

    automata = new Automata();
    frecuencia = new Frecuencia();

    on_lengthLineEdit_editingFinished();
    on_ruleLineEdit_editingFinished();
    on_timeLineEdit_editingFinished();

    connect(automata, SIGNAL(newStep(uint)), frecuencia, SLOT(addFrequency(uint)));
    connect(automata, SIGNAL(endTime()), this, SLOT(on_pausePushButton_clicked()));

    setFixedSize(geometry().width(), geometry().height());
    move(197, 25);

    statusLabel = new QLabel(tr(""), this);
    ui->statusBar->addWidget(statusLabel);
    ui->statusBar->setSizeGripEnabled(false);
}

MainWindow::~MainWindow(){
    qInfo() << "MainWindow Descructor begin";
    delete ui;
    delete automata;
    delete frecuencia;
    qInfo() << "MainWindow Descructor end";
}

void MainWindow::closeEvent(QCloseEvent *event){
    automata->close();
    frecuencia->close();
    event->accept();
}

void MainWindow::on_lengthLineEdit_editingFinished(){
    int pos = 0;
    QString str = ui->lengthLineEdit->text();
    QIntValidator *v = new QIntValidator(this);
    v->setBottom(2);

    if( v->validate(str, pos) != QValidator::Acceptable ){
        ui->lengthLineEdit->setText(QString::number(automata->getSize()));
        return;
    }
    if( automata->getSize() == str.toUInt() )
        return;

    automata->setSize(str.toUInt());
    frecuencia->setMaxOnes(automata->getSize());
    dist = std::uniform_int_distribution<int>(0, automata->getSize()-1);

    int oldSize = ui->tapeTableWidget->columnCount();
    ui->tapeTableWidget->setColumnCount(automata->getSize());
    for(uint i=oldSize;i<automata->getSize();i++)
        ui->tapeTableWidget->setItem(0, i, protoItem->clone());

    initTape();
}

void MainWindow::on_ruleLineEdit_editingFinished(){
    int pos = 0;
    QString str = ui->ruleLineEdit->text();
    QIntValidator *v = new QIntValidator(0, 255, this);

    if( v->validate(str, pos) != QValidator::Acceptable ){
        ui->ruleLineEdit->setText(QString::number(automata->getRule()));
        return;
    }
    if( automata->getRule() == str.toInt() )
        return;

    automata->setRule(str.toInt());
    frecuencia->reset();
}

void MainWindow::on_timeLineEdit_editingFinished(){
    int pos = 0;
    QString str = ui->timeLineEdit->text();
    QIntValidator *v = new QIntValidator(this);
    v->setBottom(0);

    if( v->validate(str, pos) != QValidator::Acceptable ){
        ui->timeLineEdit->setText(QString::number(automata->getTime()));
        return;
    }
    if( automata->getTime() == str.toUInt() )
        return;

    automata->setTime(str.toLongLong());
    frecuencia->setTime(automata->getTime());
}

void MainWindow::on_playPushButton_clicked(){
    if( automata->getState() == STOP ){
        bool t[automata->getSize()];
        uint f = 0;
        for(uint i=0;i<automata->getSize();i++){
            t[i] = (ui->tapeTableWidget->item(0, i)->text() == "1");
            if( t[i] ) f++;
        }
        automata->setTape(t);
        frecuencia->reset();
        frecuencia->addFrequency(f);
    }

    automata->play();
    automata->show();
    frecuencia->show();

    statusLabel->setText(tr("Corriendo"));

    ui->playPushButton->setEnabled(false);
    ui->pausePushButton->setEnabled(true);
    ui->stopPushButton->setEnabled(true);
    ui->lengthLineEdit->setEnabled(false);
    ui->ruleLineEdit->setEnabled(false);
    ui->timeLineEdit->setEnabled(false);
    ui->percentLineEdit->setEnabled(false);
    ui->percentHorizontalSlider->setEnabled(false);
    for(uint i=0;i<automata->getSize();i++){
        QTableWidgetItem *item = ui->tapeTableWidget->item(0, i);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
    }
}

void MainWindow::on_pausePushButton_clicked(){
    automata->pause();

    statusLabel->setText(tr("Pausado"));

    ui->playPushButton->setEnabled(true);
    ui->pausePushButton->setEnabled(false);
}

void MainWindow::on_stopPushButton_clicked(){
    automata->reset();
    frecuencia->reset();
    automata->hide();
    frecuencia->hide();

    statusLabel->setText(tr(""));
    ui->statusBar->showMessage(tr("Detenido"), 2000);

    ui->playPushButton->setEnabled(true);
    ui->pausePushButton->setEnabled(false);
    ui->stopPushButton->setEnabled(false);
    ui->lengthLineEdit->setEnabled(true);
    ui->ruleLineEdit->setEnabled(true);
    ui->timeLineEdit->setEnabled(true);
    ui->percentLineEdit->setEnabled(true);
    ui->percentHorizontalSlider->setEnabled(true);
    for(uint i=0;i<automata->getSize();i++){
        QTableWidgetItem *item = ui->tapeTableWidget->item(0, i);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    }
}

void MainWindow::on_percentLineEdit_editingFinished(){
    int pos = 0;
    QString str = ui->percentLineEdit->text();
    QDoubleValidator *v = new QDoubleValidator(0.0, 100.0, 6, this);

    if( v->validate(str, pos) != QValidator::Acceptable ){
        ui->percentLineEdit->setText(QString::number(m_nPercent));
        return;
    }
    if( m_nPercent == str.toDouble() )
        return;

    m_nPercent = str.toDouble();
    bool s = ui->percentHorizontalSlider->blockSignals(true);
    ui->percentHorizontalSlider->setValue((int)(m_nPercent*10 + 0.5));
    ui->percentHorizontalSlider->blockSignals(s);

    initTape();
}

void MainWindow::on_percentHorizontalSlider_valueChanged(int value)
{
    m_nPercent = value/10.0;
    ui->percentLineEdit->setText(QString::number(m_nPercent));

    initTape();
}

void MainWindow::initTape(){
    dist.reset();

    uint size = automata->getSize();
    for(uint i=0;i<size;i++)
        ui->tapeTableWidget->item(0, i)->setText(tr("0"));

    double numOnes = m_nPercent * size / 100.0;
    uint m = (uint)numOnes, j;
    std::uniform_real_distribution<double> d(0.0, 1.0);
    double p = d(generator);

    if( p < numOnes - m )
        m++;

    for(uint i=0;i<m;i++){
        do j = dist(generator);
        while( ui->tapeTableWidget->item(0, j)->text() == "1" );
        ui->tapeTableWidget->item(0, j)->setText(tr("1"));
    }

    frecuencia->addFrequency(m);
}
