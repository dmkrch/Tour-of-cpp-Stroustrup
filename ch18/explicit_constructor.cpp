#include <iostream>


class vect {
public:
    vect(int amount) {
        elements = new double[amount];
        size = amount;
        std::cout << "constr int a\n";

        for (int i = 0; i < size; ++i) 
            elements[i] = 0.0;
    }

    void PrintVector() {
        for (int i = 0; i < size; ++i) 
            std::cout << elements[i] << " ";
    }
private:
    int size;
    double* elements;
};


int main() {
    try {
        // here we can create vector of 10 element
        // this is called 'implicit' constructor
        // SO, our constructor can convert argument int to vect
        vect v = 10;    

        // now we created vector of 10 elements
        v.PrintVector(); // 00 0 0 0 0 0..0 (10)

        // now we recreate vector of 20 elements
        v = 20;
        v.PrintVector(); // 0 00 0 0 0 0  0 0..0 0(20)

        // if we want to prevent from this action - use 'explicit' before the constructor with 1 arg
    }
    catch(...) {
        std::cout << "some general error\n";
    }
}