#include <iostream>

using namespace std;


/*





*/
class Token {
public:
    char kind;
    double value;
};



int main() {
    cout << "Enter expression: ";
    int lval = 0;
    int rval;
    char op;
    int res;

    cin >> lval >> op >> rval;

    if (op=='+')
        res = lval + rval;
    else if (op == '-')
        res = lval - rval;
    
    return 0;
}