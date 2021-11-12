#include <iostream>


class MyVector {
private:    
    int sz;
    double* elem;
public:
    // default constructor
    MyVector(int s) : sz{s}, elem{new double[sz]} {
        for (int i = 0; i < static_cast<int>(sz); ++i)
            elem[i] = 0.0;
    }

    //constructor with initializer list
    MyVector(std::initializer_list<double> lst)
    : sz{static_cast<int>(lst.size())}, elem{new double[sz]} {
        std::copy(lst.begin(), lst.end(), elem);
    }

    MyVector(const MyVector& arg) 
    : sz{arg.sz}, elem{new double[arg.sz]} {
        std::cout << "copy constructor has been called for vector\n";
        for (int i = 0; i < sz; ++i) 
            elem[i] = arg.elem[i];
    }

    // function that prints elements of vector
    void PrintVector() {
        for (int i = 0; i < sz; ++i) {
            std::cout << elem[i] << " ";
        }
    }


};


int main() {
    try {
        MyVector v{2.3, 2.6, 5.6, 8.3}; 
        v.PrintVector();
        // 2.3 2.6 5.6 8.3

        std::cout << std::endl;
        
        MyVector v1(6);
        v1.PrintVector();
         // 0 0 0 0 0 0

        v1 = v; // not copy constructor
        MyVector v2{v1}; // copy constructor
        
        MyVector v3(3);
        v3 = v1; // not copy constructor
    }
    catch(...) {
        std::cout << "some general error" << std::endl;
        return 1;
    }
    return 0;
}