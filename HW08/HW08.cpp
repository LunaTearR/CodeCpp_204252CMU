#include "BSTNode.cpp"
#include<iostream>
using namespace std;
class BST {

public:
  BSTNode *root,*p,*prev,*temp;
  
  BST() {
    root = nullptr;
    p = nullptr;
    prev = nullptr;
    temp = nullptr;
  }

  void insert(int value) {
    BSTNode *new_node = new BSTNode();
    new_node -> left = nullptr;
    new_node -> right = nullptr;
    new_node -> value = value;
    if(root == nullptr){
      root = new_node;
      root -> left = nullptr;
      root -> right = nullptr;
    }
    if(search_value(root,value)){
      return ;
    }
    else {
      p = root;
      while(p != nullptr){
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
    remove_element(root, root, value);
  }

  BSTNode *find_min(BSTNode *min){
    while(min != nullptr && min->left != nullptr)
      min = min->left;
    return min;
  }
  BSTNode* find_max(BSTNode* max){
  while(max != nullptr && max->right != nullptr)
    max = max -> right;
  return max;
}

  int get_depth(int value) {
    int depth = 0;
    if(!search_value(root,value)){
      return -1;
    }
    if (value == root -> value){
      return 0;
    }
    p = root;
    while (p -> value != value){
      depth++;
      if(value < p -> value){
        p = p -> left;
      }
      //value >= p -> value
      else{
        p = p -> right;
      }
    }
    return depth;
  }

  bool search_value(BSTNode *node, int key) {
   BSTNode *temps = new BSTNode();
   temps = node;
   while(temps != nullptr) {
      if(temps -> value == key) {
         return true;
      } 
      else if(temps -> value > key){
         temps = temps -> left;
      }
      else{
        temps = temps->right;
      }
   }
   return false;
  }



  void remove_element(BSTNode *a, BSTNode *before, int value) {
    if (a != nullptr) {
      if (value < a -> value) {
        before = a;
        remove_element(a->left, before, value);
      } 
      else if (value > a->value) {
        before = a;
        remove_element(a->right, before, value);
      } 
      else {
        if (a->left == nullptr && a->right == nullptr) {
          // cout << "Both empty"
          //<< "\n";
          if (before->value == a->value) {
            root = nullptr;
      
          } 
          else if (before->left->value == a->value){
            before->left = nullptr;
          } 
          else {
            before->right = nullptr;
          }
        } 
        else if (a->left == nullptr) {
          // cout << "child on right";
          if (before->value == a->value) {
            root = a->right;
          } 
          else if (before->left->value == a->value) {
            before->left = a->right;
          } 
          else {
            before->right = a->right;
          }
        } 
        else if (a->right == nullptr) {
          if (before->value == a->value) {
            root = a->left;
          } 
          else if (before->left->value == a->value) {
            before->left = a->left;
          } 
          else {
            before->right = a->left;
          }
        } 
        else {
          // cout << "Both child"<<"\n";
          BSTNode *Curr = new BSTNode;
          Curr = find_min(a->right);
          int num = Curr->value;
          remove_element(root, root, Curr->value);
          if (before->value == a->value) {
            before->value = num;
          } 
          else if (before->left->value == a->value) {
            before->left->value = num;
          } 
          else {
            before->right->value = num;
          }
        }
      }
    }
  }
};