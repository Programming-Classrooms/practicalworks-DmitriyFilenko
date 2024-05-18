#include "src/Book/Book.hpp"
#include "src/Library/Library.hpp"
#include <stdexcept>
#include <gtest/gtest.h>


TEST(testCase, testName) 
{
    EXPECT_EQ(1, 1);
}

// Тест для класса Book
TEST(BookTest, CreateBook) {
    Book book("7121", "Язык программирования C++", 29.99, 10);
    EXPECT_EQ(book.getISBN(), "7121");
    EXPECT_EQ(book.getTitle(), "Язык программирования C++");
    EXPECT_DOUBLE_EQ(book.getPrice(), 29.99);
    EXPECT_EQ(book.getCount(), 10);
    EXPECT_TRUE(book.getAuthors().empty());
}

TEST(BookTest, AddAndRemoveAuthors) {
    Book book("7121", "Язык программирования C++", 29.99, 10);
    book.addAuthor("Бёрн Страуструп");
    book.addAuthor("Какойто Мужичок");
    EXPECT_EQ(book.getAuthors().size(), 2);
    EXPECT_EQ(book.getAuthors()[0], "Бёрн Страуструп");
    EXPECT_EQ(book.getAuthors()[1], "Какойто Мужичок");

    book.removeAuthor("Бёрн Страуструп");
    EXPECT_EQ(book.getAuthors().size(), 1);
    EXPECT_EQ(book.getAuthors()[0], "Какойто Мужичок");
}

// Тест для класса Library
TEST(LibraryTest, AddAndFindBook) {
    Library library;
    Book book("7121", "Язык программирования C++", 29.99, 10);
    library.addBook(book);

    Book* foundBook = library.findBook("7121");
    ASSERT_NE(foundBook, nullptr);
    EXPECT_EQ(foundBook->getISBN(), "7121");
}

TEST(LibraryTest, RemoveBook) {
    Library library;
    Book book("7121", "Язык программирования C++", 29.99, 10);
    library.addBook(book);
    library.removeBook("7121");

    Book* foundBook = library.findBook("7121");
    EXPECT_EQ(foundBook, nullptr);
}

TEST(LibraryTest, AddAndRemoveAuthor) {
    Library library;
    Book book("7121", "Язык программирования C++", 29.99, 10);
    library.addBook(book);
    library.addAuthor("7121", "Бёрн Страуструп");

    Book* foundBook = library.findBook("7121");
    ASSERT_NE(foundBook, nullptr);
    EXPECT_EQ(foundBook->getAuthors().size(), 1);
    EXPECT_EQ(foundBook->getAuthors()[0], "Бёрн Страуструп");

    library.removeAuthor("7121", "Бёрн Страуструп");
    EXPECT_EQ(foundBook->getAuthors().size(), 0);
}

TEST(LibraryTest, SortBooksByISBN) {
    Library library;
    Book book1("7111", "Эффективный и современный С++", 35.50, 5);
    Book book2("7121", "Язык программирования C++", 29.99, 10);
    library.addBook(book1);
    library.addBook(book2);

    library.sortByISBN();

    auto books = library.findBook("7121");
    ASSERT_NE(books, nullptr);
    EXPECT_EQ(books->getISBN(), "7121");

    books = library.findBook("7111");
    ASSERT_NE(books, nullptr);
    EXPECT_EQ(books->getISBN(), "7111");
}

TEST(LibraryTest, SortBooksByTitle) {
    Library library;
    Book book1("7111", "Эффективный и современный С++", 35.50, 5);
    Book book2("7121", "Язык программирования C++", 29.99, 10);
    library.addBook(book1);
    library.addBook(book2);

    library.sortByTitle();

    auto books = library.findBook("7121");
    ASSERT_NE(books, nullptr);
    EXPECT_EQ(books->getTitle(), "Язык программирования C++");

    books = library.findBook("7111");
    ASSERT_NE(books, nullptr);
    EXPECT_EQ(books->getTitle(), "Эффективный и современный С++");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
