#include <iostream>
#include <vector>

namespace Chrono
{
    enum class Month
    {
        Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
    };

    enum class Day
    {
        monday, tuesday, wednesday, 
        thursday, friday, saturday, sunday
    };

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

    class Date
    {
    public:
        class InvalidDate {};
        Date(Year y, Month m, int d);
        Date();
        void ShowDate();
        Month get_month() const { return month; }
        Year get_year() const { return year; }
        int get_day() const { return day; }

    private:
        Year year;
        Month month;
        int day;
        bool is_valid();
    };

    std::ostream& operator<<(std::ostream& os, Month m);
    std::ostream& operator<<(std::ostream& os, Year y);
}