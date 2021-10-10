#include "BookLibrary.h"

int main()
{
    try
    {
        Library::ISBN isbn_code{1,2,3,'g'};
        std::string title;
        std::string author;
        Chrono::Date date{1974, Chrono::Month::Aug, 25};

        Library::Book b1{isbn_code, title, author, date, false};

        std::cout << b1.get_isbn();
    }
    catch(...)
    {
        std::cout << "general error\n";
    }
    return 0;
}