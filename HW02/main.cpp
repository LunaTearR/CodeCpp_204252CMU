#include <iostream>
#include "HW02.cpp"
using namespace std;
int main()
{
    Trip T;    
    T.insert_front("UENO");
    T.insert_front("KANDA");
    T.insert_front("TOKYO");
    T.insert_front("OSAKA");
    T.insert_front("NUMBA");
    T.insert_front("SHIBUYA");
    // T.insert_back("ASAKUSA");
    // T.insert_back("TOKYO");
    // T.insert_back("UENO");
    // T.remove_front();
    // T.remove_back();
    // T.remove_front();
    // T.remove_back();

    T.printList();
    Station *lastStation;
    // lastStation= T.visit(7,"RRLRRRL");
    lastStation= T.visit(6,"LLLRRR");
    cout<<lastStation->name;
    return 0;
}