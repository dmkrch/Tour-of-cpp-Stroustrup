#include <vector>
#include <iostream>


int main() {
    std::vector<int> v1 {25, 26, 15, 19};
    std::vector<int> v2 {28, -24, 11, 11};

    std::copy(v1.begin(), v1.end(), v2.begin());

    for (const auto& elem : v2)
        std::cout << elem << " ";

    return 0;
}