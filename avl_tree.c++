#include "iostream"
#include <algorithm>
#include <cstddef>
using namespace std;

/*
* This is the pointer implementation of an AVL tree, yeah, just don't ask I like pointers more than arrays and linked list
* This includes the functions that allow us to rotate a standard binary tree into the optimal AVL tree, use it when you have an assignment or when they ask us to use it

*/



template <class T> class AvlTree {
public:
  struct node {
    T data;
    node *lchild;
    node *rchild;
  };

  // inserting value into the tree
  node* insert(node* curr);

  // height of the tree from the current node
  int height(node *currentNode) {
    // check if the tree is null
    if (currentNode != NULL) {
      // obtains the height of the sub-trees under the node
      int l_height = height(currentNode->lchild);
      int r_height = height(currentNode->rchild);

      // checks which side is longer and sets it as the height of the tree
      int max_height = max(l_height, r_height);
      return (max_height + 1);
    }
  }
  // differences between the left and right level of the tree
  int difference(node*root) {

    // checks the height of the left and right 
    int l_height = height(root->lchild);
    int r_height = height(root->rchild);

    // obtaining the balance factor of the individual nodes of the tree
    int b_factor = l_height - r_height;
    return b_factor;
  }
  // rotation methods
  node *rr_rotation(node *parent) {
    // obtain the current parent node's right child [parent->rchild]
    node* tree = parent->rchild;

    // replace the [parent->rchild] with [temp->lchild];
    parent->rchild = tree->lchild;

    // make the parent the left child of the [temp] tree
    tree->lchild = parent;
    cout << "RR-rotation" << endl;
    return tree;
  }
  node *ll_rotation(node *parent) {
    
    node* tree = parent->lchild;
    
    parent->lchild = tree->rchild;

    tree->rchild = parent;
    
    return tree;
  }
  node *lr_rotation(node *parent) {
    
    node* tree = parent->rchild;

    parent->lchild = rr_rotation(tree);

    cout << "Right-Left Rotation";
    return ll_rotation(parent);
  }
  node *rl_rotation(node *parent) {


  }

  // show tree
  void displayOutput(node *curr, int length);

  // traversing the tree
  void inorder(node *curr) {
    inorder(curr->rchild);
    cout << curr->data << endl;
    inorder(curr->lchild);
  }
  void preorder(node *curr){
    cout << curr->data << endl;
    preorder(curr->lchild);
    preorder(curr->rchild);
  }
  void postorder(node *curr) {
    postorder(curr->lchild);
    postorder(curr->rchild);
    cout << curr->data << endl;
  }
};

int main(int argv, char **argc) {}
