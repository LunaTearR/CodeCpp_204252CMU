#include <iostream>
#include "term.cpp"
using namespace std;
class Polynomial{
public:
    Poly_node* head = new Poly_node;
    int size;
    Polynomial(){
        head = NULL;
        size = 0;
    }
    void addTerm(int coef, int exponent){
        
        
        if(size == 0){
            Poly_node *new_poly = new Poly_node;
            new_poly -> coef = coef;
            new_poly -> exponent = exponent;
            head = new_poly;
            size++;
        }
        else{
            Poly_node *new_poly = new Poly_node;
            Poly_node *poly = new Poly_node;
            
            new_poly -> coef = coef;
            new_poly -> exponent = exponent;

            if(size == 1){
                poly = head;

                if(poly -> exponent > exponent){
                    poly -> next = new_poly;
                }
                else if(poly -> exponent == exponent){
                    poly -> coef += coef;
                    delete new_poly;
                }
                else {
                    head = new_poly;
                    new_poly -> next = poly;
                }
            }
            else {
                Poly_node *curr = new Poly_node;
                poly = head;
                curr = head -> next;
                while(poly != NULL){
                    if(poly -> next != NULL){
                        if(exponent > poly -> exponent && exponent > curr -> exponent) {
                            head = new_poly;
                            new_poly -> next = poly;
                            break;
                        }
                        else if( exponent < poly -> exponent && exponent > curr -> exponent){
                            poly -> next = new_poly;
                            new_poly = curr;
                            break;
                        }
                        else if(exponent == poly -> exponent){
                            poly -> coef += coef;
                            delete new_poly;
                            break;
                        }
                        else if(exponent == curr -> exponent){
                            curr -> coef += coef;
                            delete new_poly;
                            break;
                        }
                    }
                    else {
                        poly -> next = new_poly;
                        break;
                    }
                    poly = poly -> next;
                    curr = curr -> next;
                }
            }
            size++;
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
