#include "temperatures.h"

namespace WeatherStatistics
{

    std::vector<std::string> month_print_tbl = {
        "jan", "feb", "mar", "apr", "may", "jun",
        "jul", "aug", "sep", "oct", "nov", "dec"
    };

    void end_of_loop(std::istream& ist, char term, const std::string& message)
    {
        if (ist.fail())
        {
            ist.clear();
            char ch;
            if (ist >> ch && ch == term)
                return;

            throw "error";
        }
    }

    bool is_valid(const Reading& r)
    {
        if (r.day < 1 || 31 <r.day) return false;
        if (r.hour < 0 || 23 < r.hour) return false;
        if (r.temperature < implausible_min ||
            implausible_max < r.temperature)
            return false;
        return true;
    }


    //---------------------OPERATORS OVERLOAD----------------
        // reading temperatures from stream is to r
    // format : ( 3 4 9.7)
    // here we check format, not correct data
    std::istream& operator>>(std::istream& is, Reading& r)
    {
    
        char ch1;
        if (is >> ch1 && ch1 != '(')
        {
            is.unget();
            is.clear(std::ios_base::failbit);
            return is;
        }

        char ch2;
        int d;
        int h;
        double t;
        is >> d >> h >> t >> ch2;
        if (!is || ch2 != ')')
            throw "error";
        r.day = d;
        r.hour = h;
        r.temperature = t;
        return is;
    }

    // reading object of Month class from stream is to m
    // format : { month feb ... }
    std::istream& operator>>(std::istream& is, Month& m)
    {
        char ch = 0;
        if (is >> ch && ch != '{')
        {
            is.unget();
            is.clear(std::ios_base::failbit);
            return is;
        }

        std::string month_marker;
        std::string mm;
        is >> month_marker >> mm;
        if (!is || month_marker != "month")
            throw "error";
        m.month = month_to_int(mm);

        Reading r;
        int duplicates = 0;
        int invalids = 0;
        for (Reading r; is >> r; )
        {
            if (is_valid(r))
            {
                if (m.day[r.day].hour[r.hour] != not_a_reading)
                    ++duplicates;
                m.day[r.day].hour[r.hour] = r.temperature;
            }
            else
                ++invalids;
        }
        if (invalids)
            throw "error";
        if (duplicates)
            throw "error";
        end_of_loop(is, '}', "Incorrect Month");
        return is;
    }

    std::istream& operator>>(std::istream& is, Year& y)
    {
        char ch;
        is >> ch;
        if (ch!='{')
        {
            is.unget();
            is.clear(std::ios::failbit);
            return is;
        }

        std::string year_marker;
        int yy;
        is >> year_marker >> yy;
        if (!is || year_marker!="year")
            throw "error";
        y.year = yy;
        while(true)
        {
            Month m;
            if (!(is >> m)) 
                break;
            y.month[m.month] = m;
        }

        end_of_loop(is, '}', "Incorrect ending of Year");
        return is;
    }

    int month_to_int(std::string s)
    {
        for (int i = 0; i < 12; ++i) 
            if (month_print_tbl[i] == s) return i;
        return -1;
    }
}