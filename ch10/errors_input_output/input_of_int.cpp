#include <iostream>


void skip_to_int()
{
    if (std::cin.fail()) // something not an integer number...
    {
        std::cin.clear();   // returning stream to state 'good'. We wannna take a look at symbols

        for (char ch; std::cin;) // skipping symbols
        {
            if (isdigit(ch) || ch == '-')
            {
                std::cin.unget(); // returning digit, so that we can read number
                return;
            }
        }
    }
    std::cout << "exception error here\n";
}

int get_int()
{
    int n = 0;
    while(true)
    {
        if (std::cin >> n)
            return n;
        
        std::cout << "This is not a number, try again\n";
        skip_to_int();
    }
}

int get_int(int low, int high, const std::string& greeting,
            const std::string& sorry)
{
    std::cout << greeting << low << " to " << high << " including:\n";

    while(true)
    {
        int n = get_int();
        if (low <= n && n <= high)
            return n;
        
        std::cout << sorry << n << " is out of interval [" 
            << low << ", " << high << "]\n";
    }
}


int main()
{
    int n = get_int(1,10, "Enter power", "Out of interval, try again");

    int m = get_int(2, 300, "Enter height in feet",
                    "Out of interval. Try typing again");
                    
    std::cout << "m: " << m << std::endl;

    return 0;
}