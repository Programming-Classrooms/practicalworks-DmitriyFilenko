#include <gtest/gtest.h>
#include "src/Author/Author.hpp"
#include "src/Book/Book.hpp"
#include "src/Library/Library.hpp"

TEST(AuthorTest, AuthorCreation) {
    Author author("Loss", "Vlad", "NePomnu");
    EXPECT_EQ(author.getLastName(), "Loss");
    EXPECT_EQ(author.getFirstName(), "Vlad");
    EXPECT_EQ(author.getMiddleName(), "NePomnu");
}

TEST(BookTest, BookCreation) {
    Book book(7101, "Test Book", 2024);
    EXPECT_EQ(book.getID(), 7101);
    EXPECT_EQ(book.getTitle(), "Test Book");
    EXPECT_EQ(book.getYear(), 2024);
}

TEST(BookTest, AddAuthor) {
    Book book(7101, "Test Book", 2024);
    Author author("Loss", "Vlad", "NePomnu");
    book.addAuthor(author);
    auto authors = book.getAuthors();
    EXPECT_EQ(authors.size(), 1);
    EXPECT_EQ(authors[0].getLastName(), "Loss");
}

TEST(LibraryTest, AddAndSearchBook) {
    Library library;
    Book book(7101, "Test Book", 2024);
    library.addBook(book);
    Book* foundBook = library.searchByTitle("Test Book");
    ASSERT_NE(foundBook, nullptr);
    EXPECT_EQ(foundBook->getTitle(), "Test Book");
}

TEST(LibraryTest, RemoveBook) {
    Library library;
    Book book(7101, "Test Book", 2024);
    library.addBook(book);
    library.removeBook("Test Book");
    Book* foundBook = library.searchByTitle("Test Book");
    EXPECT_EQ(foundBook, nullptr);
}

TEST(LibraryTest, SearchByAuthor) {
    Library library;
    Book book1(7101, "Test Book 1", 2024);
    Author author("Loss", "Vlad", "NePomnu");
    book1.addAuthor(author);
    library.addBook(book1);

    Book book2(7111, "Test Book 2", 2024);
    book2.addAuthor(author);
    library.addBook(book2);

    auto books = library.searchByAuthor(author);
    EXPECT_EQ(books.size(), 2);
    EXPECT_EQ(books[0].getTitle(), "Test Book 1");
    EXPECT_EQ(books[1].getTitle(), "Test Book 2");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
