#include "src/Library/Library.hpp"
#include "src/Book/Book.hpp"


int main() {
    Library library;

    // Добавляем книги
    Book book1("7121", "Язык программирования C++", 29.99, 10);
    book1.addAuthor("Бёрн Страуструп");
    library.addBook(book1);

    Book book2("7111", "Эффективный и современный C++", 35.50, 5);
    book2.addAuthor("Скотт Майерс");
    library.addBook(book2);

    // Смотрим список книг
    std::cout << "Список книг:\n";
    library.listBooks();

    // Добавляем автора к книге
    library.addAuthor("7111", "Какойто Мужичок");
    std::cout << "\nСписок книг после добавления автора:\n";
    library.listBooks();

    // Удаляем книгу
    library.removeBook("7121");
    std::cout << "\nСписок книг после удаления книги:\n";
    library.listBooks();

    Book book3("7121", "Эффективный и современный C++", 35.50, 5);
    book3.addAuthor("Скотт Майерс");
    library.addBook(book3);

    // Сортируем книги по идентификационному номеру
    library.sortByISBN();
    std::cout << "\nСписок книг после сортировки по ISBN:\n";
    library.listBooks();

    // Сортируем книги по названию
    library.sortByTitle();
    std::cout << "\nСписок книг после сортировки по названию:\n";
    library.listBooks();

    return 0;
}
