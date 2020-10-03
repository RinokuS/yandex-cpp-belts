#include <iostream>

using namespace std;

class INotifier{
public:
    void virtual Notify(const string& message) const = 0;
};

class SmsNotifier: public INotifier{
public:
    SmsNotifier(const string& number){
        this->number = number;
    }

    void Notify(const string& message) const override{
        SendSms(number, message);
    }

private:
    string number;
};

class EmailNotifier: public INotifier{
public:
    EmailNotifier(const string& address){
        this->address = address;
    }

    void Notify(const string& message) const override{
        SendEmail(address, message);
    }

private:
    string address;
};

