#include <iostream>
#include "src/Library/Library.hpp"


int main() {
    Library library;
    library.loadFromFile("src/data/books.txt");
std::cout << "-= Welcome to the library! =-\n";
std::cout << "~~~~ Created by F1L3SHK4 ~~~~\n\n";

    int32_t choice;
while (true) {
    //сначала хотел switch-case, но вспомнил, что в Яндексe if-if, +там в обход иницилизация, короче, ШЛЯПА!
    std::cout << "\n============ [MENU] ============\n";
        std::cout << "1. Add book\n2. Remove book\n3. Search by title\n4. Search by author\n5. Exit\nChoose an option: ";
        std::cin >> choice;
        std::cout << std::endl;

        if (choice == 1) {
std::cout << "\n============ [ADDING BOOK] ============\n";
            int32_t id, year;
            std::string title;
            std::cout << "Enter ID: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Enter title: ";
            std::getline(std::cin, title);
            std::cout << "Enter year: ";
            std::cin >> year;
            Book book(id, title, year);

            int32_t authorCount;
            std::cout << "Enter number of authors: ";
            std::cin >> authorCount;
            for (int32_t i = 0; i < authorCount; ++i) {
                std::string lastName, firstName, middleName;
                std::cout << "Enter author " << i + 1 << " (surname, name, middle name): ";
                std::cin >> lastName >> firstName >> middleName;
                book.addAuthor(Author(lastName, firstName, middleName));
            }
            library.addBook(book);
            std::cout << "Book added succesfully!\n";

        } else if (choice == 2) {
            std::cout << "\n============ [REMOVING BOOK] ============\n";
            std::string title;
            std::cout << "Enter title of the book to remove: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            library.removeBook(title);
            std::cout << "Book removed succesfully!\n";
        } else if (choice == 3) {
            std::cout << "\n============ [SEARCHING BY TITLE] ============\n";
            std::string title;
            std::cout << "Enter title: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            Book* book = library.searchByTitle(title);
            if (book) {
                std::cout << "Book found: " << book->getTitle() << " (" << book->getYear() << ")\n";
            } else {
                std::cout << "Book not found...\n";
            }
        } else if (choice == 4) {
            std::cout << "\n============ [SEARCHING BY AUTHOR] ============\n";
            std::string lastName, firstName, middleName;
            std::cout << "Enter author's surname: ";
            std::cin >> lastName;
            std::cout << "Enter author's name: ";
            std::cin >> firstName;
            std::cout << "Enter author's middle name: ";
            std::cin >> middleName;
            Author author(lastName, firstName, middleName);
            std::vector<Book> books = library.searchByAuthor(author);
            std::cout << "Books by " << lastName << ": \n";
            for (const auto &book : books) {
                std::cout << book.getTitle() << " (" << book.getYear() << ")\n";
            }
        } else if (choice == 5) {
            std::cout << "\n============ [GOODBYE!] ============\n";
            break;
        }
    }

    return 0;
}