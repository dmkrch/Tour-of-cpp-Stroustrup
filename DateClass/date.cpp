#include <iostream>
#include <vector>
#include "Chrono.h"

int main()
{
    try 
    {
        Chrono::Date my_birthday{2001, Chrono::Month::Jul, 10};
        my_birthday.ShowDate(); // 2001.July.10

        my_birthday.add_month(13);
        my_birthday.ShowDate(); // 2002.August.10

        Chrono::Date some_day{2002, Chrono::Month::Aug, 10};
        my_birthday==some_day ? std::cout << "equal\n" : std::cout << "not equal\n"; // equal
        my_birthday!=some_day ? std::cout << "not equal\n" : std::cout << "equal\n"; // equal
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