#include <iostream>
#include <vector>
using namespace std;

class FunctionPart{
public:
    FunctionPart(char operation, double value){
        this->operation = operation;
        this->value = value;
    }
    double Apply(double val) const{
        if (operation == '+'){
            return val + value;
        } else{
            return val - value;
        }
    }
    void Invert(){
        if (operation == '+'){
            operation = '-';
        } else{
            operation = '+';
        }
    }
private:
    char operation;
    double value;
};

class Function{
public:
    void AddPart(char operation, double value){
        parts.push_back(FunctionPart({operation, value}));
    }
    double Apply(double value) const{
        for (const FunctionPart& part: parts) {
            value = part.Apply(value);
        }
        return value;
    }
    void Invert(){
        for(FunctionPart& part: parts){
            part.Invert();
        }
        reverse(begin(parts), end(parts));
    }
private:
    vector<FunctionPart> parts;
};
