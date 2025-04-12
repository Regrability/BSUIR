/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *image1;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QLineEdit *title;
    QLabel *label_3;
    QLineEdit *author;
    QLabel *label_4;
    QLineEdit *year;
    QLabel *label_5;
    QLineEdit *price;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(778, 409);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QFont font1;
        font1.setPointSize(12);
        pushButton->setFont(font1);

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        image1 = new QLabel(centralWidget);
        image1->setObjectName(QStringLiteral("image1"));
        image1->setMinimumSize(QSize(200, 0));
        image1->setPixmap(QPixmap(QString::fromUtf8("../image/book1.png")));

        gridLayout->addWidget(image1, 0, 1, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font2;
        font2.setPointSize(14);
        label_2->setFont(font2);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        title = new QLineEdit(centralWidget);
        title->setObjectName(QStringLiteral("title"));
        title->setFont(font2);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, title);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font2);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_3);

        author = new QLineEdit(centralWidget);
        author->setObjectName(QStringLiteral("author"));
        author->setFont(font2);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, author);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font2);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_4);

        year = new QLineEdit(centralWidget);
        year->setObjectName(QStringLiteral("year"));
        year->setFont(font2);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, year);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_5);

        price = new QLineEdit(centralWidget);
        price->setObjectName(QStringLiteral("price"));
        price->setFont(font2);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, price);


        gridLayout->addLayout(formLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 778, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "\320\243\320\267\320\275\320\260\321\202\321\214 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216", 0));
        image1->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", 0));
        label_3->setText(QApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200", 0));
        label_4->setText(QApplication::translate("MainWindow", "\320\223\320\276\320\264 \320\270\320\267\320\264\320\260\320\275\320\270\321\217", 0));
        label_5->setText(QApplication::translate("MainWindow", "\320\246\320\265\320\275\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
