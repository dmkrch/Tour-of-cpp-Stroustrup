#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <algorithm>


using Line = std::vector<char>; // typedef Line == array of chars

// document - contains list of lines
// so that line[0] - first line of document
// line[1] - second line of document and so on...

template<class InputIterator, class T>
bool match(InputIterator firstIt, InputIterator lastIt, T elem) {
    auto elemIt = elem.begin(); // getting iterator of element

    while(firstIt != lastIt) {
        if (*elemIt != *firstIt)
            return false;
        ++firstIt;
        elemIt++;
    }

    if (firstIt==lastIt)
        return true;
}

class Text_iterator {
    // tracking line and position of symbol in line
    std::list<Line>::iterator ln;
    Line::iterator pos;
public:
    Text_iterator(std::list<Line>::iterator ll, Line::iterator pp) : ln(ll), pos(pp) {}
    // 4 basic operations : *, ++, ==, !=
    char& operator*() { return *pos; }

    Text_iterator& operator++() {
        ++pos;
        if (pos==(*ln).end()) {
            ++ln;
            pos = (*ln).begin();
        }
        return *this;
    }

    Text_iterator find_txt(Text_iterator first, Text_iterator last, const std::string& s) {
        if (s.size()==0) return last; // can't search emtpy line
        
        char first_char = s[0];
        while(true) {
            auto p = std::find(first, last, first_char);
            if (p == last || match(p, last, s)) return p;
            first = ++p;    // searching for next symbol entering
        }
    }

    bool operator==(const Text_iterator& other) const {
        return ln==other.ln && pos==other.pos; 
    }

    bool operator!=(const Text_iterator& other) const {
        return ln != other.ln || pos != other.pos;
    }

    
};



struct Document {
    std::list<Line> line;
    Document() { line.push_back(Line{}); }  

    Text_iterator begin() {
        return Text_iterator(line.begin(), (*line.begin()).begin());
    }

    Text_iterator end() {
        return Text_iterator(line.end(), (*line.end()).end());
    }
};


// std::list.back() and std::vector.back() returns reference to last element. 
// that's why our Document ends with 
std::istream& operator>>(std::istream& is, Document& d) {
    for (char ch; is.get(ch); ) {
        d.line.back().push_back(ch); // adding symbol
        if (ch=='\n')
            d.line.push_back(Line{}); // adding line
    }

    if (d.line.back().size())       // adding empty line if size is > 0
        d.line.push_back(Line{});

    return is;
}



int main() {
    std::string fileName("example.txt");
    std::ifstream ist{fileName};

    Document doc;

    while(ist)
        ist >> doc;
    
    for (auto c : doc)
        std::cout << c;

    return 0;
}