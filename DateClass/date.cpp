#include <iostream>

class Date
{
public:
    class InvalidDate {};
    Date(int y, int m, int d);
    void ShowDate();
private:
    int year;
    int month;
    int day;
    bool is_valid();
};

Date::Date(int y, int m, int d)
    : year{y}, month{m}, day{d}
{
    if (!is_valid()) throw InvalidDate(); // if date is not valid - throw exception
}

bool Date::is_valid()
{
    if (month < 1 || month > 12) return false;
    if (year < 0) return false;
    if (day < 1 || day > 31) return false;
    return true;
}

void Date::ShowDate()
{
    std::cout << year <<  "." << month << "." << day << "\n";
}

int main()
{
    try 
    {
        Date date1 = {2001, 11, 25};
        //Date date2 = {2005, 13, 4};

        date1.ShowDate();
        //date2.ShowDate();
    }
    catch(Date::InvalidDate d)
    {
        std::cout << "something went wrong in main";
    }
    return 0;
}