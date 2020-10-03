#pragma once

#include "iterator_range.h"

#include <optional>
#include <string>
#include <string_view>
#include <vector>
#include <iosfwd>

struct Date {
    int year, month, day;
};

struct Contact {
    std::string name;
    std::optional<Date> birthday;
    std::vector<std::string> phones;
};

class PhoneBook {
private:
    std::vector<Contact> contacts_;
public:
    explicit PhoneBook(std::vector<Contact> contacts);

    using ContactRange = IteratorRange<std::vector<Contact>::const_iterator>;
    ContactRange FindByNamePrefix(std::string_view name_prefix) const;

    void SaveTo(std::ostream& output) const;
};

PhoneBook DeserializePhoneBook(std::istream& input);
