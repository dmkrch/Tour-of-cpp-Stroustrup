#include <iostream>
#include <initializer_list>

template<typename T, int N> 
struct arr {
    arr(std::initializer_list<T> lst) {
        std::copy(lst.begin(), lst.end(), elem);
    }

    const T& operator[](int id) const {
        return elem[id];
    }

    int size() const { return N; }

    T elem[N];
};


template<typename T>
class myArray {
public:
    myArray(int s) {
        lastElemId = 0;
        sz = s;
        ptr = new T(s);

        for (int i = 0; i < sz; ++i)
            ptr[i] = 0;
    }
    
    ~myArray() {
        delete [] ptr;
    }

    int size() const { return sz; }

    void push_back(T elem) {
        ptr[lastElemId] = elem;
        lastElemId++;
    }

    T& operator[](int id) const {
        return ptr[id];
    }

private:
    int sz;
    T* ptr;
    int lastElemId;
};


template<typename C>
void printout(const C& c) {
    for (int i = 0; i < c.size(); ++i)
        std::cout << c[i] << std::endl;
}

int main() {
    arr<double, 6> arr{ 0.0, 1.1, 2.2, 3.3, 4.4, 5.5 };
    myArray<int> arr1(5);
    arr1.push_back(5);
    arr1.push_back(7);
    arr1.push_back(10);
    arr1.push_back(-5);


    printout(arr1);
    printout(arr);

    return 0;
}