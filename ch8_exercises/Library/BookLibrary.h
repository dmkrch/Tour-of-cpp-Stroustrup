#include <iostream>
#include "Chrono.h"

namespace Library
{
    enum class Genre
    {
        fantastics, prose, story,
        biography, novel, adventure,
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
            if (!is_valid())
                throw new Invalid_ISBN();
        }
        
        ISBN() : n1(0), n2(0), n3(0), x('0') {}

        // non modification functions
        int get_n1() const { return n1; }
        int get_n2() const { return n2; }
        int get_n3() const { return n3; }
        char get_n4() const { return x; }


    private:
        int n1;
        int n2;
        int n3;
        char x;
        bool is_valid();
    };


    // class that describes book in library
    class Book
    {
    public:
        class Invalid_Book {};
        Book(ISBN c, std::string t, std::string n, Chrono::Date d, bool g);


        // non modification functions
        ISBN get_isbn() const { return isbn_code; }

    private:
        ISBN isbn_code;
        std::string title;
        std::string author_name;
        Chrono::Date registration_date;
        bool is_given;
    };


    // operators overload
    bool operator==(const ISBN& a, const ISBN& b);
    bool operator==(const Book& a, const Book& b);
    std::ostream& operator<<(std::ostream& os, ISBN i);

    // some useful functions
    bool is_digit(int a);
    bool is_eng_symbol(int a);
}