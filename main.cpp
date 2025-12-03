#include <iostream>
#include "Libraly.h"
#include "Author.h"
#include "Book.h"
#include "Member.h"

int main() {
    Library lib;

    Author writer{"Fyodor Dostoevski", 1821};
    Book b1{"Crime and punishment", writer, 1866, 30.70, "ISBN-001"};
    Book b2{"White nights", writer, 1880, 10.99, "ISBN-002"};

    lib.addBook(b1);
    lib.addBook(b2);
    lib.addMember(Member{"viktoriq marqnova ivanova", "M001", 2020});

    std::cout << lib.to_string() << "\n";

    if(lib.loanBook("ISBN-001", "M001", "2025-11-03", "2025-11-17"))
        std::cout << "Loan is created.\n";

    std::cout << "Available ISBN-001? " << std::boolalpha
              << lib.isBookAvailable("ISBN-001") << "\n";

    lib.returnBook("ISBN-001", "M001");

    std::cout << "Available ISBN-001? " << std::boolalpha
              << lib.isBookAvailable("ISBN-001") << "\n";

    for(const auto& bk : lib.findByAuthor("Dostoevski"))
        std::cout << bk.to_string() << "\n";

    return 0;
}
