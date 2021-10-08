#include <iostream>
#include <vector>

enum class Day
{
    monday, tuesday, wednesday, 
    thursday, friday, saturday, sunday
};

enum class Month
{
    Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};


std::vector<std::string> month_tbl = {"January", "February",
    "March", "April", "May", "June", "July", "August",
        "September", "October", "November", "December"};

std::ostream& operator<<(std::ostream& os, Month m)
{
    return os << month_tbl[int(m)-1];
}



class Year 
{
public:
    class InvalidYear{};
    Year(int x) : year{x} { if (x<min || max<=x) throw InvalidYear(); }
    int get_year() { return year; }
private:
    static const int min = 1800;
    static const int max = 2200;
    int year;
};

std::ostream& operator<<(std::ostream& os, Year y)
{
    return os << y.get_year();
}

/* -------------------------DATE CLASS REALISATION------------------------------------- */
class Date
{
public:
    class InvalidDate {};
    Date(Year y, Month m, int d);
    void ShowDate();
    Month get_month() { return month; }
private:
    Year year;
    Month month;
    int day;
    bool is_valid();
};

Date::Date(Year y, Month m, int d)
    : year{y}, month{m}, day{d}
{
    if (!is_valid()) throw InvalidDate(); // if date is not valid - throw exception
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
/* -------------------------END OF DATE CLASS REALISATION---------------------------------*/



Month operator++(Month& m)
{
    m = (m==Month::Dec) ? Month::Jan : Month(int(m) + 1);
    return m;
}

int main()
{
    try 
    {
        Date d1 = {Year{2001}, Month::Jan, 25};
        d1.ShowDate();
    }
    catch(Date::InvalidDate d)
    {
        std::cout << "wrong date setup";
    }
    catch(...)
    {
        std::cout << "some general error";
    }
    return 0;
}