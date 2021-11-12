// 1 .   Определите  класс  B1  с  виртуальной  функцией  vf ( )    и  невиртуаль­
// ной  функцией  f ( ) .  Определите  эти  функции  в  классе B1 .  Реализуй­
// те  каждую  функцию  так,  чтобы  она  выводила  свое  имя  (например, 
// "B1 :  : vf () ") .  Сделайте эти функции открытыми. Создайте объект B1    и 
// вызовите каждую из функций. 
// 2.  Определите  класс D1 ,   производный от  класса B1 ,   и  перекройте  в нем 
// функцию vf () . Создайте объект класса D1   и вызовите из него функции 
// vf () и f ( ) . 
// 3.  Определите  ссылку на объект  класса  B1  (т.е. B1 &)  и  инициализируйте 
// ее только что созданным объектом класса D1 .   Вызовите функции vf () 
// и f () с помощью этой ссылки. 
// 4. Теперь определите функцию f () в классе D1   и повторите пп.  1-3. Объ­
// ясните результаты. 
// 5.  Добавьте в класс B1  чисто виртуальную функцию pvf () и попытайтесь 
// повторить пп.  1-4. Объясните результат. 
// 6.  Определите  класс D 2 ,    производный от класса D l ,    и  перекройте в  нем 
// функцию pvf () .  Создайте объект класса D2  и вызовите  из него функ­
// ции f ( )   , vf () и pvf ( )   . 
// 7.  Определите  класс  B2  с  чисто  виртуальной  функцией  pvf ( )   .  Опреде­
// лите класс D2 1  с данным-членом типа string и функцией-членом, пе­
// рекрывающей функцию pvf ( ) ;  функция D 2 1  :  :pvf( )   должна выводить 
// значение упомянутого выше члена типа string. Определите класс D22,   
// аналогичный классу D21 ,   за исключением того, что его член имеет тип 
// int. Определите функцию f (),  получающую аргумент типа B2 &  и  вы­
// зывающую  функцию pvf ( )   для  этого  аргумента.  Вызовите функцию 
// f () с аргументами D21  и D22 .  

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

        // bRef is a reference of B type to d1 object
        B1& bRef = d1;
        bRef.vf();
        bRef.f();
    }
    catch(...) {
        std::cerr << "some error" << std::endl;
    }
}