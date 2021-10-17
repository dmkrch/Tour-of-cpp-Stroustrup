#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    try
    {
        std::cout << "Please enter input file name: ";
        std::string iname;
        std::cin >> iname;

        // opening streams and checking whether it was successful
        std::ifstream ist(iname);   // ist - input stream for file iname

        if (ist)
            std::cout << "file opened!" << std::endl;
        else
        {
            if (ist.bad())
                std::cout << "ist is bad";
            if (ist.eof())
            {
                // no more input data
                // usually this is the end of inputting data
            }
            if (ist.fail()) // something went wrong with stream
            {
                ist.clear(); //  be ready to new input
                // fixing this error
            }
        }

        // closing opened ist and ost streams
        ist.close();
    }
    catch(...)
    {
        std::cout << "Some general error" << std::endl;
        return 1;
    }
    return 0;
}