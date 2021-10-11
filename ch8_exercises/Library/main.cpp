#include "BookLibrary.h"

int main()
{
    try
    {
        Library::ISBN isbn_code{1,2,3,'g'};
        std::string title;
        std::string author;
        Chrono::Date date{1974, Chrono::Month::Aug, 25};
        Library::Genre genre{Library::Genre::adventure};


        Library::Book b1{isbn_code, title, author, date, false, genre};
        std::cout << b1.GetIsbn();
    }
    catch(...)
    {
        std::cout << "general error\n";
    }
    return 0;
}