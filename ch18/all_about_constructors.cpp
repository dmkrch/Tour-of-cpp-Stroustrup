#include <vector>
#include <iostream>


struct X {
    int val;

    void out(const std::string& s, int nv) {
        std::cout << this << "->" << s << ": " << val
            << " (" << nv << ")\n";
    }

    X() { out("X()", 0); val=0; } // default constructor

    X(int v) { val=v; out("X(int)",v); }

    X(const X& x) { val=x.val; out("X(X&) ", x.val); } // copy constructor

    X& operator=(const X& a) { // assign constructor
        out("X::operator=()",a.val);
        val=a.val; return *this;
    }

    ~X() { out("~X()",0); } // destructor
};

X glob(2); // global variable

X copy(X a) { std::cout << "inside X copy(X a)\n"; return a; }

X copy2(X a) { std::cout << "inside X copy2(X a)\n"; X aa = a; return aa; }

X& ref_to(X& a) { return a; }

X* make(int i) { X a(i); return new X(a); }

struct XX { X a; X b; };

int main() {
    X loc {4}; // local variable
    X loc2 {loc}; // copy constructor

    std::cout << "\t\tnow assign constr\n";
    loc = X{5}; // assign constructor

    std::cout << "\t\tnow copy\n";
    loc2 = copy(loc); // passing by value and return

    std::cout << "\t\tcopy2 now\n";
    loc2 = copy2(loc);

    std::cout << "\t\tpassing by reference and return\n";
    X& r = ref_to(loc); // passing by reference and return


    std::cout << "\t\tdelete make(7)\n";
    delete make(7);


    std::cout << "\t\tvector of 4 X\n";
    std::vector<X> v(4); // values by default

    std::cout << "\t\tcreating an object of XX struct\n";
    XX loc4;

    std::cout << "\t\tX in dynamic mem\n";
    X* p = new X{9}; // X in dynamic memory

    std::cout << "\t\tdelete of pointer\n";
    delete p;

    std::cout << "\t\tarray of X in dynamic mem\n";
    X* pp = new X[5]; // array of X in dynamic memory

    std::cout << "\t\tdeletion of array of x in dynamic array\n";
    delete[] pp;
    return 0;
}