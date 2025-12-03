#pragma once
#include <string>
#include "Author.h"

class Book {
private:
    std::string bookTitle;
    Author bookAuthor;
    int publishYear;
    double bookPrice;
    std::string bookIsbn;

public:
    static int totalBooks;

    Book()
        : bookTitle("Untitled"), bookAuthor(), publishYear(1900),
          bookPrice(0.0), bookIsbn("NONE")
    {
        totalBooks++;
    }

    Book(const std::string& t, const Author& a, int y, double p, const std::string& i)
        : bookTitle(t), bookAuthor(a), bookIsbn(i)
    {
        publishYear = (y < 1450 ? 1450 : (y > 2025 ? 2025 : y));
        bookPrice = (p < 0 ? 0.0 : p);
        totalBooks++;
    }

    Book(const Book& other)
        : bookTitle(other.bookTitle), bookAuthor(other.bookAuthor),
          publishYear(other.publishYear), bookPrice(other.bookPrice),
          bookIsbn(other.bookIsbn)
    {
        totalBooks++;
    }

    Book(Book&& other) noexcept
        : bookTitle(std::move(other.bookTitle)),
          bookAuthor(std::move(other.bookAuthor)),
          publishYear(other.publishYear),
          bookPrice(other.bookPrice),
          bookIsbn(std::move(other.bookIsbn))
    {
        totalBooks++;
    }

    Book& operator=(const Book& other) {
        if(this != &other) {
            bookTitle   = other.bookTitle;
            bookAuthor  = other.bookAuthor;
            publishYear = other.publishYear;
            bookPrice   = other.bookPrice;
            bookIsbn    = other.bookIsbn;
        }
        return *this;
    }

    Book& operator=(Book&& other) noexcept {
        if(this != &other) {
            bookTitle   = std::move(other.bookTitle);
            bookAuthor  = std::move(other.bookAuthor);
            publishYear = other.publishYear;
            bookPrice   = other.bookPrice;
            bookIsbn    = std::move(other.bookIsbn);
        }
        return *this;
    }

    ~Book() { totalBooks--; }

    std::string to_string() const {
        return bookTitle + " | " + bookAuthor.to_string() + " | " +
               std::to_string(publishYear) + " | " +
               std::to_string(bookPrice) + " BGN | " + bookIsbn;
    }

    std::string getISBN() const { return bookIsbn; }
    std::string getAuthorName() const { return bookAuthor.getName(); }
};

int Book::totalBooks = 0;
