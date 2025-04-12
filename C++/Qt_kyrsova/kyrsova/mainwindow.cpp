#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include <QIcon>
#include <QPixmap>
#include "Book.h"
#include "BookStore.h"

// Конструктор окна
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); // Настройка интерфейса
    setWindowTitle("Информация о книгах");
    QPixmap pix(":/book/image/book1.png");
    QPixmap pix2(":/book2/image/book2.jpg");
    setWindowIcon(QIcon(":/icon/image/icon.jpg"));

    ui->image1->setPixmap(pix.scaled(200, 200, Qt::KeepAspectRatio));


}

// Деструктор окна
MainWindow::~MainWindow()
{
    delete ui; // Удаляем интерфейс
}

// Слот для обработки нажатия на кнопку
void MainWindow::on_pushButton_clicked()
{
    // Получение данных из текстовых полей интерфейса
    QString title = ui->title->text();    // Название книги
    QString author = ui->author->text();  // Автор книги
    QString year = ui->year->text();      // Год издания
    QString price = ui->price->text();    // Цена книги

    // Проверка на пустые значения
    if (title.isEmpty() || author.isEmpty() || year.isEmpty() || price.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, заполните все поля."); // Сообщение об ошибке
        ui->statusBar->showMessage("ошибка в вводе значений");
        return; // Прерываем выполнение, если есть пустые поля
    }

    // Проверка: является ли год корректным целым числом
    bool isYearInt; // Переменная для хранения результата проверки
    int bookYear = year.toInt(&isYearInt); // Преобразуем строку в int
    if (!isYearInt || bookYear <= 0) { // Если год не число или меньше/равен нулю
        QMessageBox::warning(this, "Ошибка", "Введите корректный год (целое число больше нуля)."); // Сообщение об ошибке
        ui->statusBar->showMessage("ошибка в вводе значений");
        return; // Прерываем выполнение
    }

    // Проверка: является ли цена корректным числом с плавающей точкой
    bool isPriceDouble; // Переменная для хранения результата проверки
    double bookPrice = price.toDouble(&isPriceDouble); // Преобразуем строку в double
    if (!isPriceDouble || bookPrice <= 0.0) { // Если цена не число или меньше/равна нулю
        QMessageBox::warning(this, "Ошибка", "Введите корректную цену (положительное число)."); // Сообщение об ошибке
        ui->statusBar->showMessage("ошибка в вводе значений");
        return; // Прерываем выполнение
    }

    // Преобразование строк из Qt в стандартные строки C++ для передачи в BookStore
    std::string bookTitle = title.toStdString(); // Преобразуем QString в std::string
    std::string bookAuthor = author.toStdString(); // Преобразуем QString в std::string

    // Создание объекта BookStore с введёнными данными
    BookStore bookStore(bookTitle, bookAuthor, bookYear, bookPrice);

    // Преобразуем информацию из BookStore в QString и устанавливаем её на label
    ui->label->setText(QString::fromStdString(bookStore.displayBookStoreInfo()));

    ui->statusBar->showMessage("созван объект класс BookStore");
}
