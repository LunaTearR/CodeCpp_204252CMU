#include <iostream>
#include "HW03.cpp"
using namespace std;

int main()
{
    Polynomial f1;
    Polynomial f2;
    f1.addTerm(5,8);
    f1.addTerm(2,7);
    f1.addTerm(4,1);
    f1.addTerm(1,6);
    f1.addTerm(9,3);
    f1.addTerm(4,1);
    f1.addTerm(4,9);
    
    f1.printPolynomial();
    f2.addTerm(4,5);
    f2.addTerm(1,1);
    f2.addTerm(-5,0);
    f2.printPolynomial();
    f1.minus(f2);
    f1.printPolynomial();
    return 0;
}