#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QMessageBox>
#include <QJsonArray>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bookModel = new QStandardItemModel(this);
    userModel = new QStandardItemModel(this);
    // Изменяем методы setModel для QTableView
    ui->bookTableView->setModel(bookModel);
    ui->userTableView->setModel(userModel);

    // Создаем UI-элементы для входа
    usernameLineEdit = new QLineEdit;
    passwordLineEdit = new QLineEdit;
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    loginButton = new QPushButton("Войти");
    loginStatusLabel = new QLabel(""); // Надпись для статуса входа
    loginStatusLabel->setStyleSheet("color: green;"); // Зеленый цвет для успешного входа

    // Создаем QGridLayout для размещения UI-элементов
    QGridLayout *loginLayout = new QGridLayout;
    loginLayout->addWidget(new QLabel("Имя пользователя:"), 0, 0);
    loginLayout->addWidget(usernameLineEdit, 0, 1);
    loginLayout->addWidget(new QLabel("Пароль:"), 1, 0);
    loginLayout->addWidget(passwordLineEdit, 1, 1);
    loginLayout->addWidget(loginButton, 2, 0, 1, 2);
    loginLayout->addWidget(loginStatusLabel, 3, 0, 1, 2);

    // Добавляем layout в mainWindow
    QWidget *loginWidget = new QWidget;
    loginWidget->setLayout(loginLayout);

    // Устанавливаем начальное состояние элементов
    setElementsEnabled(false); // Все элементы не активны
    loadBooks();
    loadUsers();

    // Подключаем сигнал к слоту
    connect(loginButton, &QPushButton::clicked, this, &MainWindow::on_loginButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addBookButton_clicked()
{
    bool ok;
    QString title = QInputDialog::getText(this, "Добавить книгу", "Название:", QLineEdit::Normal, "", &ok);
    if (ok && !title.isEmpty()) {
        QString author = QInputDialog::getText(this, "Добавить книгу", "Автор:", QLineEdit::Normal, "", &ok);
        if (ok && !author.isEmpty()) {
            QString genre = QInputDialog::getText(this, "Добавить книгу", "Жанр:", QLineEdit::Normal, "", &ok);
            if (ok && !genre.isEmpty()) {
                bool isOk;
                int yearPublished = QInputDialog::getInt(this, "Добавить книгу", "Год издания:", 1900, 2024, 1, isOk);
                if (isOk) {
                    // Проверяем, является ли пользователь администратором
                    int userRow = ui->userTableView->currentIndex().row();
                    if (userRow >= 0) {
                        if (userModel->item(userRow, 2)->text() == "Администратор") {
                            addBook(title, author, genre, yearPublished, true);
                            saveBooks();
                            updateBookView();
                        } else {
                            QMessageBox::warning(this, "Ошибка доступа", "У вас недостаточно прав для добавления книг.");
                        }
                    }
                }
            }
        }
    }
}

void MainWindow::on_editBookButton_clicked()
{
    int row = ui->bookTableView->currentIndex().row();
    if (row >= 0) {
        QString title = bookModel->item(row, 0)->text();
        QString author = bookModel->item(row, 1)->text();
        QString genre = bookModel->item(row, 2)->text();
        int yearPublished = bookModel->item(row, 3)->text().toInt();
        bool available = bookModel->item(row, 4)->text() == "Доступна";
        bool ok;
        QString newTitle = QInputDialog::getText(this, "Редактировать книгу", "Название:", QLineEdit::Normal, title, &ok);
        if (ok && !newTitle.isEmpty()) {
            QString newAuthor = QInputDialog::getText(this, "Редактировать книгу", "Автор:", QLineEdit::Normal, author, &ok);
            if (ok && !newAuthor.isEmpty()) {
                QString newGenre = QInputDialog::getText(this, "Редактировать книгу", "Жанр:", QLineEdit::Normal, genre, &ok);
                if (ok && !newGenre.isEmpty()) {
                    bool isOk;
                    int newYearPublished = QInputDialog::getInt(this, "Редактировать книгу", "Год издания:", 1900, 2024, 1, isOk);
                    if (isOk) {
                        editBook(row, newTitle, newAuthor, newGenre, newYearPublished, available);
                        saveBooks();
                        updateBookView();
                    }
                }
            }
        }
    }
}

void MainWindow::on_deleteBookButton_clicked()
{
    int row = ui->bookTableView->currentIndex().row();
    if (row >= 0) {
        if (QMessageBox::question(this, "Удаление книги", "Вы уверены, что хотите удалить эту книгу?") == QMessageBox::Yes) {
            deleteBook(row);
            saveBooks();
            updateBookView();
        }
    }
}

void MainWindow::on_addUserButton_clicked()
{
    bool ok;
    QString username = QInputDialog::getText(this, "Добавить пользователя", "Имя пользователя:", QLineEdit::Normal, "", &ok);
    if (ok && !username.isEmpty()) {
        QString password = QInputDialog::getText(this, "Добавить пользователя", "Пароль:", QLineEdit::Password, "", &ok);
        if (ok && !password.isEmpty()) {
            QString userType = QInputDialog::getItem(this, "Добавить пользователя", "Тип пользователя:", QStringList() << "Администратор" << "Пользователь", 0, false, &ok);
            if (ok) {
                addUser(username, password, userType);
                saveUsers();
                updateUserView();
            }
        }
    }
}

void MainWindow::on_editUserButton_clicked()
{
    int row = ui->userTableView->currentIndex().row();
    if (row >= 0) {
        QString username = userModel->item(row, 0)->text();
        QString password = userModel->item(row, 1)->text();
        QString userType = userModel->item(row, 2)->text();
        bool ok;
        QString newUsername = QInputDialog::getText(this, "Редактировать пользователя", "Имя пользователя:", QLineEdit::Normal, username, &ok);
        if (ok && !newUsername.isEmpty()) {
            QString newPassword = QInputDialog::getText(this, "Редактировать пользователя", "Пароль:", QLineEdit::Password, password, &ok);
            if (ok && !newPassword.isEmpty()) {
                QString newUserType = QInputDialog::getItem(this, "Редактировать пользователя", "Тип пользователя:", QStringList() << "Администратор" << "Пользователь", 0, false, &ok);
                if (ok) {
                    editUser(row, newUsername, newPassword, newUserType);
                    saveUsers();
                    updateUserView();
                }
            }
        }
    }
}

void MainWindow::on_deleteUserButton_clicked()
{
    int row = ui->userTableView->currentIndex().row();
    if (row >= 0) {
        if (QMessageBox::question(this, "Удаление пользователя", "Вы уверены, что хотите удалить этого пользователя?") == QMessageBox::Yes) {
            deleteUser(row);
            saveUsers();
            updateUserView();
        }
    }
}

void MainWindow::on_issueBookButton_clicked()
{
    int userRow = ui->userTableView->currentIndex().row();
    if (userRow >= 0) {
        int bookRow = ui->bookTableView->currentIndex().row();
        if (bookRow >= 0) {
            if (bookModel->item(bookRow, 4)->text() == "Доступна") {
                issueBook(userRow, bookRow);
                saveBooks();
                updateBookView();
            } else {
                QMessageBox::warning(this, "Ошибка", "Книга не доступна для выдачи.");
            }
        }
    }
}

void MainWindow::on_returnBookButton_clicked()
{
    int userRow = ui->userTableView->currentIndex().row();
    if (userRow >= 0) {
        int bookRow = ui->bookTableView->currentIndex().row();
        if (bookRow >= 0) {
            if (bookModel->item(bookRow, 4)->text() == "Взята") {
                returnBook(userRow, bookRow);
                saveBooks();
                updateBookView();
            } else {
                QMessageBox::warning(this, "Ошибка", "Книга не взята пользователем.");
            }
        }
    }
}

void MainWindow::on_generateReportButton_clicked()
{
    generateReport();
}

void MainWindow::loadBooks()
{
    QFile file("books.json");
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
        if (jsonDoc.isArray()) {
            QJsonArray jsonArray = jsonDoc.array();
            bookModel->clear();
            bookModel->setHorizontalHeaderLabels(QStringList() << "Название" << "Автор" << "Жанр" << "Год издания" << "Статус" << "Взял");
            for (int i = 0; i < jsonArray.size(); i++) {
                QJsonObject bookObject = jsonArray.at(i).toObject();
                QString title = bookObject.value("title").toString();
                QString author = bookObject.value("author").toString();
                QString genre = bookObject.value("genre").toString();
                int yearPublished = bookObject.value("yearPublished").toInt();
                bool available = bookObject.value("available").toBool();
                QString takenByUser = bookObject.value("takenByUser").toString();
                QList<QStandardItem*> items;
                items.append(new QStandardItem(title));
                items.append(new QStandardItem(author));
                items.append(new QStandardItem(genre));
                items.append(new QStandardItem(QString::number(yearPublished)));
                items.append(new QStandardItem(available ? "Доступна" : "Взята"));
                items.append(new QStandardItem(takenByUser));
                bookModel->appendRow(items);
            }
        }
        file.close();
    }
}

