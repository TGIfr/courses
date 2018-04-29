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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *FindByMass_pushButton;
    QDoubleSpinBox *Mass_doubleSpinBox;
    QLabel *label;
    QListWidget *Dino_listWidget;
    QTextBrowser *Result_textBrowser;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *Name_label;
    QLabel *Age_label;
    QLabel *Mass_label;
    QLabel *Friend_label;
    QFrame *frame_2;
    QPushButton *editPushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(503, 385);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        FindByMass_pushButton = new QPushButton(centralWidget);
        FindByMass_pushButton->setObjectName(QStringLiteral("FindByMass_pushButton"));
        FindByMass_pushButton->setGeometry(QRect(270, 10, 101, 25));
        Mass_doubleSpinBox = new QDoubleSpinBox(centralWidget);
        Mass_doubleSpinBox->setObjectName(QStringLiteral("Mass_doubleSpinBox"));
        Mass_doubleSpinBox->setGeometry(QRect(380, 10, 101, 26));
        Mass_doubleSpinBox->setValue(10);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(270, 50, 67, 17));
        Dino_listWidget = new QListWidget(centralWidget);
        Dino_listWidget->setObjectName(QStringLiteral("Dino_listWidget"));
        Dino_listWidget->setGeometry(QRect(10, 30, 221, 231));
        Dino_listWidget->setFocusPolicy(Qt::WheelFocus);
        Result_textBrowser = new QTextBrowser(centralWidget);
        Result_textBrowser->setObjectName(QStringLiteral("Result_textBrowser"));
        Result_textBrowser->setGeometry(QRect(265, 70, 231, 91));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 67, 17));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 270, 101, 25));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 270, 111, 25));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(270, 180, 151, 17));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(280, 200, 51, 17));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(290, 230, 31, 17));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(280, 260, 41, 17));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(270, 280, 67, 17));
        Name_label = new QLabel(centralWidget);
        Name_label->setObjectName(QStringLiteral("Name_label"));
        Name_label->setGeometry(QRect(330, 200, 67, 17));
        Age_label = new QLabel(centralWidget);
        Age_label->setObjectName(QStringLiteral("Age_label"));
        Age_label->setGeometry(QRect(330, 230, 67, 17));
        Mass_label = new QLabel(centralWidget);
        Mass_label->setObjectName(QStringLiteral("Mass_label"));
        Mass_label->setGeometry(QRect(330, 260, 67, 17));
        Friend_label = new QLabel(centralWidget);
        Friend_label->setObjectName(QStringLiteral("Friend_label"));
        Friend_label->setGeometry(QRect(330, 280, 67, 17));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(260, 170, 161, 141));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        editPushButton = new QPushButton(centralWidget);
        editPushButton->setObjectName(QStringLiteral("editPushButton"));
        editPushButton->setGeometry(QRect(10, 300, 221, 25));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 503, 22));
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
        FindByMass_pushButton->setText(QApplication::translate("MainWindow", "Find by Mass", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Results:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Dinos:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Delete", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Selected object data:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Name:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Age:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Mass:", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Friend:", Q_NULLPTR));
        Name_label->setText(QApplication::translate("MainWindow", "name", Q_NULLPTR));
        Age_label->setText(QApplication::translate("MainWindow", "age", Q_NULLPTR));
        Mass_label->setText(QApplication::translate("MainWindow", "mass", Q_NULLPTR));
        Friend_label->setText(QApplication::translate("MainWindow", "friend", Q_NULLPTR));
        editPushButton->setText(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
