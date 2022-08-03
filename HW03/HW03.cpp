#include <iostream>
#include "term.cpp"
using namespace std;
class Polynomial{
public:
    Poly_node* head;
    int size;
    Polynomial(){
        head = NULL;
        size = 0;
    }
    void addTerm(int coef, int exponent){
        Poly_node *new_poly = new Poly_node;
        Poly_node *curr = head;
        new_poly -> coef = coef;
        new_poly -> exponent = exponent;
        size++;
        if (size == 1){
            head = new_poly;
        }
        else {
            
        }

    }
    void printPolynomial(){
        cout<<"[ ";
        Poly_node* ptr = head;
        while(ptr!=NULL){
            if(ptr->coef==0){

            }else{
                cout<< ptr->coef<<"X^{"<<ptr->exponent<<"} ";
            }
            ptr = ptr->next;
        }
        cout<<"]\n";
    }
    void plus(Polynomial f2){
        /*
         WRITE YOUR CODE HERE
         */
    }
    void minus(Polynomial f2){
        /*
         WRITE YOUR CODE HERE
         */
    }
};



