#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    std::string from;
    std::string to;
    
    std::cin >> from >> to; // input of source and obj files

    std::ifstream is{from}; // opening input stream
    std::ofstream os{to}; // opening output stream

    std::set<std::string> b {std::istream_iterator<std::string>{is},
                             std::istream_iterator<std::string>{}};

    // copying buffer into output stream
    std::copy(b.begin(), b.end(), std::ostream_iterator<std::string>{os, "\n"});

    return 0;
}