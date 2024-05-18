#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Пример использования библиотеки nlohmann/json
    nlohmann::json j = {
        {"pi", 3.141},
        {"happy", true},
        {"name", "Niels"},
        {"nothing", nullptr},
        {"answer", {
                       {"everything", 42}
                   }},
        {"list", {1, 0, 2}},
        {"object", {
                       {"currency", "USD"},
                       {"value", 42.99}
                   }}
    };
}

MainWindow::~MainWindow()
{
    delete ui;
}
