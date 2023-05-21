/********************************************************************************
** Form generated from reading UI file 'Personal_MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONAL_MAINWINDOW_H
#define UI_PERSONAL_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <myMaterialButton.h>

QT_BEGIN_NAMESPACE

class Ui_Personal_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *introduce;
    QHBoxLayout *horizontalLayout_3;
    QLabel *account_lab;
    QSpacerItem *horizontalSpacer_2;
    QTextBrowser *textBrowser;
    QSpacerItem *verticalSpacer;
    QFrame *line;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    myMaterialButton *create_btn;
    myMaterialButton *selectbtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Personal_MainWindow)
    {
        if (Personal_MainWindow->objectName().isEmpty())
            Personal_MainWindow->setObjectName(QString::fromUtf8("Personal_MainWindow"));
        Personal_MainWindow->resize(662, 484);
        centralwidget = new QWidget(Personal_MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        treeWidget = new QTreeWidget(centralwidget);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setFont(0, font);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy);
        treeWidget->setMinimumSize(QSize(200, 0));
        treeWidget->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(treeWidget);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setContentsMargins(-1, -1, -1, 0);
        introduce = new QLabel(page);
        introduce->setObjectName(QString::fromUtf8("introduce"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        introduce->setFont(font1);
        introduce->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(introduce, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 0);
        account_lab = new QLabel(page);
        account_lab->setObjectName(QString::fromUtf8("account_lab"));
        QFont font2;
        font2.setPointSize(10);
        account_lab->setFont(font2);
        account_lab->setLayoutDirection(Qt::LeftToRight);
        account_lab->setScaledContents(false);
        account_lab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(account_lab);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        textBrowser = new QTextBrowser(page);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        textBrowser->setFont(font3);
        textBrowser->setAutoFillBackground(false);
        textBrowser->setStyleSheet(QString::fromUtf8("background:transparent;border-width:0;border-style:outset"));
        textBrowser->setTabChangesFocus(false);

        gridLayout->addWidget(textBrowser, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        line = new QFrame(page);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 2, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        create_btn = new myMaterialButton(widget);
        create_btn->setObjectName(QString::fromUtf8("create_btn"));

        horizontalLayout_2->addWidget(create_btn);

        selectbtn = new myMaterialButton(widget);
        selectbtn->setObjectName(QString::fromUtf8("selectbtn"));

        horizontalLayout_2->addWidget(selectbtn);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addWidget(widget);

        Personal_MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Personal_MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 662, 21));
        Personal_MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(Personal_MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Personal_MainWindow->setStatusBar(statusbar);

        retranslateUi(Personal_MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Personal_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *Personal_MainWindow)
    {
        Personal_MainWindow->setWindowTitle(QCoreApplication::translate("Personal_MainWindow", "\344\270\252\344\272\272\347\225\214\351\235\242", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("Personal_MainWindow", "\345\267\262\345\210\233\345\273\272\347\232\204\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        introduce->setText(QCoreApplication::translate("Personal_MainWindow", "\344\270\252\344\272\272\347\225\214\351\235\242", nullptr));
        account_lab->setText(QCoreApplication::translate("Personal_MainWindow", "Admin", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Personal_MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Adobe \351\273\221\344\275\223 Std R'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">      \346\254\242\350\277\216\344\275\277\347\224\250\346\210\221\344\273\254\347\232\204\347\256\241\347\220\206\347\263\273\347\273\237\357\274\201\350\277\231\344\270\252\347\250\213\345\272\217\346\227\250\345\234\250\344\270\272\346\202\250\346\217\220\344\276\233\344\270\200\344\270\252\347\256\200\345\215\225\343\200\201\351\253\230\346\225\210\343\200\201\345\217\257\345\256\232\345\210\266\347\232\204\347\256\241\347\220\206\345\267\245\345\205\267\343\200\202</span></p>\n"
"<p style=\" margin"
                        "-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">      \346\202\250\345\217\257\344\273\245\346\240\271\346\215\256\350\207\252\345\267\261\347\232\204\351\234\200\346\261\202\346\235\245\345\256\232\345\210\266\347\256\241\347\220\206\345\206\205\345\256\271\357\274\214\350\256\251\346\202\250\347\232\204\345\267\245\344\275\234\346\233\264\345\212\240\350\275\273\346\235\276\343\200\202\346\204\237\350\260\242\346\202\250\345\257\271\346\210\221\344\273\254\347\256\241\347\220\206\347\263\273\347\273\237\347\232\204\344\277\241\344\273\273\357\274\214\345\270\214\346\234\233\346\202\250\350\203\275\345\244\237\345\234\250\344\275\277\347\224\250\344\270\255\350\216\267\345\276\227\346\204\211\346\202\246\347\232\204\344\275\223\351\252\214\343\200\202</span></p></body></html>", nullptr));
        create_btn->setText(QCoreApplication::translate("Personal_MainWindow", "\346\226\260\345\273\272", nullptr));
        selectbtn->setText(QCoreApplication::translate("Personal_MainWindow", "\351\200\211\346\213\251\346\255\244\347\263\273\347\273\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Personal_MainWindow: public Ui_Personal_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONAL_MAINWINDOW_H
