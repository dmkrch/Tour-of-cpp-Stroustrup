#include <iostream>
#include <fstream>
#include <vector>

struct Reading 
{
    int hour;
    double temperature;
};

std::ostream& operator<<(std::ostream& os, Reading r)
{
    return os << r.hour << ": " << r.temperature;
}

int main()
{
    try
    {
        std::cout << "Please enter input file name: ";
        std::string iname;
        std::cin >> iname;

        std::cout << "Please enter output file name: ";
        std::string oname;
        std::cin >> oname;
        

        // opening streams and checking whether it was successful
        std::ifstream ist(iname);   // ist - input stream for file iname
        std::ofstream ost(oname);  // ost - output stream for file oname
        if (!ist)
            std::cout << "Unable to open file for reading " << iname << std::endl;
        else
            std::cout << "File for reading has been opened" << std::endl;


        // reading temperatures from ist
        std::vector<Reading> temps;
        int hour;
        double temperature;
        while(ist >> hour >> temperature)
        {
            if (hour < 0 || 23 < hour)
                std::cout << "Incorrect time" << std::endl;
            temps.push_back(Reading{hour, temperature});
        }

        // writing temperatures to ost
        for (int i = 0; i < temps.size(); ++i)
            ost << "(" << temps[i] << ")" << std::endl;

        // closing opened ist and ost streams
        ist.close();
        ost.close();
    }
    catch(...)
    {
        std::cout << "Some general error" << std::endl;
        return 1;
    }
    return 0;
}