#include "BSTNode.cpp"
#include<iostream>
using namespace std;
class BST {

public:
  BSTNode *root;
  
  BST() {
    root = NULL;
  }

  void insert(int value) {
    BSTNode *new_node = new BSTNode();
    BSTNode *p,*prev;
    new_node -> left = NULL;
    new_node -> right = NULL;
    new_node -> value = value;
    if(root == NULL){
      root = new_node;
      root -> left = NULL;
      root -> right = NULL;
    }
    if(search_value(root,value)){
      return ;
    }
    else {
      p = root;
      while(p != NULL){
        prev = p;
        if(p -> value > new_node -> value){
          p = p -> left;
        }
        else {
          p = p -> right;
        }
      }
      if(prev -> value > new_node -> value){
        prev -> left = new_node;
      }
      else {
        prev -> right = new_node;
      }
    }
  }

  void remove(int value) {
    BSTNode *p,*prev,*temp;
    // BSTNode *min = new BSTNode();
    p = root;
    if (root == NULL){
        return ;
    }
    if(!search_value(root,value)){
      return ;
    }
    while (p -> value != value){
    }
  }

  BSTNode* find_min(BSTNode* node){
    BSTNode *min = new BSTNode();
    min = node;
    while(min != NULL && min->left != NULL)
      min = min->left;
    return min;
  }

  int get_depth(int value) {
    BSTNode *p;
    int depth = 0;
    if (value == root -> value){
      return 0;
    }
    if(!search_value(root,value)){
      return -1;
    }
    p = root;
    while (p -> value != value){
      depth++;
      if(p -> value > value){
        p = p -> left;
      }
      else {
        p = p -> right;
      }
    }
    return depth;
  }

  bool search_value(BSTNode *node, int key) {
   BSTNode *temp = new BSTNode();
   temp = node;
   while(temp != NULL) {
      if(temp -> value == key) {
         return true;
      } 
      else if(temp -> value > key){
         temp = temp -> left;
      }
      else{
        temp = temp->right;
      }
   }
   return false;
  }
};
