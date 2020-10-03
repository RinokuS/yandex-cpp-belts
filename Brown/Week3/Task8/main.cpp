#include "test_runner.h"
#include <functional>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;


struct Email {
    string from;
    string to;
    string body;
};

istream& operator>>(istream& input, Email& email){
    getline(input, email.from);
    getline(input, email.to);
    getline(input, email.body);

    return input;
}

ostream& operator<<(ostream& output, Email& email){
    output << email.from << '\n';
    output << email.to << '\n';
    output << email.body << '\n';

    return output;
}


class Worker {
public:
    virtual ~Worker() = default;
    virtual void Process(unique_ptr<Email> email) = 0;
    virtual void Run() {
        // С‚РѕР»СЊРєРѕ РїРµСЂРІРѕРјСѓ worker-Сѓ РІ РїР°Р№РїР»Р°Р№РЅРµ РЅСѓР¶РЅРѕ СЌС‚Рѕ РёРјРїР»РµРјРµРЅС‚РёСЂРѕРІР°С‚СЊ
        throw logic_error("Unimplemented");
    }

protected:
    // СЂРµР°Р»РёР·Р°С†РёРё РґРѕР»Р¶РЅС‹ РІС‹Р·С‹РІР°С‚СЊ PassOn, С‡С‚РѕР±С‹ РїРµСЂРµРґР°С‚СЊ РѕР±СЉРµРєС‚ РґР°Р»СЊС€Рµ
    // РїРѕ С†РµРїРѕС‡РєРµ РѕР±СЂР°Р±РѕС‚С‡РёРєРѕРІ
    void PassOn(unique_ptr<Email> email) const{
        if (next_)
            next_->Process(move(email));
    }

public:
    void SetNext(unique_ptr<Worker> next){
        if (!next_){
            next_ = move(next);
        } else{
            next_->SetNext(move(next));
        }
    }

private:
    unique_ptr<Worker> next_ = nullptr;
};


class Reader : public Worker {
public:
    Reader(istream& input){
        Email mail;
        while(input >> mail){
            mails_.emplace_back(make_unique<Email>(move(mail)));
        }
    }

    void Run() override{
        for(auto& mail: mails_){
            PassOn(move(mail));
        }
    }

    void Process(unique_ptr<Email> email) override{
        Run();
    }
private:
    vector<unique_ptr<Email>> mails_;
};


class Filter : public Worker {
public:
    using Function = function<bool(const Email&)>;
    explicit Filter(Function func) : predicate_(move(func)) {}

    void Process(unique_ptr<Email> email) override{
        if (predicate_(*email)){
            PassOn(move(email));
        }
    }

public:
    Function predicate_;
};


class Copier : public Worker {
public:
    Copier(string address) : address_(move(address)){}

    void Process(unique_ptr<Email> email) override{
        unique_ptr<Email> email_ptr = nullptr;
        if (email->to != address_){
            Email copy = {email->from, address_, email->body};
            email_ptr = make_unique<Email>(move(copy));
        }

        PassOn(move(email));
        if (email_ptr)
            PassOn(move(email_ptr));
    }
private:
    string address_;
};


class Sender : public Worker {
public:
    Sender(ostream& output) : output_(output){}

    void Process(unique_ptr<Email> email) override{
        output_ << *email;
        PassOn(move(email));
    }

private:
    ostream& output_;
};


// СЂРµР°Р»РёР·СѓР№С‚Рµ РєР»Р°СЃСЃ
class PipelineBuilder {
public:
    // РґРѕР±Р°РІР»СЏРµС‚ РІ РєР°С‡РµСЃС‚РІРµ РїРµСЂРІРѕРіРѕ РѕР±СЂР°Р±РѕС‚С‡РёРєР° Reader
    explicit PipelineBuilder(istream& in): pipeline_head_(make_unique<Reader>(in)){}

    // РґРѕР±Р°РІР»СЏРµС‚ РЅРѕРІС‹Р№ РѕР±СЂР°Р±РѕС‚С‡РёРє Filter
    PipelineBuilder& FilterBy(Filter::Function filter){
        pipeline_head_->SetNext(make_unique<Filter>(move(filter)));

        return *this;
    }

    // РґРѕР±Р°РІР»СЏРµС‚ РЅРѕРІС‹Р№ РѕР±СЂР°Р±РѕС‚С‡РёРє Copier
    PipelineBuilder& CopyTo(string recipient){
        pipeline_head_->SetNext(make_unique<Copier>(move(recipient)));

        return *this;
    }

    // РґРѕР±Р°РІР»СЏРµС‚ РЅРѕРІС‹Р№ РѕР±СЂР°Р±РѕС‚С‡РёРє Sender
    PipelineBuilder& Send(ostream& out){
        pipeline_head_->SetNext(make_unique<Sender>(out));

        return *this;
    }

    // РІРѕР·РІСЂР°С‰Р°РµС‚ РіРѕС‚РѕРІСѓСЋ С†РµРїРѕС‡РєСѓ РѕР±СЂР°Р±РѕС‚С‡РёРєРѕРІ
    unique_ptr<Worker> Build(){
        return move(pipeline_head_);
    }

private:
    unique_ptr<Worker> pipeline_head_;
};


void TestSanity() {
    string input = (
            "erich@example.com\n"
            "richard@example.com\n"
            "Hello there\n"

            "erich@example.com\n"
            "ralph@example.com\n"
            "Are you sure you pressed the right button?\n"

            "ralph@example.com\n"
            "erich@example.com\n"
            "I do not make mistakes of that kind\n"
    );
    istringstream inStream(input);
    ostringstream outStream;

    PipelineBuilder builder(inStream);
    builder.FilterBy([](const Email& email) {
        return email.from == "erich@example.com";
    });
    builder.CopyTo("richard@example.com");
    builder.Send(outStream);
    auto pipeline = builder.Build();

    pipeline->Run();

    string expectedOutput = (
            "erich@example.com\n"
            "richard@example.com\n"
            "Hello there\n"

            "erich@example.com\n"
            "ralph@example.com\n"
            "Are you sure you pressed the right button?\n"

            "erich@example.com\n"
            "richard@example.com\n"
            "Are you sure you pressed the right button?\n"
    );

    ASSERT_EQUAL(expectedOutput, outStream.str());
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestSanity);
    return 0;
}