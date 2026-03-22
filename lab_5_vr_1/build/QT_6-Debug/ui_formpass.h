/********************************************************************************
** Form generated from reading UI file 'formpass.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPASS_H
#define UI_FORMPASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormPass
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *FormPass)
    {
        if (FormPass->objectName().isEmpty())
            FormPass->setObjectName("FormPass");
        FormPass->resize(378, 218);
        FormPass->setStyleSheet(QString::fromUtf8("background-color: #2D2F33;\n"
" border: 1px solid #dcdfe6;\n"
"border-radius: 8px;\n"
"gridline-color: #f0f0f0;\n"
"selection-background-color: #eef2ff; \n"
"selection-color: #4776E6; "));
        pushButton = new QPushButton(FormPass);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 170, 101, 31));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: blue;\n"
"    color: white;\n"
"    border: 2px solid darkblue;\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"   font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: darkblue;\n"
"    }"));
        pushButton_2 = new QPushButton(FormPass);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(210, 170, 101, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;\n"
"    color: white;\n"
"    border: 2px solid darkred;\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"   background-color: darkred;\n"
"}"));
        label = new QLabel(FormPass);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 40, 111, 101));
        label->setStyleSheet(QString::fromUtf8("border: none;\n"
"background: transparent;"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/f_5.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(FormPass);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 40, 161, 101));
        label_2->setStyleSheet(QString::fromUtf8("opacity: 0; "));

        retranslateUi(FormPass);

        QMetaObject::connectSlotsByName(FormPass);
    } // setupUi

    void retranslateUi(QWidget *FormPass)
    {
        FormPass->setWindowTitle(QCoreApplication::translate("FormPass", "\320\237\321\200\320\276\320\277\321\203\321\201\320\272", nullptr));
        pushButton->setText(QCoreApplication::translate("FormPass", "\320\237\320\265\321\207\320\260\321\202\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FormPass", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormPass: public Ui_FormPass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPASS_H
