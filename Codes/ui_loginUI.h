/********************************************************************************
** Form generated from reading UI file 'loginUI.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINUI_H
#define UI_LOGINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <myMaterialButton.h>
#include <qtmaterialtextfield.h>

QT_BEGIN_NAMESPACE

class Ui_loginUI
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *photo_lab;
    QLabel *difficultT_T;
    QGridLayout *gridLayout_2;
    QLabel *account_lab;
    QtMaterialTextField *account_input;
    QLabel *passw_lab;
    QtMaterialTextField *passw_input;
    myMaterialButton *passw_view;
    QHBoxLayout *horizontalLayout;
    myMaterialButton *login_btn;
    myMaterialButton *change_btn;
    myMaterialButton *DBset_btn;
    QVBoxLayout *verticalLayout_2;
    myMaterialButton *quit_btn;

    void setupUi(QWidget *loginUI)
    {
        if (loginUI->objectName().isEmpty())
            loginUI->setObjectName(QString::fromUtf8("loginUI"));
        loginUI->setWindowModality(Qt::NonModal);
        loginUI->resize(380, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loginUI->sizePolicy().hasHeightForWidth());
        loginUI->setSizePolicy(sizePolicy);
        loginUI->setMinimumSize(QSize(300, 400));
        loginUI->setMaximumSize(QSize(500, 700));
        loginUI->setAcceptDrops(false);
        loginUI->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(loginUI);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        photo_lab = new QLabel(loginUI);
        photo_lab->setObjectName(QString::fromUtf8("photo_lab"));
        sizePolicy.setHeightForWidth(photo_lab->sizePolicy().hasHeightForWidth());
        photo_lab->setSizePolicy(sizePolicy);
        photo_lab->setStyleSheet(QString::fromUtf8("background-color: white;border-radius: 15px;"));
        photo_lab->setScaledContents(true);

        verticalLayout_3->addWidget(photo_lab);

        difficultT_T = new QLabel(loginUI);
        difficultT_T->setObjectName(QString::fromUtf8("difficultT_T"));
        difficultT_T->setMinimumSize(QSize(0, 0));
        difficultT_T->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(15);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        difficultT_T->setFont(font);
        difficultT_T->setContextMenuPolicy(Qt::DefaultContextMenu);
        difficultT_T->setLayoutDirection(Qt::LeftToRight);
        difficultT_T->setTextFormat(Qt::MarkdownText);
        difficultT_T->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(difficultT_T);


        verticalLayout->addLayout(verticalLayout_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(20, -1, 20, -1);
        account_lab = new QLabel(loginUI);
        account_lab->setObjectName(QString::fromUtf8("account_lab"));

        gridLayout_2->addWidget(account_lab, 0, 0, 1, 1);

        account_input = new QtMaterialTextField(loginUI);
        account_input->setObjectName(QString::fromUtf8("account_input"));

        gridLayout_2->addWidget(account_input, 0, 1, 1, 1);

        passw_lab = new QLabel(loginUI);
        passw_lab->setObjectName(QString::fromUtf8("passw_lab"));

        gridLayout_2->addWidget(passw_lab, 1, 0, 1, 1);

        passw_input = new QtMaterialTextField(loginUI);
        passw_input->setObjectName(QString::fromUtf8("passw_input"));
        passw_input->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(passw_input, 1, 1, 1, 1);

        passw_view = new myMaterialButton(loginUI);
        passw_view->setObjectName(QString::fromUtf8("passw_view"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(passw_view->sizePolicy().hasHeightForWidth());
        passw_view->setSizePolicy(sizePolicy1);
        passw_view->setMinimumSize(QSize(30, 28));
        passw_view->setMaximumSize(QSize(50, 28));

        gridLayout_2->addWidget(passw_view, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(20, -1, 20, 0);
        login_btn = new myMaterialButton(loginUI);
        login_btn->setObjectName(QString::fromUtf8("login_btn"));
        login_btn->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(login_btn);

        change_btn = new myMaterialButton(loginUI);
        change_btn->setObjectName(QString::fromUtf8("change_btn"));
        change_btn->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(change_btn);

        DBset_btn = new myMaterialButton(loginUI);
        DBset_btn->setObjectName(QString::fromUtf8("DBset_btn"));
        DBset_btn->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(DBset_btn);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(20, -1, 20, 0);
        quit_btn = new myMaterialButton(loginUI);
        quit_btn->setObjectName(QString::fromUtf8("quit_btn"));
        quit_btn->setMinimumSize(QSize(0, 0));

        verticalLayout_2->addWidget(quit_btn);


        verticalLayout->addLayout(verticalLayout_2);

        QWidget::setTabOrder(account_input, passw_input);
        QWidget::setTabOrder(passw_input, login_btn);
        QWidget::setTabOrder(login_btn, change_btn);
        QWidget::setTabOrder(change_btn, quit_btn);

        retranslateUi(loginUI);

        QMetaObject::connectSlotsByName(loginUI);
    } // setupUi

    void retranslateUi(QWidget *loginUI)
    {
        loginUI->setWindowTitle(QCoreApplication::translate("loginUI", "\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
        photo_lab->setText(QString());
        difficultT_T->setText(QCoreApplication::translate("loginUI", "\345\245\275 \351\232\276", nullptr));
        account_lab->setText(QCoreApplication::translate("loginUI", "\347\224\250\346\210\267\357\274\232", nullptr));
        passw_lab->setText(QCoreApplication::translate("loginUI", "\345\257\206\347\240\201\357\274\232", nullptr));
        passw_view->setText(QCoreApplication::translate("loginUI", "\342\227\210", nullptr));
        login_btn->setText(QCoreApplication::translate("loginUI", "\347\231\273\345\275\225", nullptr));
        change_btn->setText(QCoreApplication::translate("loginUI", "\345\210\233\345\273\272", nullptr));
        DBset_btn->setText(QCoreApplication::translate("loginUI", "\350\256\276\347\275\256", nullptr));
        quit_btn->setText(QCoreApplication::translate("loginUI", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginUI: public Ui_loginUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINUI_H
