#include "node.h"

bool EmptyNode::Evaluate(const Date& date, const string& event) {
    return true;
}

DateComparisonNode::DateComparisonNode(const Comparison &cmp, const Date &date) :
        mComparator(cmp), mDateValue(date) {}

bool DateComparisonNode::Evaluate(const Date &date, const string &event) {
    switch (mComparator) {
        case Comparison::Less : {
            return date < mDateValue;
        }
        case Comparison::LessOrEqual : {
            return date <= mDateValue;
        }
        case Comparison::Greater : {
            return date > mDateValue;
        }
        case Comparison::GreaterOrEqual : {
            return date >= mDateValue;
        }
        case Comparison::Equal : {
            return date == mDateValue;
        }
        case Comparison::NotEqual : {
            return date != mDateValue;
        }
    }
}

EventComparisonNode::EventComparisonNode(const Comparison& cmp, const string& value) :
        mComparator(cmp), mEventValue(value) {}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) {
    switch (mComparator) {
        case Comparison::Less : {
            return event < mEventValue;
        }
        case Comparison::LessOrEqual : {
            return event <= mEventValue;
        }
        case Comparison::Greater : {
            return event > mEventValue;
        }
        case Comparison::GreaterOrEqual : {
            return event >= mEventValue;
        }
        case Comparison::Equal : {
            return event == mEventValue;
        }
        case Comparison::NotEqual : {
            return event != mEventValue;
        }
        default: {
            throw invalid_argument("Unknown comparison :(");
        }
    }
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& operation,
                                           const shared_ptr<Node>& leftNode,
                                           const shared_ptr<Node>& rightNode): mOperation(operation){
    mLeftNode = leftNode;
    mRightNode = rightNode;
}

bool LogicalOperationNode::Evaluate(const Date &date, const string &event){
    switch (mOperation) {
        case LogicalOperation::And : {
            return mLeftNode->Evaluate(date, event) && mRightNode->Evaluate(date, event);
        }
        case LogicalOperation::Or : {
            return mLeftNode->Evaluate(date, event) || mRightNode->Evaluate(date, event);
        }
        default: {
            throw invalid_argument("Unknown operation :(");
        }
    }
}