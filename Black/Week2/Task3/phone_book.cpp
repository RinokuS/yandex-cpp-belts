#include "phone_book.h"
#include "contact.pb.h"

#include <algorithm>

PhoneBook DeserializePhoneBook(std::istream& input){
    PhoneBookSerialize::ContactList contact_list;
    contact_list.ParseFromIstream(&input);
    std::vector<Contact> contacts;
    contacts.reserve(contact_list.contact_size());

    for (const auto& con: contact_list.contact()){
        Contact contact;
        contact.name = con.name();

        if (con.has_birthday()){
            contact.birthday = {con.birthday().year(),
                                con.birthday().month(),
                                con.birthday().day()
            };
        }

        contact.phones.reserve(con.phone_number_size());
        for (const auto& phone: con.phone_number()){
            contact.phones.push_back(phone);
        }

        contacts.push_back(contact);
    }

    return PhoneBook(std::move(contacts));
}

PhoneBook::PhoneBook(std::vector<Contact> contacts) : contacts_(std::move(contacts)) {
    std::sort(contacts_.begin(), contacts_.end(),
              [](const Contact& lhs, const Contact& rhs) {
                  return lhs.name < rhs.name;
              });
}

void PhoneBook::SaveTo(std::ostream &output) const {
    PhoneBookSerialize::ContactList contact_list;

    for(const auto& con: contacts_){
        PhoneBookSerialize::Contact& contact = *contact_list.add_contact();
        contact.set_name(con.name);

        if (con.birthday.has_value()) {
            contact.mutable_birthday()->set_day(con.birthday->day);
            contact.mutable_birthday()->set_month(con.birthday->month);
            contact.mutable_birthday()->set_year(con.birthday->year);
        }

        for(const auto& number: con.phones){
            contact.add_phone_number(number);
        }
    }

    contact_list.SerializeToOstream(&output);
}

PhoneBook::ContactRange PhoneBook::FindByNamePrefix(
        std::string_view name_prefix_view) const {
    std::string name_prefix{name_prefix_view};

    if (name_prefix.empty()) {
        return IteratorRange(contacts_.cbegin(), contacts_.cend());
    }

    constexpr auto func = [](const Contact& con, const std::string& v){
        return con.name < v;
    };

    const auto left_border = std::lower_bound(contacts_.cbegin(),
                                              contacts_.cend(), name_prefix, func);
    name_prefix.back()++;
    const auto right_border = std::lower_bound(left_border,
                                               contacts_.cend(), name_prefix, func);

    return IteratorRange(left_border, right_border);
}