void MainWindow::loadUsers()
{
    QFile file("users.json");
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
        if (jsonDoc.isArray()) {
            QJsonArray jsonArray = jsonDoc.array();
            userModel->clear();
            userModel->setHorizontalHeaderLabels(QStringList() << "Имя пользователя" << "Пароль" << "Тип пользователя");
            for (int i = 0; i < jsonArray.size(); i++) {
                QJsonObject userObject = jsonArray.at(i).toObject();
                QString username = userObject.value("username").toString();
                QString password = userObject.value("password").toString();
                QString userType = userObject.value("userType").toString();
                QList<QStandardItem*> items;
                items.append(new QStandardItem(username));
                items.append(new QStandardItem(password));
                items.append(new QStandardItem(userType));
                userModel->appendRow(items);
            }
        }
        file.close();
    }
}

void MainWindow::saveBooks()
{
    QFile file("books.json");
    if (file.open(QIODevice::WriteOnly)) {
        QJsonArray jsonArray;
        // Исправляем ошибку: берем количество строк из модели, а не из jsonArray
        for (int i = 0; i < bookModel->rowCount(); i++) {
            QJsonObject bookObject;
            bookObject.insert("title", bookModel->item(i, 0)->text());
            bookObject.insert("author", bookModel->item(i, 1)->text());
            bookObject.insert("genre", bookModel->item(i, 2)->text());
            bookObject.insert("yearPublished", bookModel->item(i, 3)->text().toInt());
            bookObject.insert("available", bookModel->item(i, 4)->text() == "Доступна");
            bookObject.insert("takenByUser", bookModel->item(i, 5)->text());
            jsonArray.append(bookObject);
        }
        QJsonDocument jsonDoc(jsonArray);
        file.write(jsonDoc.toJson());
        file.close();
    }
}

