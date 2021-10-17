#include "BookLibrary.h"

int main()
{
    try
    {
        LibraryTools::ISBN isbn_code{1,2,3,'g'};
        std::string title;
        std::string author;
        Chrono::Date date{1974, Chrono::Month::Aug, 25};
        LibraryTools::Genre genre{LibraryTools::Genre::adventure};


        LibraryTools::Book b1{isbn_code, title, author, date, false, genre};
        std::cout << b1.GetIsbn();
    }
    catch(...)
    {
        std::cout << "general error\n";
    }
    return 0;
}