#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::string from;
    std::string to;
    
    std::cin >> from >> to; // input of source and obj files

    std::ifstream is{from}; // opening input stream
    std::ofstream os{to}; // opening output stream

    std::istream_iterator<std::string> ii{is}; // creating input iterator
    std::istream_iterator<std::string> eos; // input terminator
    std::ostream_iterator<std::string> oo{os, "\n"}; // creating output iterator

    std::vector<std::string> b{ii, eos}; // vector is initialized by input stream
    std::sort(b.begin(), b.end()); // sorting buffer
    std::copy(b.begin(), b.end(), oo);  // copying buffer to output stream

    return 0;
}