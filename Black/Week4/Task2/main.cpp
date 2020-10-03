#include "test_runner.h"

// EqualsToOneOf(x, "apple", "orange") РѕР·РЅР°С‡Р°РµС‚ (x == "apple" || x == "orange")


template <typename T, typename ... Args>
bool EqualsToOneOf(const T& arg, const Args& ... args){
    bool result = false;
    ((result |= arg == args), ...);

    return result;
}

void Test() {
    auto x = "pear";
    ASSERT(EqualsToOneOf(x, "pear"));
    ASSERT(!EqualsToOneOf(x, "apple"));
    ASSERT(EqualsToOneOf(x, "apple", "pear"));
    ASSERT(!EqualsToOneOf(x, "apple", "banana"));
    ASSERT(EqualsToOneOf(x, "apple", "banana", "pear"));
    ASSERT(!EqualsToOneOf(x, "apple", "banana", "peach"));
    ASSERT(EqualsToOneOf(x, "apple", "banana", "pear", "orange"));
    ASSERT(!EqualsToOneOf(x, "apple", "banana", "peach", "orange"));
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, Test);
    return 0;
}