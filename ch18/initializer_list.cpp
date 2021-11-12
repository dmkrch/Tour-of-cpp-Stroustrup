#include <iostream>


class MyVector {
public:    
    int sz;
    double* elem;
public:
    // default constructor
    MyVector(int s) : sz{s}, elem{new double[sz]} {
        for (int i = 0; i < static_cast<int>(sz); ++i)
            elem[i] = 0.0;
    }


    ~MyVector() {
        delete [] elem;
    }

    //constructor with initializer list
    MyVector(std::initializer_list<double> lst)
    : sz{static_cast<int>(lst.size())}, elem{new double[sz]} {
        std::copy(lst.begin(), lst.end(), elem);
    }

    // copy constructor
    MyVector(const MyVector& arg) 
    : sz{arg.sz}, elem{new double[arg.sz]} {
        std::cout << "copy constructor has been called for vector\n";

        std::copy(arg.elem, arg.elem+sz, elem);
    }

    // function that prints elements of vector
    void PrintVector() {
        for (int i = 0; i < sz; ++i) {
            std::cout << elem[i] << " ";
        }
    }


};

void testFunc(MyVector v) {
    std::cout << "address: " << v.elem;
    std::cout << " in test func\n";
}


int main() {
    try {
        MyVector v{2.3, 2.6, 5.6, 8.3}; 
        v.PrintVector();
        // 2.3 2.6 5.6 8.3

        MyVector v2{v}; // copy constructor    

        std::cout << "address: " << v2.elem << " in main\n";
        testFunc(v2);

        // here we dont get an error because we have copy custom constructor.
        // so that function doesnt just copy address of elem. It creates new, that
        // is being deleted after function ends 
        v2.PrintVector();
    }
    catch(...) {
        std::cout << "some general error" << std::endl;
        return 1;
    }
    return 0;
}