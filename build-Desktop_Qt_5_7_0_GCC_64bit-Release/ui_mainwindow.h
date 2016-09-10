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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Open_file;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *lengthLabel;
    QLineEdit *lengthLineEdit;
    QLabel *ruleLabel;
    QLineEdit *ruleLineEdit;
    QLabel *timeLabel;
    QLineEdit *timeLineEdit;
    QGroupBox *initTapeGroupBox;
    QPushButton *randomPushButton;
    QLabel *percentLabel;
    QLineEdit *percentLineEdit;
    QTableWidget *tapeTableWidget;
    QGroupBox *evolutionGroupBox;
    QGroupBox *frequencyGroupBox;
    QWidget *frequencyWidget;
    QPushButton *runPushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        action_Open_file = new QAction(MainWindow);
        action_Open_file->setObjectName(QStringLiteral("action_Open_file"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(21, 40, 262, 83));
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
        initTapeGroupBox->setGeometry(QRect(299, 11, 479, 149));
        randomPushButton = new QPushButton(initTapeGroupBox);
        randomPushButton->setObjectName(QStringLiteral("randomPushButton"));
        randomPushButton->setGeometry(QRect(10, 30, 80, 27));
        percentLabel = new QLabel(initTapeGroupBox);
        percentLabel->setObjectName(QStringLiteral("percentLabel"));
        percentLabel->setGeometry(QRect(140, 30, 119, 27));
        percentLineEdit = new QLineEdit(initTapeGroupBox);
        percentLineEdit->setObjectName(QStringLiteral("percentLineEdit"));
        percentLineEdit->setGeometry(QRect(270, 30, 70, 27));
        sizePolicy.setHeightForWidth(percentLineEdit->sizePolicy().hasHeightForWidth());
        percentLineEdit->setSizePolicy(sizePolicy);
        percentLineEdit->setMaximumSize(QSize(70, 27));
        tapeTableWidget = new QTableWidget(initTapeGroupBox);
        if (tapeTableWidget->rowCount() < 1)
            tapeTableWidget->setRowCount(1);
        tapeTableWidget->setObjectName(QStringLiteral("tapeTableWidget"));
        tapeTableWidget->setGeometry(QRect(10, 70, 461, 71));
        tapeTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tapeTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tapeTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tapeTableWidget->setRowCount(1);
        tapeTableWidget->horizontalHeader()->setDefaultSectionSize(45);
        tapeTableWidget->horizontalHeader()->setHighlightSections(false);
        tapeTableWidget->verticalHeader()->setVisible(false);
        evolutionGroupBox = new QGroupBox(centralWidget);
        evolutionGroupBox->setObjectName(QStringLiteral("evolutionGroupBox"));
        evolutionGroupBox->setGeometry(QRect(21, 190, 371, 389));
        frequencyGroupBox = new QGroupBox(centralWidget);
        frequencyGroupBox->setObjectName(QStringLiteral("frequencyGroupBox"));
        frequencyGroupBox->setGeometry(QRect(408, 190, 370, 389));
        frequencyWidget = new QWidget(frequencyGroupBox);
        frequencyWidget->setObjectName(QStringLiteral("frequencyWidget"));
        frequencyWidget->setGeometry(QRect(10, 30, 351, 351));
        runPushButton = new QPushButton(centralWidget);
        runPushButton->setObjectName(QStringLiteral("runPushButton"));
        runPushButton->setGeometry(QRect(120, 140, 80, 27));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Automata Celular 1D", 0));
        action_Open_file->setText(QApplication::translate("MainWindow", "Abrir archivo", 0));
        action_Open_file->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        lengthLabel->setText(QApplication::translate("MainWindow", "Longitud del Aut\303\263mata", 0));
        lengthLineEdit->setText(QApplication::translate("MainWindow", "300", 0));
        ruleLabel->setText(QApplication::translate("MainWindow", "Regla", 0));
        ruleLineEdit->setText(QApplication::translate("MainWindow", "90", 0));
        timeLabel->setText(QApplication::translate("MainWindow", "Repeticiones", 0));
        timeLineEdit->setText(QApplication::translate("MainWindow", "300", 0));
        initTapeGroupBox->setTitle(QApplication::translate("MainWindow", "Aut\303\263mata Inicial", 0));
        randomPushButton->setText(QApplication::translate("MainWindow", "Random", 0));
        percentLabel->setText(QApplication::translate("MainWindow", "Porcentaje 1's:", 0));
        percentLineEdit->setText(QApplication::translate("MainWindow", "50", 0));
        evolutionGroupBox->setTitle(QApplication::translate("MainWindow", "Evoluci\303\263n del Aut\303\263mata", 0));
        frequencyGroupBox->setTitle(QApplication::translate("MainWindow", "Diagrama de Frecuencia", 0));
        runPushButton->setText(QApplication::translate("MainWindow", "Run", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
