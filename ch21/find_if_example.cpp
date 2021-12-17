#include <iostream>
#include <vector>
#include <algorithm>

class My_Predicate {
private:
    int v;
public:
    My_Predicate(int numb) : v{numb} {}
    bool operator()(int x) const { return x > v; }
};


bool isNegative(int x) {
    return x < 0;
}



int main() {
    std::vector<int> numbArr{20,-24,40};
    numbArr.push_back(20);

    auto elemIt = std::find_if(numbArr.begin(), numbArr.end(), My_Predicate(25));
    auto elemIt1 = std::find_if(numbArr.begin(), numbArr.end(), My_Predicate(41));

    if (elemIt != numbArr.end()) {
        // so we found it
        std::cout << *elemIt << std::endl;
    }
    else {
        std::cout << "no such element" << std::endl;
    }   

    return 0;
}