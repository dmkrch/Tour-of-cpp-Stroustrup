#include <iostream>


int main()
{
    std::cout << "Enter number from 1 to 10:\n";
    int n = 0;

    while(true)
    {
        std::cin >> n;
        if (std::cin) // entered integer number. checking it
        {
            if (1 <= n && n <= 10) 
                break;
            std::cout << "sorry, " << n << " is out of [1,10] interval\n";
        }
        else if (std::cin.fail()) // something not an integer number...
        {
            std::cin.clear();   // returning stream to state 'good'. We wannna take a look at symbols

            std::cout << "This is not a number. Try again\n";
            for (char ch; std::cin >> ch && !isdigit(ch);)
                ; // skipping not numbers
            if (!std::cin)
            {
                std::cout << "No input anymore\n";
                // state to end work: exception maybe
            }
            
            std::cin.unget();   // returning digit, so that we can read number
        }
        else 
        {
            std::cout << "No input anymore\n";
            // state of eof or bad: ending work somehow: exception maybe
        }
    }

    std::cout << "Your number: " << n << std::endl;

    return 0;
}