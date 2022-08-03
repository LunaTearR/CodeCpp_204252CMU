#include <iostream>
#include <string>
#include "station.cpp"
using namespace std;

class Trip {

public:
    Station* header;
    Station* trailer;
    int size = 0;
    Trip() {
          header = new Station;
          trailer = new Station;
          header -> prev = NULL;
          header -> next = trailer;
          trailer -> prev = header;
          trailer -> next = NULL;
    }

    void printList() {
          cout << "[ ";
          Station* ptr = header->next;
          while (ptr != trailer) {
               cout << ptr->name << " ";
               ptr = ptr->next;
          }
          cout << "]\n";
    }


    void insert_front(string newItem) {
          Station *new_station = new Station;
          Station *curr = header -> next;
          new_station -> name = newItem;
          size++;
          if (size == 1) {
               header -> next = new_station;
               curr = new_station;
               new_station -> prev = header;
               new_station -> next = trailer;
               trailer -> prev = new_station;
          }
          else {
               header -> next = new_station;
               new_station -> prev = header;
               new_station -> next = curr;
               curr -> prev = new_station;
          }
          
          
    }
    void insert_back(string newItem) {
          Station *new_station = new Station;
          Station *curr = header -> next;
          new_station -> name = newItem;
          new_station -> next = NULL;
          size++;
          if(size == 1) {
               header -> next = new_station;
               new_station -> prev = header;
               new_station -> next = trailer;
          }
          else {
               while (curr -> next != trailer) {
                    curr = curr -> next;
               }
               curr -> next = new_station;
               new_station -> next = trailer;
               trailer -> prev = new_station;
          }
    }

    void remove_front() {
          Station *new_station = new Station;
          Station *curr = header -> next;
          if (size == 1) {
               header -> next = trailer;
               trailer -> prev = header;
               delete curr;
               curr = NULL;
               size--;
          }
          else if (size > 1) {
               header -> next = curr -> next;
               curr -> next -> prev = header;
               delete curr;
               curr = NULL;
               size--;
          }
    }
    void remove_back() {
         Station *curr;
         Station *front = header -> next;

         if (size == 1) {
               header -> next = trailer;
               trailer -> prev = header;
               delete front;
               front = NULL;
               size--;
          }
          else if (size > 1) {
               while (front -> next != trailer -> prev) {
                    front = front -> next;
               }
               curr = front -> next;
               front -> next = trailer;
               trailer -> prev = front;
               delete curr;
               curr = NULL;
               size--;
          }
    }

    Station* visit(int nStep, string stepText) {
          Station *curr = header -> next;
          for (int i = 0; i < nStep; i++){
               if (stepText[i] == 'L'){
                    if(curr -> prev != header){
                         curr = curr -> prev;
                    }
               }
               else if(stepText[i] == 'R'){
                    if(curr -> next != trailer){
                         curr = curr -> next;
                    }
               }
          }
          return curr;
    }
};