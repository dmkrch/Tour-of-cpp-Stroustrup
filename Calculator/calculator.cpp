#include <iostream>
using namespace std;

/*
    -----------GRAMMAR FOR CALCULATING EXPRESSIONS------------

    expression:
        term
        expression + term   
        expression - term
    term:
        primary_expression
        term * primary_expression
        term / primary_expression
        term % primary_expression
    primary_expression:
        number
        ( expression )
    number:
        literal
*/

class Token 
{
public:
    char kind;
    double value;
};

/* reading symbols and making lexemes */
Token get_token(); 

/* working with operations + - */
double expression();

/* working with operations * / % */
double term();

/* working with numbers and () */
double primary();

double expression() 
{
    double left = term(); // reading and calculating term
    Token t = get_token(); // getting next lexema

    while(true) 
    {
        switch (t.kind) 
        {
        case '+':
            left += term(); // calculating term and summing
            t = get_token();
            break;
        case '-':
            left -= term(); // calculating term and subtractioning
            t = get_token();
            break;
        default:
            return left;  // end - no + and - symbols; returning answer
        }
    }
}

double term()
{
    double left = primary();
    Token t = get_token();
    while (true)
    {
        switch (t.kind)
        {
        case '*':
            left *= primary();
            t = get_token();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0)
            {
                cout << "dividing on zero";
            }
            left /= d;
            t = get_token();
            break;
        }
        default:
            return left;
        }
    }
}

double primary()
{
    Token t = get_token();
    switch (t.kind)
    {
    case '(':
    {
        double d = expression();
        t = get_token();
        if (t.kind != ')')
        {
            cout << "needed )";
        }
        return d;
    }
    case '8':
        return t.value;
    default:
        cout << "needing primary expression";
    }
}


int main() 
try
{
    while (cin)
    {
        cout << expression() << '\n';
    }

    return 0;
}
catch (exception& e)
{
    cerr << e.what() << '\n';
    return 1;
}
catch (...)
{
    cerr << "exception!\n";
    return 2;
}