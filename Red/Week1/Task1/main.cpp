#include <iostream>
#include <algorithm>

using namespace std;

template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator max_element_if(
        ForwardIterator first, ForwardIterator last, UnaryPredicate pred){
    ForwardIterator findIter = find_if(first, last, pred);

    for(auto curr = findIter; curr != last; curr++){
        if (curr != last && pred(*curr) && *curr > *findIter){
            findIter = curr;
        }
    }

    return findIter;
}

int main() {

    return 0;
}
