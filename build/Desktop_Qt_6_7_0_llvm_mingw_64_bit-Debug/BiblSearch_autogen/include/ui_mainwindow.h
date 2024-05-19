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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *loginLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameLineEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;
    QLabel *loginStatusLabel;
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
        MainWindow->resize(1056, 765);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        loginLayout = new QGridLayout();
        loginLayout->setObjectName("loginLayout");
        usernameLabel = new QLabel(centralwidget);
        usernameLabel->setObjectName("usernameLabel");

        loginLayout->addWidget(usernameLabel, 0, 0, 1, 1);

        usernameLineEdit = new QLineEdit(centralwidget);
        usernameLineEdit->setObjectName("usernameLineEdit");

        loginLayout->addWidget(usernameLineEdit, 0, 1, 1, 1);

        passwordLabel = new QLabel(centralwidget);
        passwordLabel->setObjectName("passwordLabel");

        loginLayout->addWidget(passwordLabel, 1, 0, 1, 1);

        passwordLineEdit = new QLineEdit(centralwidget);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        loginLayout->addWidget(passwordLineEdit, 1, 1, 1, 1);

        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName("loginButton");

        loginLayout->addWidget(loginButton, 2, 1, 1, 1);

        loginStatusLabel = new QLabel(centralwidget);
        loginStatusLabel->setObjectName("loginStatusLabel");

        loginLayout->addWidget(loginStatusLabel, 3, 1, 1, 1);


        verticalLayout->addLayout(loginLayout);

        addBookButton = new QPushButton(centralwidget);
        addBookButton->setObjectName("addBookButton");

        verticalLayout->addWidget(addBookButton);

        editBookButton = new QPushButton(centralwidget);
        editBookButton->setObjectName("editBookButton");

        verticalLayout->addWidget(editBookButton);

        deleteBookButton = new QPushButton(centralwidget);
        deleteBookButton->setObjectName("deleteBookButton");

        verticalLayout->addWidget(deleteBookButton);

        addUserButton = new QPushButton(centralwidget);
        addUserButton->setObjectName("addUserButton");

        verticalLayout->addWidget(addUserButton);

        editUserButton = new QPushButton(centralwidget);
        editUserButton->setObjectName("editUserButton");

        verticalLayout->addWidget(editUserButton);

        deleteUserButton = new QPushButton(centralwidget);
        deleteUserButton->setObjectName("deleteUserButton");

        verticalLayout->addWidget(deleteUserButton);

        issueBookButton = new QPushButton(centralwidget);
        issueBookButton->setObjectName("issueBookButton");

        verticalLayout->addWidget(issueBookButton);

        returnBookButton = new QPushButton(centralwidget);
        returnBookButton->setObjectName("returnBookButton");

        verticalLayout->addWidget(returnBookButton);

        generateReportButton = new QPushButton(centralwidget);
        generateReportButton->setObjectName("generateReportButton");

        verticalLayout->addWidget(generateReportButton);

        bookTableView = new QTableView(centralwidget);
        bookTableView->setObjectName("bookTableView");

        verticalLayout->addWidget(bookTableView);

        userTableView = new QTableView(centralwidget);
        userTableView->setObjectName("userTableView");

        verticalLayout->addWidget(userTableView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1056, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "BiblSearch", nullptr));
        usernameLabel->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217:", nullptr));
        passwordLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        addBookButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\275\320\270\320\263\321\203", nullptr));
        editBookButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\272\320\275\320\270\320\263\321\203", nullptr));
        deleteBookButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\272\320\275\320\270\320\263\321\203", nullptr));
        addUserButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        editUserButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        deleteUserButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        issueBookButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\264\320\260\321\202\321\214 \320\272\320\275\320\270\320\263\321\203", nullptr));
        returnBookButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214 \320\272\320\275\320\270\320\263\321\203", nullptr));
        generateReportButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\276\321\202\321\207\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
