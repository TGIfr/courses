/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *CurTime_label;
    QPushButton *Add_pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_6;
    QListWidget *City_listWidget;
    QLabel *City_label;
    QLabel *label_5;
    QLabel *Lat_label;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *Lng_label;
    QLabel *label_8;
    QLabel *Sunrise_label;
    QLabel *label_9;
    QLabel *Sunset_label;
    QLabel *label_10;
    QLabel *UTCShift_label;
    QLabel *SunAvalaible_label;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *ZoneId_label;
    QLabel *ZoneName_label;
    QProgressBar *Sun_progressBar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(577, 385);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        CurTime_label = new QLabel(centralWidget);
        CurTime_label->setObjectName(QStringLiteral("CurTime_label"));
        CurTime_label->setGeometry(QRect(290, 300, 221, 17));
        Add_pushButton = new QPushButton(centralWidget);
        Add_pushButton->setObjectName(QStringLiteral("Add_pushButton"));
        Add_pushButton->setGeometry(QRect(20, 270, 221, 25));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(265, 0, 67, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 10, 67, 17));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(270, 210, 41, 17));
        City_listWidget = new QListWidget(centralWidget);
        City_listWidget->setObjectName(QStringLiteral("City_listWidget"));
        City_listWidget->setGeometry(QRect(20, 30, 221, 231));
        City_listWidget->setFocusPolicy(Qt::WheelFocus);
        City_label = new QLabel(centralWidget);
        City_label->setObjectName(QStringLiteral("City_label"));
        City_label->setGeometry(QRect(320, 170, 67, 17));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(270, 190, 31, 17));
        Lat_label = new QLabel(centralWidget);
        Lat_label->setObjectName(QStringLiteral("Lat_label"));
        Lat_label->setGeometry(QRect(310, 190, 67, 17));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(270, 170, 51, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(260, 100, 151, 17));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(190, 300, 91, 17));
        Lng_label = new QLabel(centralWidget);
        Lng_label->setObjectName(QStringLiteral("Lng_label"));
        Lng_label->setGeometry(QRect(320, 210, 67, 17));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(260, 230, 67, 17));
        Sunrise_label = new QLabel(centralWidget);
        Sunrise_label->setObjectName(QStringLiteral("Sunrise_label"));
        Sunrise_label->setGeometry(QRect(340, 230, 131, 17));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(260, 250, 67, 17));
        Sunset_label = new QLabel(centralWidget);
        Sunset_label->setObjectName(QStringLiteral("Sunset_label"));
        Sunset_label->setGeometry(QRect(340, 250, 111, 17));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(260, 270, 67, 17));
        UTCShift_label = new QLabel(centralWidget);
        UTCShift_label->setObjectName(QStringLiteral("UTCShift_label"));
        UTCShift_label->setGeometry(QRect(340, 270, 101, 17));
        SunAvalaible_label = new QLabel(centralWidget);
        SunAvalaible_label->setObjectName(QStringLiteral("SunAvalaible_label"));
        SunAvalaible_label->setEnabled(true);
        SunAvalaible_label->setGeometry(QRect(260, 50, 201, 17));
        QFont font;
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        font.setStrikeOut(false);
        SunAvalaible_label->setFont(font);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(270, 130, 91, 17));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(270, 150, 121, 17));
        ZoneId_label = new QLabel(centralWidget);
        ZoneId_label->setObjectName(QStringLiteral("ZoneId_label"));
        ZoneId_label->setGeometry(QRect(370, 130, 151, 17));
        ZoneName_label = new QLabel(centralWidget);
        ZoneName_label->setObjectName(QStringLiteral("ZoneName_label"));
        ZoneName_label->setGeometry(QRect(390, 150, 181, 17));
        Sun_progressBar = new QProgressBar(centralWidget);
        Sun_progressBar->setObjectName(QStringLiteral("Sun_progressBar"));
        Sun_progressBar->setGeometry(QRect(260, 20, 271, 23));
        Sun_progressBar->setValue(0);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 577, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        CurTime_label->setText(QApplication::translate("MainWindow", "friend", Q_NULLPTR));
        Add_pushButton->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Position:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Cities:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Lng:", Q_NULLPTR));
        City_label->setText(QApplication::translate("MainWindow", "name", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Lat:", Q_NULLPTR));
        Lat_label->setText(QApplication::translate("MainWindow", "age", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "CIty:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Selected object data:", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "CurrentTIme:", Q_NULLPTR));
        Lng_label->setText(QApplication::translate("MainWindow", "mass", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Sunrise:", Q_NULLPTR));
        Sunrise_label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Sunset:", Q_NULLPTR));
        Sunset_label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "UTCShift:", Q_NULLPTR));
        UTCShift_label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        SunAvalaible_label->setText(QApplication::translate("MainWindow", "SUN TEMPORARY OFFLINE", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Time Zone Id:", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Time Zone Name:", Q_NULLPTR));
        ZoneId_label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        ZoneName_label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
