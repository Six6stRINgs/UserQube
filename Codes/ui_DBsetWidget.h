/********************************************************************************
** Form generated from reading UI file 'DBsetWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBSETWIDGET_H
#define UI_DBSETWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <myMaterialButton.h>
#include <qtmaterialtextfield.h>

QT_BEGIN_NAMESPACE

class Ui_DBsetWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGridLayout *gridLayout;
    QtMaterialTextField *Account_line;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_2;
    QtMaterialTextField *Passw_line;
    QSpacerItem *horizontalSpacer_4;
    myMaterialButton *passw_view;
    QHBoxLayout *horizontalLayout_2;
    myMaterialButton *Test_btn;
    QHBoxLayout *horizontalLayout_3;
    myMaterialButton *yes_btn;
    myMaterialButton *no_btn;

    void setupUi(QWidget *DBsetWidget)
    {
        if (DBsetWidget->objectName().isEmpty())
            DBsetWidget->setObjectName(QString::fromUtf8("DBsetWidget"));
        DBsetWidget->resize(400, 300);
        DBsetWidget->setStyleSheet(QString::fromUtf8("background-color: white;border-radius: 15px;"));
        verticalLayout = new QVBoxLayout(DBsetWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(DBsetWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Account_line = new QtMaterialTextField(DBsetWidget);
        Account_line->setObjectName(QString::fromUtf8("Account_line"));
        Account_line->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(Account_line, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(35, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(35, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        Passw_line = new QtMaterialTextField(DBsetWidget);
        Passw_line->setObjectName(QString::fromUtf8("Passw_line"));
        Passw_line->setMaximumSize(QSize(300, 16777215));
        Passw_line->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(Passw_line, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(35, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        passw_view = new myMaterialButton(DBsetWidget);
        passw_view->setObjectName(QString::fromUtf8("passw_view"));
        passw_view->setMinimumSize(QSize(0, 28));
        passw_view->setMaximumSize(QSize(35, 28));
        passw_view->setAutoFillBackground(false);

        gridLayout_2->addWidget(passw_view, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Test_btn = new myMaterialButton(DBsetWidget);
        Test_btn->setObjectName(QString::fromUtf8("Test_btn"));

        horizontalLayout_2->addWidget(Test_btn);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        yes_btn = new myMaterialButton(DBsetWidget);
        yes_btn->setObjectName(QString::fromUtf8("yes_btn"));

        horizontalLayout_3->addWidget(yes_btn);

        no_btn = new myMaterialButton(DBsetWidget);
        no_btn->setObjectName(QString::fromUtf8("no_btn"));

        horizontalLayout_3->addWidget(no_btn);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(DBsetWidget);

        QMetaObject::connectSlotsByName(DBsetWidget);
    } // setupUi

    void retranslateUi(QWidget *DBsetWidget)
    {
        DBsetWidget->setWindowTitle(QCoreApplication::translate("DBsetWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("DBsetWidget", "\346\234\254\345\234\260\346\225\260\346\215\256\345\272\223\350\277\236\346\216\245\350\256\276\347\275\256", nullptr));
        passw_view->setText(QCoreApplication::translate("DBsetWidget", "\342\227\210", nullptr));
        Test_btn->setText(QCoreApplication::translate("DBsetWidget", "\350\277\236\346\216\245\346\265\213\350\257\225", nullptr));
        yes_btn->setText(QCoreApplication::translate("DBsetWidget", "\347\241\256\350\256\244", nullptr));
        no_btn->setText(QCoreApplication::translate("DBsetWidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DBsetWidget: public Ui_DBsetWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBSETWIDGET_H
