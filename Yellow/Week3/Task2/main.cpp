#include <iostream>
#include "phone_number.h"

PhoneNumber::PhoneNumber(const string &international_number) {
    if (international_number[0] == '+'){
        int counter = 0;
        bool done = false;

        for (int i = 1; i <  international_number.size(); ++i) {
            if (international_number[i] != '-' || counter == 2){
                if (counter == 0){
                    country_code_ += international_number[i];
                } else if (counter == 1){
                    city_code_ += international_number[i];
                } else {
                    local_number_ += international_number[i];
                    done = true;
                }
            } else {
                counter++;
            }
        }

        if (!done){
            throw invalid_argument("Something went wrong");
        }
    } else{
        throw invalid_argument("First char should be '+'");
    }
}

string PhoneNumber::GetCountryCode() const {
    return country_code_;
}

string PhoneNumber::GetCityCode() const {
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    return '+' + country_code_ + '-' + city_code_ + '-' + local_number_;
}
