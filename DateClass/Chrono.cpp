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

    Date::Date(int y, Month m, int d)
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

    void Date::ShowDate() const
    {
        std::cout << year <<  "." << month << "." << day << "\n";
    }

    bool is_leapyear(int n)
    {
        if (n % 400 == 0) // if year % 400 no remainder - this is a leap y.
            return true;
        else if (n % 100 == 0) // if year % 100 no remainder - this is not a leap y.
            return false;
        else if (n % 4 == 0) // this is a leap y.
            return true;
        else // else - not leap y.
            return false;
    }

    void Date::add_day(int n)
    {
        // leaving realisation for future
    }

    void Date::add_month(int n)
    {
        int curr_month = (int)month;
        month = (Month)((curr_month + n) % 12); // changing month to next

        int year_adder = (curr_month + n) / 12;
        add_year(year_adder);
    }

    void Date::add_year(int n)
    {
        if (month==Month::Feb && day==29 && !is_leapyear(year+n))
        {
            month = Month::Mar; // 29 february turns into 1 march
            day = 1;
        }
        year += n;
    }

    bool operator==(const Date& a, const Date& b)
    {
        return a.get_year() == b.get_year()
            && a.get_month() == b.get_month()
            && a.get_day() == b.get_day();
    }

    bool operator!=(const Date& a, const Date& b)
    {
        return !(a==b);
    }
}