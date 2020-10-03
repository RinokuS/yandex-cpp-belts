#include "Common.h"

using namespace std;

namespace Expressions {
    class Value : public Expression {
    public:
        explicit Value(int value) : value_(value) {}

        int Evaluate() const override {
            return value_;
        }

        string ToString() const override {
            return to_string(value_);
        }

    private:
        int value_;
    };

    class Sum : public Expression{
    public:
        Sum(ExpressionPtr left, ExpressionPtr right) : leftNode(move(left)), rightNode(move(right)){}

        int Evaluate() const override {
            return leftNode->Evaluate() + rightNode->Evaluate();
        }

        string ToString() const override {
            return "(" + leftNode->ToString() + ")" + "+" + "(" + rightNode->ToString() + ")";
        }
    private:
        ExpressionPtr leftNode;
        ExpressionPtr rightNode;
    };

    class Product : public Expression{
    public:
        Product(ExpressionPtr left, ExpressionPtr right) : leftNode(move(left)), rightNode(move(right)){}

        int Evaluate() const override {
            return leftNode->Evaluate() * rightNode->Evaluate();
        }

        string ToString() const override {
            return "(" + leftNode->ToString() + ")" + "*" + "(" + rightNode->ToString() + ")";
        }
    private:
        ExpressionPtr leftNode;
        ExpressionPtr rightNode;
    };
}

ExpressionPtr Value(int value){
    return std::make_unique<Expressions::Value>(value);
}
ExpressionPtr Sum(ExpressionPtr left, ExpressionPtr right){
    return std::make_unique<Expressions::Sum>(move(left), move(right));
}
ExpressionPtr Product(ExpressionPtr left, ExpressionPtr right){
    return std::make_unique<Expressions::Product>(move(left), move(right));
}
