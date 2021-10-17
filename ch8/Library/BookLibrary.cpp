#include "BookLibrary.h"

namespace LibraryTools
{
    bool IsDigit(int a) { return (a >= '0' && a <= '9'); }
    
    bool IsEngSymbol(int a) 
    { 
        return (a >= 'A' && a <= 'Z') 
            || (a >= 'a' && a <= 'z'); 
    }

    bool ISBN::IsValid()
    {
        if (n1 > 0 && n2 > 0 && n3 > 0
            && (IsDigit(x) || IsEngSymbol(x)))
            return true;
    }
    
    Book::Book(ISBN c, std::string t, std::string n, Chrono::Date d, bool g, Genre gr)
            : isbnCode{c}, title{t}, authorName{n}, registrationDate{d},
            IsGiven{g}, genre{gr} {}

    bool operator==(const ISBN& a, const ISBN& b)
    {
        return a.GetN1() == b.GetN1() 
            && a.GetN2() == b.GetN2()
            && a.GetN3() == b.GetN3()
            && a.GetN4() == b.GetN4();
    }
    
    bool operator==(const Book& a, const Book& b)
    {
        return a.GetIsbn() == b.GetIsbn();
    }

    std::ostream& operator<<(std::ostream& os, ISBN i)
    {
        return os << i.GetN1() << "-" << i.GetN2()
            << "-" << i.GetN3() << "-" << i.GetN4();
    }
}