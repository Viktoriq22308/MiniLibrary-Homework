#pragma once
#include <string>

class Member {
private:
    std::string fullName;
    std::string idCode;
    int joinedYear;

public:
    Member() : fullName("Unknown"), idCode(""), joinedYear(2000) {}
    Member(const std::string& n, const std::string& id, int y)
        : fullName(n), idCode(id), joinedYear(y) {}

    bool isValid() const { return !idCode.empty(); }

    std::string getId() const { return idCode; }

    std::string to_string() const {
        return fullName + " (" + idCode + ") joined " + std::to_string(joinedYear);
    }
};
