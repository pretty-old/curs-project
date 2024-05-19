#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addBookButton_clicked();
    void on_editBookButton_clicked();
    void on_deleteBookButton_clicked();
    void on_addUserButton_clicked();
    void on_editUserButton_clicked();
    void on_deleteUserButton_clicked();
    void on_issueBookButton_clicked();
    void on_returnBookButton_clicked();
    void on_generateReportButton_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *bookModel;
    QStandardItemModel *userModel;

    void loadBooks();
    void loadUsers();
    void saveBooks();
    void saveUsers();
    void updateBookView();
    void updateUserView();
    void addBook(const QString &title, const QString &author, const QString &genre, int yearPublished, bool available);
    void editBook(int row, const QString &title, const QString &author, const QString &genre, int yearPublished, bool available);
    void deleteBook(int row);
    void addUser(const QString &username, const QString &password, const QString &userType);
    void editUser(int row, const QString &username, const QString &password, const QString &userType);
    void deleteUser(int row);
    void issueBook(int userRow, int bookRow);
    void returnBook(int userRow, int bookRow);
    void generateReport();
};

#endif // MAINWINDOW_H
