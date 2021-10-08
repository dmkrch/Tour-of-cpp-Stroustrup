#include <iostream>
#include <vector>
#include "Chrono.h"

int main()
{
    try 
    {
        Chrono::Date my_birthday{Chrono::Year{2001}, Chrono::Month::Jul, 10};
        my_birthday.ShowDate();

        Chrono::Date wrong_date{Chrono::Year{2006}, Chrono::Month::Feb, 41}; // here we'll get an error
        wrong_date.ShowDate();
    }
    catch(Chrono::Date::InvalidDate d)
    {
        std::cout << "wrong date setup\n";
    }
    catch(...)
    {
        std::cout << "some general error\n";
    }
    return 0;
}