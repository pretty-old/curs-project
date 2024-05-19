/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *addBookButton;
    QPushButton *editBookButton;
    QPushButton *deleteBookButton;
    QPushButton *addUserButton;
    QPushButton *editUserButton;
    QPushButton *deleteUserButton;
    QPushButton *issueBookButton;
    QPushButton *returnBookButton;
    QPushButton *generateReportButton;
    QTableView *bookTableView;
    QTableView *userTableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        addBookButton = new QPushButton(centralwidget);
        addBookButton->setObjectName("addBookButton");
        addBookButton->setGeometry(QRect(30, 30, 131, 32));
        editBookButton = new QPushButton(centralwidget);
        editBookButton->setObjectName("editBookButton");
        editBookButton->setGeometry(QRect(30, 80, 131, 32));
        deleteBookButton = new QPushButton(centralwidget);
        deleteBookButton->setObjectName("deleteBookButton");
        deleteBookButton->setGeometry(QRect(30, 130, 131, 32));
        addUserButton = new QPushButton(centralwidget);
        addUserButton->setObjectName("addUserButton");
        addUserButton->setGeometry(QRect(30, 180, 131, 32));
        editUserButton = new QPushButton(centralwidget);
        editUserButton->setObjectName("editUserButton");
        editUserButton->setGeometry(QRect(30, 230, 131, 32));
        deleteUserButton = new QPushButton(centralwidget);
        deleteUserButton->setObjectName("deleteUserButton");
        deleteUserButton->setGeometry(QRect(30, 280, 131, 32));
        issueBookButton = new QPushButton(centralwidget);
        issueBookButton->setObjectName("issueBookButton");
        issueBookButton->setGeometry(QRect(30, 330, 131, 32));
        returnBookButton = new QPushButton(centralwidget);
        returnBookButton->setObjectName("returnBookButton");
        returnBookButton->setGeometry(QRect(30, 380, 131, 32));
        generateReportButton = new QPushButton(centralwidget);
        generateReportButton->setObjectName("generateReportButton");
        generateReportButton->setGeometry(QRect(30, 430, 131, 32));
        bookTableView = new QTableView(centralwidget);
        bookTableView->setObjectName("bookTableView");
        bookTableView->setGeometry(QRect(200, 30, 550, 200));
        userTableView = new QTableView(centralwidget);
        userTableView->setObjectName("userTableView");
        userTableView->setGeometry(QRect(200, 250, 550, 200));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addBookButton->setText(QCoreApplication::translate("MainWindow", "Add Book", nullptr));
        editBookButton->setText(QCoreApplication::translate("MainWindow", "Edit Book", nullptr));
        deleteBookButton->setText(QCoreApplication::translate("MainWindow", "Delete Book", nullptr));
        addUserButton->setText(QCoreApplication::translate("MainWindow", "Add User", nullptr));
        editUserButton->setText(QCoreApplication::translate("MainWindow", "Edit User", nullptr));
        deleteUserButton->setText(QCoreApplication::translate("MainWindow", "Delete User", nullptr));
        issueBookButton->setText(QCoreApplication::translate("MainWindow", "Issue Book", nullptr));
        returnBookButton->setText(QCoreApplication::translate("MainWindow", "Return Book", nullptr));
        generateReportButton->setText(QCoreApplication::translate("MainWindow", "Generate Report", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
