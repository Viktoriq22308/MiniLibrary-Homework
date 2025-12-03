#pragma once
#include <string>

class Loan {
private:
    std::string loanIsbn;
    std::string clientId;
    std::string dateStart;
    std::string dateDue;
    bool alreadyReturned;

public:
    Loan(const std::string& i, const std::string& m,
         const std::string& start, const std::string& due)
        : loanIsbn(i), clientId(m), dateStart(start),
          dateDue(due), alreadyReturned(false)
    {
        if(dateDue < dateStart)
            dateDue = dateStart;
    }

    void markReturned() { alreadyReturned = true; }
    bool isReturned() const { return alreadyReturned; }

    bool isOverdue(const std::string& today) const {
        return !alreadyReturned && today > dateDue;
    }

    std::string to_string() const {
        return loanIsbn + " to " + clientId +
               ", returned: " + (alreadyReturned ? "yes" : "no");
    }

    std::string getISBN() const { return loanIsbn; }
    std::string getMemberID() const { return clientId; }
};
