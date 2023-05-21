/********************************************************************************
** Form generated from reading UI file 'Create_MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_MAINWINDOW_H
#define UI_CREATE_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <Table_Widget.h>

QT_BEGIN_NAMESPACE

class Ui_Create_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QVBoxLayout *verticalLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *baseinfo;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QFrame *line;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_4;
    QLabel *mgmtsys_lab;
    QLineEdit *mgmtsys_input;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QFormLayout *formLayout_2;
    QLabel *mgmtdes_lab;
    QTextEdit *mgmtdes_input;
    QGridLayout *gridLayout;
    QPushButton *deltable;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *addtable;
    QSpacerItem *verticalSpacer_2;
    Table_Widget *table_1;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *createbtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Create_MainWindow)
    {
        if (Create_MainWindow->objectName().isEmpty())
            Create_MainWindow->setObjectName(QString::fromUtf8("Create_MainWindow"));
        Create_MainWindow->resize(631, 689);
        Create_MainWindow->setMinimumSize(QSize(600, 600));
        centralwidget = new QWidget(Create_MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(50, 0));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 171, 626));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        treeWidget = new QTreeWidget(scrollAreaWidgetContents);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setFont(0, font);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setAnimated(true);
        treeWidget->setAllColumnsShowFocus(false);

        verticalLayout->addWidget(treeWidget);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, -1, -1, 0);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        baseinfo = new QWidget();
        baseinfo->setObjectName(QString::fromUtf8("baseinfo"));
        verticalLayout_3 = new QVBoxLayout(baseinfo);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(baseinfo);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        font1.setStyleStrategy(QFont::PreferDefault);
        label->setFont(font1);

        verticalLayout_2->addWidget(label);

        line = new QFrame(baseinfo);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_3->addItem(verticalSpacer);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(5, -1, -1, -1);
        mgmtsys_lab = new QLabel(baseinfo);
        mgmtsys_lab->setObjectName(QString::fromUtf8("mgmtsys_lab"));

        gridLayout_4->addWidget(mgmtsys_lab, 0, 0, 1, 1);

        mgmtsys_input = new QLineEdit(baseinfo);
        mgmtsys_input->setObjectName(QString::fromUtf8("mgmtsys_input"));

        gridLayout_4->addWidget(mgmtsys_input, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_4);

        horizontalSpacer = new QSpacerItem(414, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_3);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(5, -1, -1, -1);
        mgmtdes_lab = new QLabel(baseinfo);
        mgmtdes_lab->setObjectName(QString::fromUtf8("mgmtdes_lab"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, mgmtdes_lab);

        mgmtdes_input = new QTextEdit(baseinfo);
        mgmtdes_input->setObjectName(QString::fromUtf8("mgmtdes_input"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, mgmtdes_input);


        verticalLayout_3->addLayout(formLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, -1, 0);
        deltable = new QPushButton(baseinfo);
        deltable->setObjectName(QString::fromUtf8("deltable"));

        gridLayout->addWidget(deltable, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        addtable = new QPushButton(baseinfo);
        addtable->setObjectName(QString::fromUtf8("addtable"));

        gridLayout->addWidget(addtable, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        verticalSpacer_2 = new QSpacerItem(20, 210, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        stackedWidget->addWidget(baseinfo);
        table_1 = new Table_Widget();
        table_1->setObjectName(QString::fromUtf8("table_1"));
        stackedWidget->addWidget(table_1);

        verticalLayout_4->addWidget(stackedWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        createbtn = new QPushButton(centralwidget);
        createbtn->setObjectName(QString::fromUtf8("createbtn"));

        horizontalLayout_2->addWidget(createbtn);


        verticalLayout_4->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_4);

        Create_MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Create_MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 631, 21));
        Create_MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(Create_MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Create_MainWindow->setStatusBar(statusbar);

        retranslateUi(Create_MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Create_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *Create_MainWindow)
    {
        Create_MainWindow->setWindowTitle(QCoreApplication::translate("Create_MainWindow", "MainWindow", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("Create_MainWindow", "\345\210\227\350\241\250", nullptr));
        label->setText(QCoreApplication::translate("Create_MainWindow", "\347\256\241\347\220\206\347\263\273\347\273\237\350\256\276\347\275\256:", nullptr));
        mgmtsys_lab->setText(QCoreApplication::translate("Create_MainWindow", "\347\256\241\347\220\206\347\263\273\347\273\237\345\220\215\347\247\260\357\274\232", nullptr));
        mgmtdes_lab->setText(QCoreApplication::translate("Create_MainWindow", "\347\263\273\347\273\237\346\217\217\350\277\260\357\274\232", nullptr));
        deltable->setText(QCoreApplication::translate("Create_MainWindow", "\345\210\240\351\231\244\350\241\250", nullptr));
        addtable->setText(QCoreApplication::translate("Create_MainWindow", "\345\242\236\346\267\273\350\241\250", nullptr));
        createbtn->setText(QCoreApplication::translate("Create_MainWindow", "\345\210\233\345\273\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Create_MainWindow: public Ui_Create_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_MAINWINDOW_H
