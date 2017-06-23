/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbrir_Automata;
    QAction *actionGuardar_Automata;
    QAction *actionSalir;
    QAction *actionTodas;
    QAction *actionEquivalentes;
    QAction *actionAcerca_de;
    QAction *actionAcerca_de_Qt;
    QWidget *centralWidget;
    QPushButton *playPushButton;
    QPushButton *pausePushButton;
    QPushButton *stopPushButton;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *lengthLabel;
    QLineEdit *lengthLineEdit;
    QLabel *ruleLabel;
    QLineEdit *ruleLineEdit;
    QLabel *timeLabel;
    QLineEdit *timeLineEdit;
    QGroupBox *initTapeGroupBox;
    QLabel *percentLabel;
    QLineEdit *percentLineEdit;
    QTableWidget *tapeTableWidget;
    QSlider *percentHorizontalSlider;
    QMenuBar *menuBar;
    QMenu *menu_Archivo;
    QMenu *menuEditar;
    QMenu *menuExplorar_reglas;
    QMenu *menuAyuda;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(680, 330);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        actionAbrir_Automata = new QAction(MainWindow);
        actionAbrir_Automata->setObjectName(QStringLiteral("actionAbrir_Automata"));
        actionGuardar_Automata = new QAction(MainWindow);
        actionGuardar_Automata->setObjectName(QStringLiteral("actionGuardar_Automata"));
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        actionTodas = new QAction(MainWindow);
        actionTodas->setObjectName(QStringLiteral("actionTodas"));
        actionEquivalentes = new QAction(MainWindow);
        actionEquivalentes->setObjectName(QStringLiteral("actionEquivalentes"));
        actionAcerca_de = new QAction(MainWindow);
        actionAcerca_de->setObjectName(QStringLiteral("actionAcerca_de"));
        actionAcerca_de_Qt = new QAction(MainWindow);
        actionAcerca_de_Qt->setObjectName(QStringLiteral("actionAcerca_de_Qt"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        playPushButton = new QPushButton(centralWidget);
        playPushButton->setObjectName(QStringLiteral("playPushButton"));
        playPushButton->setGeometry(QRect(390, 40, 32, 32));
        playPushButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        playPushButton->setIcon(icon);
        playPushButton->setIconSize(QSize(32, 32));
        playPushButton->setFlat(true);
        pausePushButton = new QPushButton(centralWidget);
        pausePushButton->setObjectName(QStringLiteral("pausePushButton"));
        pausePushButton->setEnabled(false);
        pausePushButton->setGeometry(QRect(470, 40, 32, 32));
        pausePushButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        pausePushButton->setIcon(icon1);
        pausePushButton->setIconSize(QSize(32, 32));
        pausePushButton->setFlat(true);
        stopPushButton = new QPushButton(centralWidget);
        stopPushButton->setObjectName(QStringLiteral("stopPushButton"));
        stopPushButton->setEnabled(false);
        stopPushButton->setGeometry(QRect(550, 40, 32, 32));
        stopPushButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        stopPushButton->setIcon(icon2);
        stopPushButton->setIconSize(QSize(32, 32));
        stopPushButton->setFlat(true);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 20, 231, 83));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout->setContentsMargins(0, 0, 0, 0);
        lengthLabel = new QLabel(layoutWidget);
        lengthLabel->setObjectName(QStringLiteral("lengthLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lengthLabel);

        lengthLineEdit = new QLineEdit(layoutWidget);
        lengthLineEdit->setObjectName(QStringLiteral("lengthLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lengthLineEdit->sizePolicy().hasHeightForWidth());
        lengthLineEdit->setSizePolicy(sizePolicy);
        lengthLineEdit->setMaximumSize(QSize(70, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, lengthLineEdit);

        ruleLabel = new QLabel(layoutWidget);
        ruleLabel->setObjectName(QStringLiteral("ruleLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, ruleLabel);

        ruleLineEdit = new QLineEdit(layoutWidget);
        ruleLineEdit->setObjectName(QStringLiteral("ruleLineEdit"));
        sizePolicy.setHeightForWidth(ruleLineEdit->sizePolicy().hasHeightForWidth());
        ruleLineEdit->setSizePolicy(sizePolicy);
        ruleLineEdit->setMaximumSize(QSize(70, 23));

        formLayout->setWidget(1, QFormLayout::FieldRole, ruleLineEdit);

        timeLabel = new QLabel(layoutWidget);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, timeLabel);

        timeLineEdit = new QLineEdit(layoutWidget);
        timeLineEdit->setObjectName(QStringLiteral("timeLineEdit"));
        sizePolicy.setHeightForWidth(timeLineEdit->sizePolicy().hasHeightForWidth());
        timeLineEdit->setSizePolicy(sizePolicy);
        timeLineEdit->setMaximumSize(QSize(70, 23));

        formLayout->setWidget(2, QFormLayout::FieldRole, timeLineEdit);

        initTapeGroupBox = new QGroupBox(centralWidget);
        initTapeGroupBox->setObjectName(QStringLiteral("initTapeGroupBox"));
        initTapeGroupBox->setGeometry(QRect(20, 120, 641, 149));
        percentLabel = new QLabel(initTapeGroupBox);
        percentLabel->setObjectName(QStringLiteral("percentLabel"));
        percentLabel->setGeometry(QRect(10, 30, 119, 27));
        percentLineEdit = new QLineEdit(initTapeGroupBox);
        percentLineEdit->setObjectName(QStringLiteral("percentLineEdit"));
        percentLineEdit->setGeometry(QRect(140, 30, 70, 27));
        sizePolicy.setHeightForWidth(percentLineEdit->sizePolicy().hasHeightForWidth());
        percentLineEdit->setSizePolicy(sizePolicy);
        percentLineEdit->setMaximumSize(QSize(70, 27));
        percentLineEdit->setMaxLength(10);
        tapeTableWidget = new QTableWidget(initTapeGroupBox);
        if (tapeTableWidget->rowCount() < 1)
            tapeTableWidget->setRowCount(1);
        tapeTableWidget->setObjectName(QStringLiteral("tapeTableWidget"));
        tapeTableWidget->setGeometry(QRect(10, 70, 621, 71));
        tapeTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tapeTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tapeTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tapeTableWidget->setRowCount(1);
        tapeTableWidget->horizontalHeader()->setDefaultSectionSize(45);
        tapeTableWidget->horizontalHeader()->setHighlightSections(false);
        tapeTableWidget->verticalHeader()->setVisible(false);
        percentHorizontalSlider = new QSlider(initTapeGroupBox);
        percentHorizontalSlider->setObjectName(QStringLiteral("percentHorizontalSlider"));
        percentHorizontalSlider->setGeometry(QRect(220, 30, 411, 27));
        percentHorizontalSlider->setMaximum(1000);
        percentHorizontalSlider->setSingleStep(10);
        percentHorizontalSlider->setPageStep(50);
        percentHorizontalSlider->setValue(500);
        percentHorizontalSlider->setTracking(false);
        percentHorizontalSlider->setOrientation(Qt::Horizontal);
        percentHorizontalSlider->setInvertedControls(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 680, 24));
        menu_Archivo = new QMenu(menuBar);
        menu_Archivo->setObjectName(QStringLiteral("menu_Archivo"));
        menuEditar = new QMenu(menuBar);
        menuEditar->setObjectName(QStringLiteral("menuEditar"));
        menuExplorar_reglas = new QMenu(menuEditar);
        menuExplorar_reglas->setObjectName(QStringLiteral("menuExplorar_reglas"));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QStringLiteral("menuAyuda"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_Archivo->menuAction());
        menuBar->addAction(menuEditar->menuAction());
        menuBar->addAction(menuAyuda->menuAction());
        menu_Archivo->addAction(actionAbrir_Automata);
        menu_Archivo->addAction(actionGuardar_Automata);
        menu_Archivo->addSeparator();
        menu_Archivo->addAction(actionSalir);
        menuEditar->addAction(menuExplorar_reglas->menuAction());
        menuExplorar_reglas->addAction(actionTodas);
        menuExplorar_reglas->addAction(actionEquivalentes);
        menuAyuda->addAction(actionAcerca_de);
        menuAyuda->addAction(actionAcerca_de_Qt);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Automata Celular 1D", 0));
        actionAbrir_Automata->setText(QApplication::translate("MainWindow", "Abrir Automata", 0));
        actionAbrir_Automata->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionGuardar_Automata->setText(QApplication::translate("MainWindow", "Guardar Automata", 0));
        actionGuardar_Automata->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", 0));
        actionSalir->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionTodas->setText(QApplication::translate("MainWindow", "Todas", 0));
        actionTodas->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0));
        actionEquivalentes->setText(QApplication::translate("MainWindow", "Equivalentes", 0));
        actionEquivalentes->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", 0));
        actionAcerca_de->setText(QApplication::translate("MainWindow", "Acerca de", 0));
        actionAcerca_de_Qt->setText(QApplication::translate("MainWindow", "Acerca de Qt", 0));
        playPushButton->setText(QString());
        pausePushButton->setText(QString());
        stopPushButton->setText(QString());
        lengthLabel->setText(QApplication::translate("MainWindow", "Longitud del Anillo", 0));
        lengthLineEdit->setText(QApplication::translate("MainWindow", "601", 0));
        ruleLabel->setText(QApplication::translate("MainWindow", "Regla", 0));
        ruleLineEdit->setText(QApplication::translate("MainWindow", "90", 0));
        timeLabel->setText(QApplication::translate("MainWindow", "Repeticiones", 0));
        timeLineEdit->setText(QApplication::translate("MainWindow", "1500", 0));
        initTapeGroupBox->setTitle(QApplication::translate("MainWindow", "Aut\303\263mata Inicial", 0));
        percentLabel->setText(QApplication::translate("MainWindow", "Porcentaje 1's:", 0));
        percentLineEdit->setText(QApplication::translate("MainWindow", "50", 0));
        menu_Archivo->setTitle(QApplication::translate("MainWindow", "&Archivo", 0));
        menuEditar->setTitle(QApplication::translate("MainWindow", "&Editar", 0));
        menuExplorar_reglas->setTitle(QApplication::translate("MainWindow", "Explorar reglas", 0));
        menuAyuda->setTitle(QApplication::translate("MainWindow", "Ayuda", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