void MainWindow::saveUsers()
{
    QFile file("users.json");
    if (file.open(QIODevice::WriteOnly)) {
        QJsonArray jsonArray;
        // Исправляем ошибку: создаем jsonArray из userModel
        for (int i = 0; i < userModel->rowCount(); i++) {
            QJsonObject userObject;
            userObject.insert("username", userModel->item(i, 0)->text());
            userObject.insert("password", userModel->item(i, 1)->text());
            userObject.insert("userType", userModel->item(i, 2)->text());
            jsonArray.append(userObject);
        }
        QJsonDocument jsonDoc(jsonArray);
        file.write(jsonDoc.toJson());
        file.close();
    }
}

void MainWindow::updateBookView()
{
    // Обновляем модель данных
    bookModel->clear();
    bookModel->setHorizontalHeaderLabels(QStringList() << "Название" << "Автор" << "Жанр" << "Год издания" << "Статус" << "Взял");
    for (int i = 0; i < bookModel->rowCount(); i++) {
        QList<QStandardItem*> items;
        items.append(new QStandardItem(bookModel->item(i, 0)->text()));
        items.append(new QStandardItem(bookModel->item(i, 1)->text()));
        items.append(new QStandardItem(bookModel->item(i, 2)->text()));
        items.append(new QStandardItem(QString::number(bookModel->item(i, 3)->text().toInt())));
        items.append(new QStandardItem(bookModel->item(i, 4)->text() == "Доступна" ? "Доступна" : "Взята"));
        items.append(new QStandardItem(bookModel->item(i, 5)->text()));
        bookModel->appendRow(items);
    }
    // Обновляем представление
    ui->bookTableView->resizeColumnsToContents();
    ui->bookTableView->resizeRowsToContents();
}

void MainWindow::updateUserView()
{
    // Обновляем модель данных
    userModel->clear();
    userModel->setHorizontalHeaderLabels(QStringList() << "Имя пользователя" << "Пароль" << "Тип пользователя");
    for (int i = 0; i < userModel->rowCount(); i++) {
        QList<QStandardItem*> items;
        items.append(new QStandardItem(userModel->item(i, 0)->text()));
        items.append(new QStandardItem(userModel->item(i, 1)->text()));
        items.append(new QStandardItem(userModel->item(i, 2)->text()));
        userModel->appendRow(items);
    }
    // Обновляем представление
    ui->userTableView->resizeColumnsToContents();
    ui->userTableView->resizeRowsToContents();
}

