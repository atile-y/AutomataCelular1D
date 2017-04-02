#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCloseEvent>
#include <QDebug>
#include <QFileDialog>

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
    connect(automata, SIGNAL(endTime()), this, SLOT(takeScreenshot()));

    connect(ui->actionSalir, SIGNAL(triggered(bool)), this, SLOT(close()));

    setFixedSize(geometry().width(), geometry().height());
    move(197, 25);

    statusLabel = new QLabel(tr(""), this);
    ui->statusBar->addWidget(statusLabel);
    ui->statusBar->setSizeGripEnabled(false);
}

MainWindow::~MainWindow(){
    delete ui;
    delete automata;
    delete frecuencia;
}

void MainWindow::closeEvent(QCloseEvent *event){
    automata->close();
    frecuencia->close();
    event->accept();
}

void MainWindow::on_actionAbrir_Automata_triggered(){
    QString file = QFileDialog::getOpenFileName(this,
            tr("Abrir la Cinta Inicial del Automata"),
            "/home/atile/Documentos/Materias/Sistemas Complejos",
            tr("Automata (*.eca)"));

    if( file == "" )
        return;

    if( !file.endsWith(".eca") )
        file += ".eca";

    if( !automata->readTape(file) )
        return;

    ui->lengthLineEdit->setText(QString::number(automata->getSize()));
    ui->ruleLineEdit->setText(QString::number(automata->getRule()));
    ui->timeLineEdit->setText(QString::number(automata->getTime()));

    frecuencia->setMaxOnes(automata->getSize());
    frecuencia->setTime(automata->getTime());
    frecuencia->reset();

    uint size = automata->getSize();
    bool *t = automata->getInitTape();

    int oldSize = ui->tapeTableWidget->columnCount();
    ui->tapeTableWidget->setColumnCount(size);
    for(uint i=oldSize;i<size;i++)
        ui->tapeTableWidget->setItem(0, i, protoItem->clone());

    for(uint i=0;i<size;i++)
        ui->tapeTableWidget->item(0, i)->setText(tr(t[i]?"1":"0"));
}

void MainWindow::on_actionGuardar_Automata_triggered(){
    QString file = QFileDialog::getSaveFileName(this,
            tr("Guardar Cinta Inicial del Automata"),
            "/home/atile/Documentos/Materias/Sistemas Complejos",
            tr("Automata (*.eca)"));
    if( file == "" )
        return;

    if( !file.endsWith(".eca") )
        file += ".eca";

    bool t[automata->getSize()];
    for(uint i=0;i<automata->getSize();i++)
        t[i] = (ui->tapeTableWidget->item(0, i)->text() == "1");
    automata->setTape(t);
    automata->saveTape(file);
}

void MainWindow::on_actionTodas_triggered(){
    if( automata->getState() != STOP )
        return;

    QString folder = QFileDialog::getExistingDirectory(this,
            tr("Explorar todas las reglas"),
            "/home/atile/Documentos/Materias/Sistemas Complejos");
    if( folder == "" )
        return;

    m_Thread = new QThread;
    m_UniScan = new UniverseScanner(automata->getSize(), folder);
    m_UniScan->moveToThread(m_Thread);

    connect(this, SIGNAL(startScan(int)), m_UniScan, SLOT(scan(int)));
    connect(m_UniScan, SIGNAL(startRule(int)), this, SLOT(statusRunningRule(int)));
    connect(m_UniScan, SIGNAL(endScanning()), this, SLOT(finishScan()));

    m_Thread->start();

    // Bloqueando los elementos para que no se editen
    ui->menuBar->setEnabled(false);
    ui->playPushButton->setEnabled(false);
    ui->lengthLineEdit->setEnabled(false);
    ui->ruleLineEdit->setEnabled(false);
    ui->timeLineEdit->setEnabled(false);
    ui->initTapeGroupBox->setEnabled(false);

    emit startScan(TODAS);
}

void MainWindow::on_actionEquivalentes_triggered(){
    if( automata->getState() != STOP )
        return;

    QString folder = QFileDialog::getExistingDirectory(this,
            tr("Explorar las reglas equivalentes"),
            "/home/atile/Documentos/Materias/Sistemas Complejos");
    if( folder == "" )
        return;

    m_Thread = new QThread;
    m_UniScan = new UniverseScanner(automata->getSize(), folder);
    m_UniScan->moveToThread(m_Thread);

    connect(this, SIGNAL(startScan(int)), m_UniScan, SLOT(scan(int)));
    connect(m_UniScan, SIGNAL(startRule(int)), this, SLOT(statusRunningRule(int)));
    connect(m_UniScan, SIGNAL(endScanning()), this, SLOT(finishScan()));

    m_Thread->start();

    // Bloqueando los elementos para que no se editen
    ui->menuBar->setEnabled(false);
    ui->playPushButton->setEnabled(false);
    ui->lengthLineEdit->setEnabled(false);
    ui->ruleLineEdit->setEnabled(false);
    ui->timeLineEdit->setEnabled(false);
    ui->initTapeGroupBox->setEnabled(false);

    emit startScan(EQUIVALENTES);
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

    ui->menuBar->setEnabled(false);
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

    ui->menuBar->setEnabled(true);
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
}

void MainWindow::takeScreenshot(QString filename){
    if( automata->isVisible() )
        automata->grab().save(filename + ".png");


    if( frecuencia->isVisible() )
        frecuencia->grab().save(filename + "_freq.png");
}

void MainWindow::statusRunningRule(int r){
    statusLabel->setText(QString("Corriendo Regla %1 ...").arg(r));
}

void MainWindow::finishScan(){
    // Desbloqueando los elementos para que se puedan editar
    ui->menuBar->setEnabled(true);
    ui->playPushButton->setEnabled(true);
    ui->lengthLineEdit->setEnabled(true);
    ui->ruleLineEdit->setEnabled(true);
    ui->timeLineEdit->setEnabled(true);
    ui->initTapeGroupBox->setEnabled(true);

    statusLabel->setText(tr("Listo."));
}
