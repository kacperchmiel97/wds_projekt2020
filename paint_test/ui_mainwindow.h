/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout;
    QFrame *gridFrame1;
    QGridLayout *gridLayout_2;
    QWidget *widget1;
    QFrame *gridFrame2;
    QGridLayout *gridLayout_3;
    QFrame *gridFrame3;
    QGridLayout *gridLayout_4;
    QFrame *gridFrame4;
    QGridLayout *gridLayout_5;
    QSlider *verticalSlider;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 800);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAutoFillBackground(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridFrame1 = new QFrame(centralwidget);
        gridFrame1->setObjectName(QString::fromUtf8("gridFrame1"));
        gridFrame1->setFrameShape(QFrame::Box);
        gridFrame1->setLineWidth(1);
        gridLayout_2 = new QGridLayout(gridFrame1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget1 = new QWidget(gridFrame1);
        widget1->setObjectName(QString::fromUtf8("widget1"));

        gridLayout_2->addWidget(widget1, 0, 0, 1, 1);


        gridLayout->addWidget(gridFrame1, 1, 0, 1, 1);

        gridFrame2 = new QFrame(centralwidget);
        gridFrame2->setObjectName(QString::fromUtf8("gridFrame2"));
        gridFrame2->setFrameShape(QFrame::Box);
        gridLayout_3 = new QGridLayout(gridFrame2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));

        gridLayout->addWidget(gridFrame2, 1, 1, 1, 1);

        gridFrame3 = new QFrame(centralwidget);
        gridFrame3->setObjectName(QString::fromUtf8("gridFrame3"));
        gridFrame3->setFrameShape(QFrame::Box);
        gridLayout_4 = new QGridLayout(gridFrame3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));

        gridLayout->addWidget(gridFrame3, 2, 0, 1, 1);

        gridFrame4 = new QFrame(centralwidget);
        gridFrame4->setObjectName(QString::fromUtf8("gridFrame4"));
        gridFrame4->setFrameShape(QFrame::Box);
        gridLayout_5 = new QGridLayout(gridFrame4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));

        gridLayout->addWidget(gridFrame4, 2, 1, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);

        verticalSlider = new QSlider(centralwidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setOrientation(Qt::Vertical);

        horizontalLayout_3->addWidget(verticalSlider);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
