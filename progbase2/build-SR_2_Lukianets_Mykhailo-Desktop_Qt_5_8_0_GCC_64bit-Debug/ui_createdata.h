/********************************************************************************
** Form generated from reading UI file 'createdata.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEDATA_H
#define UI_CREATEDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_CreateData
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *FatName_lineEdit;
    QLineEdit *MotName_lineEdit_2;
    QSpinBox *FatAge_spinBox;
    QSpinBox *MotAge_spinBox_2;

    void setupUi(QDialog *CreateData)
    {
        if (CreateData->objectName().isEmpty())
            CreateData->setObjectName(QStringLiteral("CreateData"));
        CreateData->resize(400, 300);
        buttonBox = new QDialogButtonBox(CreateData);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(CreateData);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 40, 67, 17));
        label_2 = new QLabel(CreateData);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 60, 67, 17));
        label_3 = new QLabel(CreateData);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 100, 67, 17));
        label_4 = new QLabel(CreateData);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 140, 67, 17));
        label_5 = new QLabel(CreateData);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(80, 210, 67, 17));
        label_6 = new QLabel(CreateData);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(70, 170, 67, 17));
        FatName_lineEdit = new QLineEdit(CreateData);
        FatName_lineEdit->setObjectName(QStringLiteral("FatName_lineEdit"));
        FatName_lineEdit->setGeometry(QRect(160, 60, 113, 25));
        MotName_lineEdit_2 = new QLineEdit(CreateData);
        MotName_lineEdit_2->setObjectName(QStringLiteral("MotName_lineEdit_2"));
        MotName_lineEdit_2->setGeometry(QRect(140, 170, 113, 25));
        FatAge_spinBox = new QSpinBox(CreateData);
        FatAge_spinBox->setObjectName(QStringLiteral("FatAge_spinBox"));
        FatAge_spinBox->setGeometry(QRect(160, 100, 111, 26));
        MotAge_spinBox_2 = new QSpinBox(CreateData);
        MotAge_spinBox_2->setObjectName(QStringLiteral("MotAge_spinBox_2"));
        MotAge_spinBox_2->setGeometry(QRect(140, 200, 111, 26));

        retranslateUi(CreateData);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateData, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateData, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateData);
    } // setupUi

    void retranslateUi(QDialog *CreateData)
    {
        CreateData->setWindowTitle(QApplication::translate("CreateData", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("CreateData", "Father:", Q_NULLPTR));
        label_2->setText(QApplication::translate("CreateData", "Name:", Q_NULLPTR));
        label_3->setText(QApplication::translate("CreateData", "Age:", Q_NULLPTR));
        label_4->setText(QApplication::translate("CreateData", "Mother:", Q_NULLPTR));
        label_5->setText(QApplication::translate("CreateData", "Age:", Q_NULLPTR));
        label_6->setText(QApplication::translate("CreateData", "Name:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CreateData: public Ui_CreateData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEDATA_H
