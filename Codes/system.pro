QT       += core gui
QT       += sql
QT       += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
RC_ICONS = logo.ico

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    create_mainwindow.cpp \
    db_construction.cpp \
    framelessWidget.cpp \
    login_widget.cpp \
    main.cpp \
    mgmt_mainwindow.cpp \
    personal_mainwindow.cpp \
    systemcore.cpp

HEADERS += \
    CusHeaders/BoolDelegate.h \
    CusHeaders/DateTimeDelegate.h \
    CusHeaders/mgmtinfo_widget.h \
    CusHeaders/myMaterialButton.h \
    CustomClass.h \
    CustomDefine.h \
    PublicSignal.h \
    create_mainwindow.h \
    db_construction.h \
    field_widget.h \
    framelessWidget.h \
    login_widget.h \
    mgmt_mainwindow.h \
    personal_mainwindow.h \
    systemcore.h \
    table_widget.h

FORMS += \
    Create_MainWindow.ui \
    DBsetWidget.ui \
    Personal_MainWindow.ui \
    fieldwidget.ui \
    framelessWidget.ui \
    loginUI.ui \
    mgmtinfowidget.ui \
    mgmtsystem.ui \
    tablewidget.ui

TRANSLATIONS += \
    system_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

HEADERS += \
    $$files($$PWD/CusHeaders/*.h)
INCLUDEPATH += $$PWD/CusHeaders

#导入组件库的源文件
SOURCES += \
    $$files($$PWD/SDK/MaterialSDK/components/*.cpp)

#导入组件库的头文件
HEADERS += \
    $$files($$PWD/SDK/MaterialSDK/components/*.h)

#import Material SDK(导入Material组件库的SDK)
LIBS += $$PWD/SDK/MaterialSDK/staticlib/libcomponents.a
INCLUDEPATH += $$PWD/SDK/MaterialSDK/components
PRE_TARGETDEPS += $$PWD/SDK/MaterialSDK/staticlib/libcomponents.a

#subdirs模板告诉qmake生成一个makefile，它可以进入到特定子目录并为这个目录中的项目文件生成makefile并且为它调用make。
SUBDIRS += \
    SDK/MaterialSDK/components/components.pro

