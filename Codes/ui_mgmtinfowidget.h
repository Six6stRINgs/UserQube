/********************************************************************************
** Form generated from reading UI file 'mgmtinfowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MGMTINFOWIDGET_H
#define UI_MGMTINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mgmtinfowidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *mgmt_lab;
    QSpacerItem *horizontalSpacer;
    QFrame *line;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *mgmtdes_lab;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QTreeView *treeView;

    void setupUi(QWidget *mgmtinfowidget)
    {
        if (mgmtinfowidget->objectName().isEmpty())
            mgmtinfowidget->setObjectName(QString::fromUtf8("mgmtinfowidget"));
        mgmtinfowidget->resize(586, 412);
        verticalLayout = new QVBoxLayout(mgmtinfowidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, 0, -1);
        label = new QLabel(mgmtinfowidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        mgmt_lab = new QLabel(mgmtinfowidget);
        mgmt_lab->setObjectName(QString::fromUtf8("mgmt_lab"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(10);
        mgmt_lab->setFont(font1);

        horizontalLayout->addWidget(mgmt_lab);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(mgmtinfowidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        label_3 = new QLabel(mgmtinfowidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        mgmtdes_lab = new QLabel(mgmtinfowidget);
        mgmtdes_lab->setObjectName(QString::fromUtf8("mgmtdes_lab"));

        horizontalLayout_2->addWidget(mgmtdes_lab);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 10);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, -1, 0, 0);
        label_4 = new QLabel(mgmtinfowidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_4->addWidget(label_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_4);

        treeView = new QTreeView(mgmtinfowidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setStyleSheet(QString::fromUtf8(""));
        treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeView->header()->setVisible(true);
        treeView->header()->setCascadingSectionResizes(true);

        horizontalLayout_3->addWidget(treeView);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(mgmtinfowidget);

        QMetaObject::connectSlotsByName(mgmtinfowidget);
    } // setupUi

    void retranslateUi(QWidget *mgmtinfowidget)
    {
        mgmtinfowidget->setWindowTitle(QCoreApplication::translate("mgmtinfowidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("mgmtinfowidget", "\345\220\215\347\247\260\357\274\232", nullptr));
        mgmt_lab->setText(QCoreApplication::translate("mgmtinfowidget", "admin", nullptr));
        label_3->setText(QCoreApplication::translate("mgmtinfowidget", "\347\256\241\347\220\206\347\263\273\347\273\237\346\217\217\350\277\260:", nullptr));
        mgmtdes_lab->setText(QCoreApplication::translate("mgmtinfowidget", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("mgmtinfowidget", "\350\241\250\350\256\276\347\275\256\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mgmtinfowidget: public Ui_mgmtinfowidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MGMTINFOWIDGET_H
