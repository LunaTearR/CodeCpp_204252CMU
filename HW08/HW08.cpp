#include "BSTNode.cpp"
#include<iostream>
using namespace std;
class BST {

public:
  BSTNode *root,*pre,*p,*prev,*temp;
  
  BST() {
    root = NULL;
    pre = NULL;
    p = NULL;
    prev = NULL;
    temp = NULL;
  }

  void insert(int value) {
    BSTNode *new_node = new BSTNode();
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
    string previous;
    // BSTNode *min = new BSTNode();
    p = root;
    prev = root;
    //don't have node in tree
    if (root == NULL){
        return ;
    }
    //tree don't have value
    if(!search_value(root,value)){
      return ;
    }
    //remove child node
    if(value != root -> value){
      //find node for delete
      while (p -> value != value){
        prev = p;
        if(value < p -> value){
          p = p -> left;
          previous = "left";
        }
        //value >= p -> value
        else{
          p = p -> right;
          previous = "right";
        }
      }
      //remove leaf node
      if(p -> left == NULL && p -> right == NULL){
        if(previous == "left"){
          prev -> left = NULL;
        }
        //previous == "right"
        else{
          prev -> right = NULL;
        }
        free(p);
      }
      //remove node with 1 child
      //node has right child
      else if(p -> right != NULL && p -> left == NULL){
        //child have no child
        if (p -> right -> left == NULL && p -> right -> left == NULL){
          if(previous == "left"){
            prev -> left = p -> right;
          }
          //previous == "right"
          else{
            prev -> right = p ->right;
          }
          free(p);
         }
         //child have another child
         else {
          temp = find_min(p -> right);
          if(temp -> left == NULL && temp -> right == NULL){
            if(pre -> left == temp){
              p -> value = temp -> value;
              
            }
            else{

            }
          }
         }
        }
      //node has left child
      else if(p -> left != NULL && p -> right == NULL){
        if(previous == "left"){
          p = prev -> left;
          prev -> left = p -> left;
        }
        //previous == "right"
        else{
          p = prev -> right;
          prev -> right = p -> left;
        }
        free(p);
      }
      //remove node with 2 child
      else{
        if(p->right->left != NULL){
          if (prev -> left -> value = value){
            p = prev -> left;
          }
          else{
            p = prev -> right;
          }
          temp = p -> right;
          p -> value = temp -> value;
          p -> right = temp -> left;
          free(temp);
        }
        else if(p -> right -> right == NULL){
          if (prev -> left -> value = value){
            p = prev -> left;
          }
          else{
            p = prev -> right;
          }
          temp = p -> right;
          p -> value = temp -> value;
          p -> right = temp -> right;
          free(temp);
        }
        else{
          if (prev -> left -> value = value){
              p = prev -> left;
          }
          else{
              p = prev -> right;
          }
          temp = find_min(p ->right);
          p -> value = temp -> value;
          pre -> left = NULL;
          free(temp);        
        }
      }
    }
    //remove root node
    else{
      p = root;
      //root no child
      if(root -> left == NULL && root -> right == NULL){
        delete root;
        root = NULL;

        return ;
      }
      else if (root -> right == NULL && root -> left != NULL){
        temp = find_max(root -> left);
        root -> value = temp -> value;
        free(temp);

      }

      else if(root -> right != NULL){
        temp = root -> right;
        while(temp != NULL && temp->left != NULL)
          pre = temp;
          temp = temp->left;
        root -> value = temp -> value;
        pre -> left = NULL;
        free(temp);      
      }
    }
  }

  BSTNode* find_min(BSTNode* node){
    BSTNode *min = new BSTNode();
    min = node;
    while(min != NULL && min->left != NULL)
      pre = min;
      min = min->left;
    return min;
  }

  BSTNode* find_max(BSTNode* node){
  BSTNode *max = new BSTNode();
  max = node;
  while(max != NULL && max->right != NULL)
    pre = max;
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
   while(temps != NULL) {
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
};
