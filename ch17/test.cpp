#include <iostream>

class GeneralError {
public:
    GeneralError() : error_text("default error text"),
        error_code(252) {
    }

    std::string error_text;
    int error_code;
};

void test_func() {
    throw GeneralError();
}



int main() {
    try {
        int a = 5;
        int b = 7;
        int c = 10;

        std::cout << "1: " << &a << " 2: " << &b << " 3: " << &c << std::endl;

        int* ap = new int{5};
        int* bp = new int{7};
        int* cp = new int{10};

        std::cout << "1: " << ap << " 2: " << bp << " 3: " << cp << std::endl;
    }
    catch(GeneralError err) {
        std::cout << err.error_text;
        return err.error_code;
    }

    return 0;
}