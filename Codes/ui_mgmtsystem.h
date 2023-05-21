/********************************************************************************
** Form generated from reading UI file 'mgmtsystem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MGMTSYSTEM_H
#define UI_MGMTSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <myMaterialButton.h>

QT_BEGIN_NAMESPACE

class Ui_mgmtsystem
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *tablab;
    QLabel *tabname;
    QSpacerItem *horizontalSpacer_2;
    myMaterialButton *lastbtn;
    myMaterialButton *nextbtn;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QLabel *tableselect_lab;
    QComboBox *tableselect_box;
    QSpacerItem *horizontalSpacer;
    myMaterialButton *addbtn;
    myMaterialButton *editbtn;
    myMaterialButton *searchbtn;
    myMaterialButton *delbtn;
    myMaterialButton *chart_btn;
    QSpacerItem *horizontalSpacer_3;
    QLabel *searchlab;
    myMaterialButton *norbtn;
    QHBoxLayout *horizontalLayout_3;
    QTreeWidget *tabselect_tree;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView;
    QWidget *page_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mgmtsystem)
    {
        if (mgmtsystem->objectName().isEmpty())
            mgmtsystem->setObjectName(QString::fromUtf8("mgmtsystem"));
        mgmtsystem->resize(662, 445);
        centralwidget = new QWidget(mgmtsystem);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(5, -1, -1, 0);
        tablab = new QLabel(centralwidget);
        tablab->setObjectName(QString::fromUtf8("tablab"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        tablab->setFont(font);

        horizontalLayout_4->addWidget(tablab);

        tabname = new QLabel(centralwidget);
        tabname->setObjectName(QString::fromUtf8("tabname"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(12);
        tabname->setFont(font1);

        horizontalLayout_4->addWidget(tabname);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        lastbtn = new myMaterialButton(centralwidget);
        lastbtn->setObjectName(QString::fromUtf8("lastbtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lastbtn->sizePolicy().hasHeightForWidth());
        lastbtn->setSizePolicy(sizePolicy);
        lastbtn->setMinimumSize(QSize(25, 25));
        lastbtn->setMaximumSize(QSize(25, 25));

        horizontalLayout_4->addWidget(lastbtn);

        nextbtn = new myMaterialButton(centralwidget);
        nextbtn->setObjectName(QString::fromUtf8("nextbtn"));
        nextbtn->setMinimumSize(QSize(25, 25));
        nextbtn->setMaximumSize(QSize(25, 25));

        horizontalLayout_4->addWidget(nextbtn);


        verticalLayout->addLayout(horizontalLayout_4);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        tableselect_lab = new QLabel(centralwidget);
        tableselect_lab->setObjectName(QString::fromUtf8("tableselect_lab"));

        horizontalLayout->addWidget(tableselect_lab);

        tableselect_box = new QComboBox(centralwidget);
        tableselect_box->setObjectName(QString::fromUtf8("tableselect_box"));
        tableselect_box->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(tableselect_box);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addbtn = new myMaterialButton(centralwidget);
        addbtn->setObjectName(QString::fromUtf8("addbtn"));
        addbtn->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(addbtn);

        editbtn = new myMaterialButton(centralwidget);
        editbtn->setObjectName(QString::fromUtf8("editbtn"));
        editbtn->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(editbtn);

        searchbtn = new myMaterialButton(centralwidget);
        searchbtn->setObjectName(QString::fromUtf8("searchbtn"));
        searchbtn->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(searchbtn);

        delbtn = new myMaterialButton(centralwidget);
        delbtn->setObjectName(QString::fromUtf8("delbtn"));
        delbtn->setMaximumSize(QSize(60, 16777215));
        delbtn->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(delbtn);

        chart_btn = new myMaterialButton(centralwidget);
        chart_btn->setObjectName(QString::fromUtf8("chart_btn"));

        horizontalLayout->addWidget(chart_btn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        searchlab = new QLabel(centralwidget);
        searchlab->setObjectName(QString::fromUtf8("searchlab"));

        horizontalLayout->addWidget(searchlab);

        norbtn = new myMaterialButton(centralwidget);
        norbtn->setObjectName(QString::fromUtf8("norbtn"));

        horizontalLayout->addWidget(norbtn);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 0);
        tabselect_tree = new QTreeWidget(centralwidget);
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setFont(0, font2);
        tabselect_tree->setHeaderItem(__qtreewidgetitem);
        tabselect_tree->setObjectName(QString::fromUtf8("tabselect_tree"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabselect_tree->sizePolicy().hasHeightForWidth());
        tabselect_tree->setSizePolicy(sizePolicy1);
        tabselect_tree->setMaximumSize(QSize(200, 16777215));
        tabselect_tree->header()->setVisible(false);
        tabselect_tree->header()->setCascadingSectionResizes(true);
        tabselect_tree->header()->setMinimumSectionSize(20);
        tabselect_tree->header()->setDefaultSectionSize(100);
        tabselect_tree->header()->setHighlightSections(true);
        tabselect_tree->header()->setProperty("showSortIndicator", QVariant(false));
        tabselect_tree->header()->setStretchLastSection(true);

        horizontalLayout_3->addWidget(tabselect_tree);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout_2 = new QHBoxLayout(page);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tableView = new QTableView(page);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        horizontalLayout_2->addWidget(tableView);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        horizontalLayout_3->addWidget(stackedWidget);


        verticalLayout->addLayout(horizontalLayout_3);

        mgmtsystem->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mgmtsystem);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 662, 21));
        mgmtsystem->setMenuBar(menubar);
        statusbar = new QStatusBar(mgmtsystem);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mgmtsystem->setStatusBar(statusbar);

        retranslateUi(mgmtsystem);
        QObject::connect(tableselect_box, SIGNAL(currentIndexChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));

        QMetaObject::connectSlotsByName(mgmtsystem);
    } // setupUi

    void retranslateUi(QMainWindow *mgmtsystem)
    {
        mgmtsystem->setWindowTitle(QCoreApplication::translate("mgmtsystem", "MainWindow", nullptr));
        tablab->setText(QCoreApplication::translate("mgmtsystem", "\345\275\223\345\211\215\350\241\250\357\274\232", nullptr));
        tabname->setText(QCoreApplication::translate("mgmtsystem", "TextLabel", nullptr));
        lastbtn->setText(QCoreApplication::translate("mgmtsystem", "\342\206\221", nullptr));
        nextbtn->setText(QCoreApplication::translate("mgmtsystem", "\342\206\223", nullptr));
        tableselect_lab->setText(QCoreApplication::translate("mgmtsystem", "\350\241\250\351\200\211\346\213\251\357\274\232", nullptr));
        addbtn->setText(QCoreApplication::translate("mgmtsystem", "\346\226\260\345\242\236", nullptr));
        editbtn->setText(QCoreApplication::translate("mgmtsystem", "\346\233\264\346\226\260", nullptr));
        searchbtn->setText(QCoreApplication::translate("mgmtsystem", "\346\237\245\346\211\276", nullptr));
        delbtn->setText(QCoreApplication::translate("mgmtsystem", "\345\210\240\351\231\244", nullptr));
        chart_btn->setText(QCoreApplication::translate("mgmtsystem", "\345\233\276\350\241\250\345\210\206\346\236\220", nullptr));
        searchlab->setText(QCoreApplication::translate("mgmtsystem", "(\346\220\234\347\264\242\346\250\241\345\274\217\344\270\255)", nullptr));
        norbtn->setText(QCoreApplication::translate("mgmtsystem", "\346\201\242\345\244\215", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = tabselect_tree->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("mgmtsystem", "\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mgmtsystem: public Ui_mgmtsystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MGMTSYSTEM_H
