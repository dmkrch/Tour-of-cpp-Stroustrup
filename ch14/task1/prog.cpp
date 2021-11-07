// 1 .   Определите  класс  B1   с  виртуальной  функцией  vf ( )    и  невиртуаль­
// ной  функцией  f ( ) .  Определите  эти  функции  в  классе B1.  Реализуй­
// те  каждую  функцию  так,  чтобы  она  выводила  свое  имя  (например, 
// "B1 :  : vf () ") .  Сделайте эти функции открытыми. Создайте объект B1    и 
// вызовите каждую из функций.

#include <iostream>

class B1 {
public:
    virtual void vf() {
        std::cout << "B1::vf() ";
    }

    void f() {
        std::cout << "B1::f() ";
    }
};

class D1 : public B1 {
public:
    void vf() override {
        std::cout << "D1::vf() ";
    }
};

int main() {
    try {
        B1 b1;

        b1.vf();
        b1.f();

        D1 d1;
        d1.vf();
        d1.f();
    }
    catch(...) {
        std::cerr << "some error" << std::endl;
    }
}