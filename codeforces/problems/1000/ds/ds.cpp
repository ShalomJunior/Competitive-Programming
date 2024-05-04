#include<bits/stdc++.h>


int main() {
    std::unordered_multiset<int> multiset = { 45, 2, 16, -7 , 5, 74 };
    std::cout << "Before swap: ";
    for (int x : multiset) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Swap 2 and 5
    auto it_2 = multiset.find(2);
    auto it_5 = multiset.find(5);
    if (it_2 != multiset.end() && it_5 != multiset.end()) {
        std::iter_swap(it_2, it_5);
    }

    std::cout << "After swap: ";
    for (int x : multiset) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