void MainWindow::addBook(const QString &title, const QString &author, const QString &genre, int yearPublished, bool available)
{
    QList<QStandardItem*> items;
    items.append(new QStandardItem(title));
    items.append(new QStandardItem(author));
    items.append(new QStandardItem(genre));
    items.append(new QStandardItem(QString::number(yearPublished)));
    items.append(new QStandardItem(available ? "Доступна" : "Взята"));
    items.append(new QStandardItem("")); // takenByUser по умолчанию пустое
    bookModel->appendRow(items);
}

void MainWindow::editBook(int row, const QString &title, const QString &author, const QString &genre, int yearPublished, bool available)
{
    bookModel->setItem(row, 0, new QStandardItem(title));
    bookModel->setItem(row, 1, new QStandardItem(author));
    bookModel->setItem(row, 2, new QStandardItem(genre));
    bookModel->setItem(row, 3, new QStandardItem(QString::number(yearPublished)));
    bookModel->setItem(row, 4, new QStandardItem(available ? "Доступна" : "Взята"));
    // Не трогаем takenByUser, так как при редактировании книга не меняет владельца
}

void MainWindow::deleteBook(int row)
{
    bookModel->removeRow(row);
}

void MainWindow::addUser(const QString &username, const QString &password, const QString &userType)
{
    QList<QStandardItem*> items;
    items.append(new QStandardItem(username));
    items.append(new QStandardItem(password));
    items.append(new QStandardItem(userType));
    userModel->appendRow(items);
}

void MainWindow::editUser(int row, const QString &username, const QString &password, const QString &userType)
{
    userModel->setItem(row, 0, new QStandardItem(username));
    userModel->setItem(row, 1, new QStandardItem(password));
    userModel->setItem(row, 2, new QStandardItem(userType));
}

void MainWindow::deleteUser(int row)
{
    userModel->removeRow(row);
}

void MainWindow::issueBook(int userRow, int bookRow)
{
    QString username = userModel->item(userRow, 0)->text(); // Получаем имя пользователя
    bookModel->setItem(bookRow, 4, new QStandardItem("Взята"));
    bookModel->setItem(bookRow, 5, new QStandardItem(username)); // Устанавливаем takenByUser
}

void MainWindow::returnBook(int userRow, int bookRow)
{
    bookModel->setItem(bookRow, 4, new QStandardItem("Доступна"));
    bookModel->setItem(bookRow, 5, new QStandardItem("")); // Очищаем takenByUser
}

void MainWindow::generateReport()
{
    // Реализуйте генерацию отчета
    QMessageBox::information(this, "Отчет", "Отчет пока не реализован!");
}

// Слот для получения сигнала об успешном входе
void MainWindow::onLoginSuccess(const QString& username)
{
    // Загружаем данные из JSON-файлов (если нужно)
    loadBooks();
    loadUsers();

    // Покажем основное окно (MainWindow)
    show();

    // Закрываем окно входа
    // LoginWindow *loginWindow = qobject_cast<LoginWindow*>(sender());
    // if (loginWindow) {
    //     loginWindow->close();
    // }
}

void MainWindow::on_loginButton_clicked()
{
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();

    if (validateLogin(username, password)) {
        loginStatusLabel->setText("Вход успешен!");
        setElementsEnabled(true); // Все элементы активны
    } else {
        loginStatusLabel->setText("Неверные данные. Попробуйте еще раз.");
    }
}

bool MainWindow::validateLogin(const QString& username, const QString& password)
{
    QFile file("users.json"); // Открываем файл users.json
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
        if (jsonDoc.isArray()) {
            QJsonArray jsonArray = jsonDoc.array();
            for (int i = 0; i < jsonArray.size(); i++) {
                QJsonObject userObject = jsonArray.at(i).toObject();
                QString storedUsername = userObject.value("username").toString();
                QString storedPassword = userObject.value("password").toString();

                if (storedUsername == username && storedPassword == password) {
                    file.close();
                    return true; // Пользователь найден, пароль верный
                }
            }
        }
        file.close();
    }
    return false; // Пользователь не найден или пароль неверный
}

void MainWindow::setElementsEnabled(bool enabled)
{
    ui->addBookButton->setEnabled(enabled);
    ui->editBookButton->setEnabled(enabled);
    ui->deleteBookButton->setEnabled(enabled);
    ui->addUserButton->setEnabled(enabled);
    ui->editUserButton->setEnabled(enabled);
    ui->deleteUserButton->setEnabled(enabled);
    ui->issueBookButton->setEnabled(enabled);
    ui->returnBookButton->setEnabled(enabled);
    ui->generateReportButton->setEnabled(enabled);
    ui->bookTableView->setEnabled(enabled);
    ui->userTableView->setEnabled(enabled);
}
