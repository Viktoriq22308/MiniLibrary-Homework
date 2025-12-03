#pragma once
#include <string>

class Author {
private:
    std::string authorName;
    int bornYear;

public:
    Author() : authorName("Unknown"), bornYear(1900) {}
    explicit Author(const std::string& n, int y) : authorName(n) {
        setBirthYear(y);
    }

    std::string to_string() const {
        return authorName + " (" + std::to_string(bornYear) + ")";
    }

    std::string getName() const { return authorName; }
    int getBirthYear() const { return bornYear; }

    void setBirthYear(int y) {
        int corrected = y;
        if(corrected < 1850) corrected = 1850;
        if(corrected > 2025) corrected = 2025;
        bornYear = corrected;
    }
};
