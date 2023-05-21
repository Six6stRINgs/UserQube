/********************************************************************************
** Form generated from reading UI file 'fieldwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIELDWIDGET_H
#define UI_FIELDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fieldwidget
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QComboBox *type_combo;
    QLabel *name_lab;
    QLineEdit *name_input;
    QSpacerItem *horizontalSpacer_2;
    QLabel *type_lab;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *intwid;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QRadioButton *int_btn;
    QRadioButton *long_btn;
    QCheckBox *int_uns;
    QCheckBox *int_unq;
    QWidget *doublewid;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *double_uns;
    QCheckBox *double_unq;
    QWidget *charwid;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_6;
    QLabel *char_len_lab;
    QLineEdit *char_len_input;
    QRadioButton *char_box;
    QRadioButton *varchar_box;
    QCheckBox *char_unq;
    QWidget *boolwid;
    QWidget *timewid;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *time_year;
    QCheckBox *time_month;
    QCheckBox *time_day;
    QCheckBox *time_hour;

    void setupUi(QWidget *fieldwidget)
    {
        if (fieldwidget->objectName().isEmpty())
            fieldwidget->setObjectName(QString::fromUtf8("fieldwidget"));
        fieldwidget->resize(454, 90);
        verticalLayout = new QVBoxLayout(fieldwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        type_combo = new QComboBox(fieldwidget);
        type_combo->addItem(QString());
        type_combo->addItem(QString());
        type_combo->addItem(QString());
        type_combo->addItem(QString());
        type_combo->addItem(QString());
        type_combo->setObjectName(QString::fromUtf8("type_combo"));

        gridLayout_3->addWidget(type_combo, 0, 4, 1, 1);

        name_lab = new QLabel(fieldwidget);
        name_lab->setObjectName(QString::fromUtf8("name_lab"));

        gridLayout_3->addWidget(name_lab, 0, 0, 1, 1);

        name_input = new QLineEdit(fieldwidget);
        name_input->setObjectName(QString::fromUtf8("name_input"));

        gridLayout_3->addWidget(name_input, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        type_lab = new QLabel(fieldwidget);
        type_lab->setObjectName(QString::fromUtf8("type_lab"));

        gridLayout_3->addWidget(type_lab, 0, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        stackedWidget = new QStackedWidget(fieldwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        intwid = new QWidget();
        intwid->setObjectName(QString::fromUtf8("intwid"));
        horizontalLayout_2 = new QHBoxLayout(intwid);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        int_btn = new QRadioButton(intwid);
        int_btn->setObjectName(QString::fromUtf8("int_btn"));
        int_btn->setChecked(true);

        horizontalLayout_2->addWidget(int_btn);

        long_btn = new QRadioButton(intwid);
        long_btn->setObjectName(QString::fromUtf8("long_btn"));

        horizontalLayout_2->addWidget(long_btn);

        int_uns = new QCheckBox(intwid);
        int_uns->setObjectName(QString::fromUtf8("int_uns"));

        horizontalLayout_2->addWidget(int_uns);

        int_unq = new QCheckBox(intwid);
        int_unq->setObjectName(QString::fromUtf8("int_unq"));

        horizontalLayout_2->addWidget(int_unq);

        stackedWidget->addWidget(intwid);
        doublewid = new QWidget();
        doublewid->setObjectName(QString::fromUtf8("doublewid"));
        horizontalLayout_3 = new QHBoxLayout(doublewid);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        double_uns = new QCheckBox(doublewid);
        double_uns->setObjectName(QString::fromUtf8("double_uns"));

        horizontalLayout_3->addWidget(double_uns);

        double_unq = new QCheckBox(doublewid);
        double_unq->setObjectName(QString::fromUtf8("double_unq"));

        horizontalLayout_3->addWidget(double_unq);

        stackedWidget->addWidget(doublewid);
        charwid = new QWidget();
        charwid->setObjectName(QString::fromUtf8("charwid"));
        horizontalLayout_4 = new QHBoxLayout(charwid);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        char_len_lab = new QLabel(charwid);
        char_len_lab->setObjectName(QString::fromUtf8("char_len_lab"));

        horizontalLayout_4->addWidget(char_len_lab);

        char_len_input = new QLineEdit(charwid);
        char_len_input->setObjectName(QString::fromUtf8("char_len_input"));

        horizontalLayout_4->addWidget(char_len_input);

        char_box = new QRadioButton(charwid);
        char_box->setObjectName(QString::fromUtf8("char_box"));
        char_box->setChecked(true);

        horizontalLayout_4->addWidget(char_box);

        varchar_box = new QRadioButton(charwid);
        varchar_box->setObjectName(QString::fromUtf8("varchar_box"));

        horizontalLayout_4->addWidget(varchar_box);

        char_unq = new QCheckBox(charwid);
        char_unq->setObjectName(QString::fromUtf8("char_unq"));

        horizontalLayout_4->addWidget(char_unq);

        stackedWidget->addWidget(charwid);
        boolwid = new QWidget();
        boolwid->setObjectName(QString::fromUtf8("boolwid"));
        stackedWidget->addWidget(boolwid);
        timewid = new QWidget();
        timewid->setObjectName(QString::fromUtf8("timewid"));
        horizontalLayout_5 = new QHBoxLayout(timewid);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        time_year = new QCheckBox(timewid);
        time_year->setObjectName(QString::fromUtf8("time_year"));

        horizontalLayout_5->addWidget(time_year);

        time_month = new QCheckBox(timewid);
        time_month->setObjectName(QString::fromUtf8("time_month"));

        horizontalLayout_5->addWidget(time_month);

        time_day = new QCheckBox(timewid);
        time_day->setObjectName(QString::fromUtf8("time_day"));

        horizontalLayout_5->addWidget(time_day);

        time_hour = new QCheckBox(timewid);
        time_hour->setObjectName(QString::fromUtf8("time_hour"));
        time_hour->setCheckable(true);
        time_hour->setChecked(true);

        horizontalLayout_5->addWidget(time_hour);

        stackedWidget->addWidget(timewid);

        horizontalLayout->addWidget(stackedWidget);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(name_input, type_combo);

        retranslateUi(fieldwidget);
        QObject::connect(type_combo, SIGNAL(currentIndexChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(fieldwidget);
    } // setupUi

    void retranslateUi(QWidget *fieldwidget)
    {
        fieldwidget->setWindowTitle(QCoreApplication::translate("fieldwidget", "Form", nullptr));
        type_combo->setItemText(0, QCoreApplication::translate("fieldwidget", "\346\225\264\346\225\260\345\236\213", nullptr));
        type_combo->setItemText(1, QCoreApplication::translate("fieldwidget", "\346\265\256\347\202\271\345\236\213", nullptr));
        type_combo->setItemText(2, QCoreApplication::translate("fieldwidget", "\345\255\227\347\254\246\345\236\213", nullptr));
        type_combo->setItemText(3, QCoreApplication::translate("fieldwidget", "\345\270\203\345\260\224\345\236\213", nullptr));
        type_combo->setItemText(4, QCoreApplication::translate("fieldwidget", "\346\227\266\351\227\264\345\236\213", nullptr));

        name_lab->setText(QCoreApplication::translate("fieldwidget", "\345\255\227\346\256\265\345\220\215\347\247\260\357\274\232", nullptr));
        type_lab->setText(QCoreApplication::translate("fieldwidget", "\345\255\227\346\256\265\347\261\273\345\236\213\357\274\232", nullptr));
        int_btn->setText(QCoreApplication::translate("fieldwidget", "\346\231\256\351\200\232", nullptr));
        long_btn->setText(QCoreApplication::translate("fieldwidget", "\351\225\277\346\225\264\345\236\213", nullptr));
        int_uns->setText(QCoreApplication::translate("fieldwidget", "\346\227\240\347\254\246\345\217\267", nullptr));
        int_unq->setText(QCoreApplication::translate("fieldwidget", "\345\224\257\344\270\200", nullptr));
        double_uns->setText(QCoreApplication::translate("fieldwidget", "\346\227\240\347\254\246\345\217\267", nullptr));
        double_unq->setText(QCoreApplication::translate("fieldwidget", "\345\224\257\344\270\200", nullptr));
        char_len_lab->setText(QCoreApplication::translate("fieldwidget", "\351\225\277\345\272\246\357\274\232", nullptr));
        char_box->setText(QCoreApplication::translate("fieldwidget", "\345\256\232\351\225\277\345\255\227\347\254\246", nullptr));
        varchar_box->setText(QCoreApplication::translate("fieldwidget", "\345\217\230\351\225\277\345\255\227\347\254\246", nullptr));
        char_unq->setText(QCoreApplication::translate("fieldwidget", "\345\224\257\344\270\200", nullptr));
        time_year->setText(QCoreApplication::translate("fieldwidget", "\345\271\264", nullptr));
        time_month->setText(QCoreApplication::translate("fieldwidget", "\346\234\210", nullptr));
        time_day->setText(QCoreApplication::translate("fieldwidget", "\346\227\245", nullptr));
        time_hour->setText(QCoreApplication::translate("fieldwidget", "\346\227\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fieldwidget: public Ui_fieldwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIELDWIDGET_H
