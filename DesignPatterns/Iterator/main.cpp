#include "iterator.h"

int main() {
    Container<int> contr_;
    for (int i = 0; i < 10; i++) {
        contr_.add(i);
    }
    auto* iter = contr_.CreateIterator();

    for (iter->first(); !iter->is_end(); iter->operator++()) {
        std::cout << *(iter->current()) << "\n";
    }
}