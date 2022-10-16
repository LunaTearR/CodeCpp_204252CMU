#include<iostream>
#include "HW08.cpp"
using namespace std;

int main() {
    BST tree;
    tree.insert(2);
    tree.insert(1);
    tree.insert(4);
    tree.insert(11);
    tree.insert(10);
    tree.insert(8);
    // tree.insert(9);
    tree.insert(6);
    tree.remove(2);
    cout << tree.get_depth(8) << endl;
    cout << tree.get_depth(2) << endl;
    cout << tree.get_depth(4) << endl;
    cout << tree.get_depth(6) << endl;

    return 0;
}
