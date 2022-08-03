#include <iostream>
#include <string>
#include "card.cpp"

using namespace std;

class CardList{

public:
	Card *head;
    int size_deck = 0;
    CardList(){
        head = NULL;
    }
	void pop_back(){
        Card *curr = head;
        Card *front = head;
        if (size_deck == 1) {
            head = head->next;
            delete curr;
            curr = NULL;
            size_deck--;
        }
        else if (size_deck > 1) {
            while (front->next->next != NULL) {
                front = front->next;
            }
            curr = front->next;
            front->next = NULL;
            delete curr;
            curr = NULL;
            size_deck--;
        }
	}

    void insert_back(string newItem){
        Card *new_card = new Card;
        Card *curr = head;
        new_card -> name = newItem;
        new_card -> next = NULL;
        size_deck++;
        if (size_deck == 1) {
            head = new_card;
        }
        else {
            while (curr->next != NULL) {
                
                curr = curr->next;
            }
            curr->next = new_card;
        }
        
    }

    void shuffle(int pos){
        Card *curr;
        Card *front = head;
        Card *first = head;
        Card *Last = head;
        if (pos >= 1 && size_deck - 1 >= pos) {
            int i = 0;
            while (Last->next != NULL) {
                Last = Last->next; 
                if (size_deck - 1 == pos) {
                    if (i < size_deck - 3) {
                        front = front->next;
                        i++;
                    }
                }
                else if (i < pos-1) {
                    front = front->next;
                }
                i++;
            }
            if (size_deck == 2) {
                head = Last;
                head->next = first;
                head->next->next = NULL;
            }
            else if (size_deck - 1 == pos) {
                head = Last;
                curr = Last;
                curr->next = first;
                if (pos >= 4) { 
                    front = front->next;
                    for ( i = 0; i < pos-4; i++); {
                        front = front->next;
                    }
                    front->next = NULL;
                }
                else {
                    front->next->next = NULL;
                }
            }
            else {
                curr = front->next;
                head = curr;
                front->next = NULL;
                Last->next = first;
            }
        }
    }

    void printCardList(){
        /*
         DO NOT DELETE OR EDIT
         */
        cout << "[ ";
        Card* ptr = head;
        while(ptr!=NULL){
            cout << ptr->name << " ";
            ptr = ptr->next;
        }
        cout << "]\n";
    }
};
