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
        Poly_node *new_poly = new Poly_node;
        Poly_node *curr = new Poly_node;

        new_poly -> coef = coef;
        new_poly -> exponent = exponent;
        new_poly -> next = NULL;

        if(head == NULL){
            head = new_poly;
            size++;
        }
        else if(size == 1){
            if(head -> exponent > exponent){
                head -> next = new_poly; 
                size++;
            }
            else if(head -> exponent == exponent){
                head -> coef += coef;
                delete new_poly;
            }
            else{
                new_poly -> next = head;
                head = new_poly;
                size++;
            }
        }
        else{
            curr = head;
            if(curr -> exponent  < exponent){
                new_poly -> next = curr;
                head = new_poly;
                curr = head;
            }
            else if(curr -> exponent == exponent){
                curr -> coef += coef;
                delete new_poly;
            }
            else {
                while(curr -> next != NULL){
                    if(curr -> next -> exponent <= exponent){
                        break;
                    }
                    else{
                        curr = curr -> next;
                    }
                }
                if (curr -> next == NULL){
                    curr -> next = new_poly;
                    size++;
                }
                else if( curr -> next -> exponent == exponent){
                    curr -> next -> coef += coef;
                    delete new_poly;
                }else {
                    new_poly -> next = curr -> next;
                    curr -> next = new_poly;
                    size++;
                }
            }
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
        Poly_node *poly = new Poly_node;
        poly = f2.head;

        while (poly != NULL){
            int coeff = poly -> coef;
            int expo = poly -> exponent;
            addTerm(coeff,expo);
            poly = poly -> next;
        }
    }
    void minus(Polynomial f2){
        Poly_node *poly = new Poly_node;
        poly = f2.head;

        while (poly != NULL){
            int coeff = poly -> coef;
            coeff *= -1;
            int expo = poly -> exponent;
            addTerm(coeff,expo);
            poly = poly -> next;
        }
    }
};
