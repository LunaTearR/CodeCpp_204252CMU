#include "BSTNode.cpp"
#include<iostream>

using namespace std;
class BST {

public:
  BSTNode* root;
  
  BST() {
    root = nullptr;
    
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
    
  }

  int get_depth(int value) {
    BSTNode *p,*prev;
    int depth = 0;
    if (value == root -> value){
      return depth;
    }
    if(!checkValue(root,value)){
      return -1;
    }
    p = root;
    while (p -> value != value){
      if(p -> value > value){
        p = p -> left;
        depth++;
      }
      else {
        p = p -> right;
        depth++;
      }
    }
    return depth;
  }

  bool checkValue(BSTNode* node, int key){
    if (node == NULL)
        return false;
 
    if (node -> value == key)
        return true;
 
    /* check on left subtree */
    bool res1 = checkValue(node -> left, key);
    // node found, no need to look further
    if(res1) return true;
 
    /* node is not found in left,
    so check on right subtree */
    bool res2 = checkValue(node -> right, key);

    return res2;
  }

  void show(){
    BSTNode *p;
    p = root;
    while (p != NULL){
      cout << p -> value << endl;
      p = p -> left;
    }
    p = root;
    while (p != NULL){
      cout << p -> value << endl;
      p = p -> right;
    }
  }

};
