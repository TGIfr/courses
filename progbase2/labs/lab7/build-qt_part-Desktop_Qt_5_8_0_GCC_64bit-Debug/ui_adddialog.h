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

QT_BEGIN_NAMESPACE

class Ui_adddialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *City_lineEdit;
    QLabel *label;
    QLabel *label_5;
    QDoubleSpinBox *Lng_doubleSpinBox;
    QDoubleSpinBox *Lat_doubleSpinBox;

    void setupUi(QDialog *adddialog)
    {
        if (adddialog->objectName().isEmpty())
            adddialog->setObjectName(QStringLiteral("adddialog"));
        adddialog->resize(282, 187);
        buttonBox = new QDialogButtonBox(adddialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-130, 140, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_2 = new QLabel(adddialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 67, 17));
        label_3 = new QLabel(adddialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 70, 67, 17));
        City_lineEdit = new QLineEdit(adddialog);
        City_lineEdit->setObjectName(QStringLiteral("City_lineEdit"));
        City_lineEdit->setGeometry(QRect(80, 40, 181, 25));
        label = new QLabel(adddialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 141, 17));
        label_5 = new QLabel(adddialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 110, 67, 17));
        Lng_doubleSpinBox = new QDoubleSpinBox(adddialog);
        Lng_doubleSpinBox->setObjectName(QStringLiteral("Lng_doubleSpinBox"));
        Lng_doubleSpinBox->setGeometry(QRect(80, 110, 181, 26));
        Lng_doubleSpinBox->setMinimum(-180);
        Lng_doubleSpinBox->setMaximum(180);
        Lat_doubleSpinBox = new QDoubleSpinBox(adddialog);
        Lat_doubleSpinBox->setObjectName(QStringLiteral("Lat_doubleSpinBox"));
        Lat_doubleSpinBox->setGeometry(QRect(80, 70, 181, 26));
        Lat_doubleSpinBox->setDecimals(6);
        Lat_doubleSpinBox->setMinimum(-90);
        Lat_doubleSpinBox->setMaximum(90);

        retranslateUi(adddialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), adddialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), adddialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(adddialog);
    } // setupUi

    void retranslateUi(QDialog *adddialog)
    {
        adddialog->setWindowTitle(QApplication::translate("adddialog", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("adddialog", "City:", Q_NULLPTR));
        label_3->setText(QApplication::translate("adddialog", "Lat:", Q_NULLPTR));
        label->setText(QApplication::translate("adddialog", "Enter object data", Q_NULLPTR));
        label_5->setText(QApplication::translate("adddialog", "Lng:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class adddialog: public Ui_adddialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDIALOG_H
