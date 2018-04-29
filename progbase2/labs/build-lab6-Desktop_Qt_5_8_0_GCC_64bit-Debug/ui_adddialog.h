/********************************************************************************
** Form generated from reading UI file 'adddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDIALOG_H
#define UI_ADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AddDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *Name_lineEdit;
    QLineEdit *Friend_lineEdit;
    QSpinBox *Age_spinBox;
    QDoubleSpinBox *Mass_doubleSpinBox;

    void setupUi(QDialog *AddDialog)
    {
        if (AddDialog->objectName().isEmpty())
            AddDialog->setObjectName(QStringLiteral("AddDialog"));
        AddDialog->resize(271, 197);
        buttonBox = new QDialogButtonBox(AddDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-260, 150, 481, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(AddDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 141, 17));
        label_2 = new QLabel(AddDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 30, 67, 17));
        label_3 = new QLabel(AddDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 60, 67, 17));
        label_4 = new QLabel(AddDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 90, 67, 17));
        label_5 = new QLabel(AddDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 120, 67, 17));
        Name_lineEdit = new QLineEdit(AddDialog);
        Name_lineEdit->setObjectName(QStringLiteral("Name_lineEdit"));
        Name_lineEdit->setGeometry(QRect(80, 30, 181, 25));
        Friend_lineEdit = new QLineEdit(AddDialog);
        Friend_lineEdit->setObjectName(QStringLiteral("Friend_lineEdit"));
        Friend_lineEdit->setGeometry(QRect(80, 90, 181, 25));
        Age_spinBox = new QSpinBox(AddDialog);
        Age_spinBox->setObjectName(QStringLiteral("Age_spinBox"));
        Age_spinBox->setGeometry(QRect(80, 60, 181, 26));
        Mass_doubleSpinBox = new QDoubleSpinBox(AddDialog);
        Mass_doubleSpinBox->setObjectName(QStringLiteral("Mass_doubleSpinBox"));
        Mass_doubleSpinBox->setGeometry(QRect(80, 120, 181, 26));

        retranslateUi(AddDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddDialog);
    } // setupUi

    void retranslateUi(QDialog *AddDialog)
    {
        AddDialog->setWindowTitle(QApplication::translate("AddDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("AddDialog", "Enter object data", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddDialog", "Name:", Q_NULLPTR));
        label_3->setText(QApplication::translate("AddDialog", "Age:", Q_NULLPTR));
        label_4->setText(QApplication::translate("AddDialog", "Friend:", Q_NULLPTR));
        label_5->setText(QApplication::translate("AddDialog", "Mass:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddDialog: public Ui_AddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDIALOG_H
