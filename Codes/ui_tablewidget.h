/********************************************************************************
** Form generated from reading UI file 'tablewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEWIDGET_H
#define UI_TABLEWIDGET_H

#include <Field_Widget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tablewidget
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QFrame *line;
    QSpacerItem *verticalSpacer_6;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QTextEdit *describe_input;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addfield;
    QPushButton *delfield;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *tablename_input;
    QLabel *tablename_lab;
    QVBoxLayout *verticalLayout_3;
    QLabel *describle_lab;
    QSpacerItem *verticalSpacer_3;
    QLabel *fieldset_lab;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *vlay_field;
    QScrollArea *fieldscroll;
    QWidget *fieldscrollContents;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *fieldlayout;
    Field_Widget *field_widget;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *tablewidget)
    {
        if (tablewidget->objectName().isEmpty())
            tablewidget->setObjectName(QString::fromUtf8("tablewidget"));
        tablewidget->resize(486, 565);
        verticalLayout = new QVBoxLayout(tablewidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, -1, -1, 0);
        label = new QLabel(tablewidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout_5->addWidget(label);

        line = new QFrame(tablewidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line);


        verticalLayout->addLayout(verticalLayout_5);

        verticalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_6);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, -1, 20, -1);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 4, 1, 1, 1);

        describe_input = new QTextEdit(tablewidget);
        describe_input->setObjectName(QString::fromUtf8("describe_input"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(100);
        sizePolicy.setHeightForWidth(describe_input->sizePolicy().hasHeightForWidth());
        describe_input->setSizePolicy(sizePolicy);

        gridLayout->addWidget(describe_input, 3, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addfield = new QPushButton(tablewidget);
        addfield->setObjectName(QString::fromUtf8("addfield"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addfield->sizePolicy().hasHeightForWidth());
        addfield->setSizePolicy(sizePolicy1);
        addfield->setMinimumSize(QSize(20, 20));
        addfield->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(addfield);

        delfield = new QPushButton(tablewidget);
        delfield->setObjectName(QString::fromUtf8("delfield"));
        sizePolicy1.setHeightForWidth(delfield->sizePolicy().hasHeightForWidth());
        delfield->setSizePolicy(sizePolicy1);
        delfield->setMinimumSize(QSize(20, 20));
        delfield->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(delfield);


        gridLayout->addLayout(horizontalLayout, 6, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        tablename_input = new QLineEdit(tablewidget);
        tablename_input->setObjectName(QString::fromUtf8("tablename_input"));

        verticalLayout_2->addWidget(tablename_input);


        gridLayout->addLayout(verticalLayout_2, 2, 2, 1, 1);

        tablename_lab = new QLabel(tablewidget);
        tablename_lab->setObjectName(QString::fromUtf8("tablename_lab"));

        gridLayout->addWidget(tablename_lab, 2, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        describle_lab = new QLabel(tablewidget);
        describle_lab->setObjectName(QString::fromUtf8("describle_lab"));

        verticalLayout_3->addWidget(describle_lab);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        gridLayout->addLayout(verticalLayout_3, 3, 1, 1, 1);

        fieldset_lab = new QLabel(tablewidget);
        fieldset_lab->setObjectName(QString::fromUtf8("fieldset_lab"));

        gridLayout->addWidget(fieldset_lab, 6, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        vlay_field = new QVBoxLayout();
        vlay_field->setObjectName(QString::fromUtf8("vlay_field"));
        vlay_field->setContentsMargins(5, 0, 0, -1);
        fieldscroll = new QScrollArea(tablewidget);
        fieldscroll->setObjectName(QString::fromUtf8("fieldscroll"));
        fieldscroll->setWidgetResizable(true);
        fieldscrollContents = new QWidget();
        fieldscrollContents->setObjectName(QString::fromUtf8("fieldscrollContents"));
        fieldscrollContents->setGeometry(QRect(0, 0, 460, 118));
        verticalLayout_4 = new QVBoxLayout(fieldscrollContents);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        fieldlayout = new QVBoxLayout();
        fieldlayout->setObjectName(QString::fromUtf8("fieldlayout"));
        field_widget = new Field_Widget(fieldscrollContents);
        field_widget->setObjectName(QString::fromUtf8("field_widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(field_widget->sizePolicy().hasHeightForWidth());
        field_widget->setSizePolicy(sizePolicy2);

        fieldlayout->addWidget(field_widget);


        verticalLayout_4->addLayout(fieldlayout);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        fieldscroll->setWidget(fieldscrollContents);

        vlay_field->addWidget(fieldscroll);


        verticalLayout->addLayout(vlay_field);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_4);

        QWidget::setTabOrder(tablename_input, describe_input);
        QWidget::setTabOrder(describe_input, addfield);
        QWidget::setTabOrder(addfield, delfield);
        QWidget::setTabOrder(delfield, fieldscroll);

        retranslateUi(tablewidget);

        QMetaObject::connectSlotsByName(tablewidget);
    } // setupUi

    void retranslateUi(QWidget *tablewidget)
    {
        tablewidget->setWindowTitle(QCoreApplication::translate("tablewidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("tablewidget", "\350\241\250\350\256\276\347\275\256:", nullptr));
        addfield->setText(QCoreApplication::translate("tablewidget", "+", nullptr));
        delfield->setText(QCoreApplication::translate("tablewidget", "-", nullptr));
        tablename_lab->setText(QCoreApplication::translate("tablewidget", "\350\241\250\345\220\215\357\274\232", nullptr));
        describle_lab->setText(QCoreApplication::translate("tablewidget", "\346\217\217\350\277\260\357\274\232", nullptr));
        fieldset_lab->setText(QCoreApplication::translate("tablewidget", "\345\255\227\346\256\265\350\256\276\347\275\256\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tablewidget: public Ui_tablewidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEWIDGET_H
