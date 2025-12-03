# Проект: Мини „Библиотечна система“ (Library System)

## Описание

Проектът „Библиотечна система“ представлява малка C++ система, която моделира работа с книги, автори, читатели и заеми чрез пет взаимосвързани класа — **Author**, **Book**, **Member**, **Loan** и **Library**.  
Този README е създаден заедно с `main.cpp`, който демонстрира основните функционалности на системата.

Системата показва:

* добавяне на книги и членове;
* създаване на заем и проверка за наличност;
* връщане на книги;
* търсене на книги по автор;
* използване на статични членове, `const` методи и валидация на данни.

---

## Структура на проекта

library_homework/
├── Author.h
├── Book.h
├── Member.h
├── Loan.h
├── Library.h
├── main.cpp
└── README.md


---

## Компилация и изпълнение

Отворете терминал в директорията на проекта и изпълнете:

g++ -std=gnu++17 -Wall -Wextra -O2 -o library main.cpp
.\library


---

## Класове

### Author

**Полета:**
- `std::string authorName`
- `int bornYear`

**Методи:**
- `Author()`
- `Author(const std::string&, int)`
- `std::string to_string() const`
- `std::string getName() const`
- `int getBirthYear() const`
- `void setBirthYear(int)` – валидация (1850–2025)

---

### Book

**Полета:**
- `std::string bookTitle`
- `Author bookAuthor`
- `int publishYear`
- `double bookPrice`
- `std::string bookIsbn`
- `static int totalBooks`

**Методи:**
- конструктор по подразбиране
- параметризиран конструктор
- копиращ и преместващ конструктор
- деструктор
- `std::string to_string() const`
- `std::string getISBN() const`
- `std::string getAuthorName() const`

**Валидации:**
- година: 1450–2025  
- цена: >= 0

---

### Member

**Полета:**
- `std::string fullName`
- `std::string idCode`
- `int joinedYear`

**Методи:**
- `bool isValid() const`
- `std::string getId() const`
- `std::string to_string() const`

---

### Loan

**Полета:**
- `std::string loanIsbn`
- `std::string clientId`
- `std::string dateStart`
- `std::string dateDue`
- `bool alreadyReturned`

**Методи:**
- `Loan(...)`
- `void markReturned()`
- `bool isReturned() const`
- `bool isOverdue(const std::string&) const`
- `std::string to_string() const`
- `std::string getISBN() const`
- `std::string getMemberID() const`

---

### Library

**Полета:**
- `std::vector<Book> bookList`
- `std::vector<Member> userList`
- `std::vector<Loan> loanRecords`

**Методи:**
- `void addBook(const Book&)`
- `void addMember(const Member&)`
- `bool hasBook(const std::string&) const`
- `bool isBookAvailable(const std::string&) const`
- `bool loanBook(const std::string&, const std::string&, const std::string&, const std::string&)`
- `bool returnBook(const std::string&, const std::string&)`
- `std::vector<Book> findByAuthor(const std::string&) const`
- `std::string to_string() const`

---

## main.cpp (демонстрация)

```cpp
#include <iostream>
#include "Library.h"
#include "Author.h"
#include "Book.h"
#include "Member.h"

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
---
## ПРИМЕРЕН ИЗХОД
```cpp
Books: 2, Members: 1, Loans: 0
Loan is created.
Available ISBN-001? false
Available ISBN-001? true
Crime and punishment | Fyodor Dostoevski (1850) | 1866 | 30.700000 BGN | ISBN-001
White nights | Fyodor Dostoevski (1850) | 1880 | 10.990000 BGN | ISBN-002
PS C:\Users\PC\Desktop\22308\c++\22308 Homework> 

---
## ЕКРАННА СНИМКА:
<img width="1911" height="1012" alt="output" src="https://github.com/user-attachments/assets/986c3b0c-a0db-44b8-ba8c-f65d94f1d285" />


## Автор

* Име: ИВЕЛИН БОРИСЛАВОВ РАЙНОВСКИ
* Номер: 22315
* Курс: Обектно-ориентирано програмиране (C++)
* Дата: 12/2/2025









