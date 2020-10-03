#include <string>
#include <memory>

#include "date.h"
#include "token.h"

#pragma once

using namespace std;

class Node {
public:
    virtual bool Evaluate(const Date &, const string &) = 0;
};

class EmptyNode : public Node {
public:
    bool Evaluate(const Date &, const string &) override;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(const Comparison &, const Date &);

    bool Evaluate(const Date &, const string &) override;

private:
    const Comparison mComparator;
    const Date mDateValue;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(const Comparison &, const string &);

    bool Evaluate(const Date &, const string &) override;

private:
    const Comparison mComparator;
    const string mEventValue;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(const LogicalOperation&, const shared_ptr<Node>&, const shared_ptr<Node>&);

    bool Evaluate(const Date&, const string&) override;

private:
    const LogicalOperation mOperation;
    shared_ptr<Node> mLeftNode;
    shared_ptr<Node> mRightNode;

};