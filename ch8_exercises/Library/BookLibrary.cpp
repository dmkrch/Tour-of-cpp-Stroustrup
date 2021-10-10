#include "BookLibrary.h"

namespace Library
{
    bool is_digit(int a) { return (a >= '0' && a <= '9'); }
    
    bool is_eng_symbol(int a) 
    { 
        return (a >= 'A' && a <= 'Z') 
            || (a >= 'a' && a <= 'z'); 
    }

    bool ISBN::is_valid()
    {
        if (n1 > 0 && n2 > 0 && n3 > 0
            && (is_digit(x) || is_eng_symbol(x)))
            return true;
    }
    
    Book::Book(ISBN c, std::string t, std::string n, Chrono::Date d, bool g)
            : isbn_code{c}, title{t}, author_name{n}, registration_date{d},
            is_given{g} {}

    bool operator==(const ISBN& a, const ISBN& b)
    {
        return a.get_n1() == b.get_n2() 
            && a.get_n2() == b.get_n2()
            && a.get_n3() == b.get_n3()
            && a.get_n4() == b.get_n4();
    }
    
    bool operator==(const Book& a, const Book& b)
    {
        return a.get_isbn() == b.get_isbn();
    }

    std::ostream& operator<<(std::ostream& os, ISBN i)
    {
        return os << i.get_n1() << "-" << i.get_n2()
            << "-" << i.get_n3() << "-" << i.get_n4();
    }
}