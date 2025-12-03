#pragma once
#include <vector>
#include <string>
#include "Book.h"
#include "Member.h"
#include "Loan.h"

class Library {
private:
    std::vector<Book> bookList;
    std::vector<Member> userList;
    std::vector<Loan> loanRecords;

public:
    void addBook(const Book& b) {
        bookList.push_back(b);
    }

    void addMember(const Member& m) {
        if(m.isValid())
            userList.push_back(m);
    }

    bool hasBook(const std::string& isbn) const {
        for(const auto& b : bookList)
            if(b.getISBN() == isbn)
                return true;
        return false;
    }

    bool isBookAvailable(const std::string& isbn) const {
        for(const auto& l : loanRecords)
            if(l.getISBN() == isbn && !l.isReturned())
                return false;
        return true;
    }

    bool loanBook(const std::string& isbn, const std::string& memberId,
                  const std::string& start, const std::string& due)
    {
        if(!hasBook(isbn)) return false;
        if(!isBookAvailable(isbn)) return false;

        loanRecords.emplace_back(isbn, memberId, start, due);
        return true;
    }

    bool returnBook(const std::string& isbn, const std::string& memberId) {
        for(auto& l : loanRecords) {
            if(l.getISBN() == isbn && l.getMemberID() == memberId && !l.isReturned()) {
                l.markReturned();
                return true;
            }
        }
        return false;
    }

    std::vector<Book> findByAuthor(const std::string& authorName) const {
        std::vector<Book> result;
        for(const auto& b : bookList)
            if(b.getAuthorName().find(authorName) != std::string::npos)
                result.push_back(b);
        return result;
    }

    std::string to_string() const {
        return "Books: " + std::to_string(bookList.size()) +
               ", Members: " + std::to_string(userList.size()) +
               ", Loans: " + std::to_string(loanRecords.size());
    }
};
