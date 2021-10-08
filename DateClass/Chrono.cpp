#include "Chrono.h"


namespace Chrono
{
    std::vector<std::string> month_tbl = {"January", "February",
        "March", "April", "May", "June", "July", "August",
            "September", "October", "November", "December"};

    std::ostream& operator<<(std::ostream& os, Month m)
    {
        return os << month_tbl[int(m)-1];
    }

    std::ostream& operator<<(std::ostream& os, Year y)
    {
        return os << y.get_year();
    }

    Date::Date(Year y, Month m, int d)
        : year{y}, month{m}, day{d}
    {
        if (!is_valid()) throw InvalidDate(); // if date is not valid - throw exception
    }

    Date::Date()
        : year{2001}, month{Month::Jan}, day{1}
    {

    }

    bool Date::is_valid()
    {
        if ((int)month < 1 || (int)month > 12) return false;
        if (day < 1 || day > 31) return false;
        return true;
    }

    void Date::ShowDate()
    {
        std::cout << year <<  "." << month << "." << day << "\n";
    }
}