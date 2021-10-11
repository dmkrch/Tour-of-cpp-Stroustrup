#include <iostream>
#include "Chrono.h"

namespace Library
{
    enum class Genre
    {
        fantastics, prose, story,
        biography, novel, adventure,
    };


    class Patron
    {
    public:
        Patron(std::string n, int c, bool p)
            : userName{n}, userCardName{c}, isFeePaid{p} {}
        
        void SetMembershipFee(int n) const { membershipFee = n; }
        bool IsPaidMembership() const { return isFeePaid; }
    private:
        std::string userName;
        int userCardName;
        static int membershipFee;
        bool isFeePaid;
    };


    // class for storing ISBN code in format n-n-n-x,
    // where n - number, x - digit or symbol
    class ISBN
    {
    public:
        class Invalid_ISBN {};

        ISBN(int a ,int b, int c, char d)
            : n1(a), n2(b), n3(c), x(d)
        {
            if (!IsValid())
                throw new Invalid_ISBN();
        }
        
        ISBN() : n1(0), n2(0), n3(0), x('0') {}

        // non modification functions
        int GetN1() const { return n1; }
        int GetN2() const { return n2; }
        int GetN3() const { return n3; }
        char GetN4() const { return x; }


    private:
        int n1;
        int n2;
        int n3;
        char x;
        bool IsValid();
    };


    // class that describes book in library
    class Book
    {
    public:
        class Invalid_Book {};
        Book(ISBN c, std::string t, std::string n,
            Chrono::Date d, bool g, Genre gr);


        // non modification functions
        ISBN GetIsbn() const { return isbnCode; }

    private:
        ISBN isbnCode;
        std::string title;
        std::string authorName;
        Chrono::Date registrationDate;
        bool IsGiven;
        Genre genre;
    };


    // operators overload
    bool operator==(const ISBN& a, const ISBN& b);
    bool operator==(const Book& a, const Book& b);
    std::ostream& operator<<(std::ostream& os, ISBN i);

    // some useful functions
    bool IsDigit(int a);
    bool IsEngSymbol(int a);
}