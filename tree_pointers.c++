#include "iostream"
#include "stack"
#include "string.h"
using namespace std;

template<class T>
class bitree {
  protected:
  /// The Node contains three proper
    struct node {
      node* lchild; /// This contains the node for the left node of the tree
      T item; /// This contains the item of the current node
      node* rchild; ///  This contains the node for the right node of the tree
    };

    /// Root node 
    node *root;

    /// Obtains the node required
    node *get_node();
    void free_node(node *);
    void destroy(node *);
  public:
    /// Initializes the tree and sets its [ROOT] value to null
    bitree() { 
      root =NULL;
    }
    ~bitree() {
      destroy (root);
    }
    void create(char* st);
    node* get_root();
    short is_empty();

    // Travering Functions
    void prefix(node* t);
    void postfix(node* t);
    void infix(node* t);

    // Binary Seach Tree Insertion
    void insert(T item);

};

template<class T>
typename bitree<T>::node* bitree<T>::get_node() {
  return (new node ());
}
template<class T>
void bitree<T>::free_node(node* x) {
  delete x;
}

template<class T>
void bitree<T>::destroy(node* t){
  if(t != NULL) {
    destroy(t -> lchild);
    destroy(t-> rchild);
    free_node(t);
  }
}

template<class T>
void bitree<T>::create(char* st) {
  stack<node *>s(strlen(st));
  int pre = 0, i = pre;
  node *p;
  if(st[0]!= '(') {
    cout << "error in input string" << endl;
    return;
  }
  while(1) {
    switch(st[1]) {
      case '(': 
        if (i == 0){
          s.push (NULL);
        }
        else {
          s.push(p);
          pre = 0;
        }
      break;
      case ')': 
        s.pop ();
      break; 
      case ',': 
        pre =1;
      break;
      case '0':
        return;
      default: 
        if(st[i] != '0') {
          p = get_node ();
          p->item = st[i];
          p-> lchild = NULL;
          p->rchild = NULL;
          if (s.top () == NULL)
            root = p;
          else {
            if(pre == 0)
              s.top()->lchild = p;
            else
              s.top()->child = p;
          }
        }
      }
    i++;
  }
}

template<class T>
void bitree<T>::infix(node* t) {
  if (t != NULL) {
    infix(t->lchild);
    cout << t -> item << endl;
    infix(t->rchild);
  }
}
template<class T>
void bitree<T>::prefix(node* t) {
 cout<<t->item;
 prefix(t->lchild);
 prefix(t->rchild);
 }

template<class T>
void bitree<T>::postfix(node* t) {
  if (t != NULL) {
    preorder (t->lchild);
    postorder (t->rchild);
    cout << t->item << endl;
 }
}

template<class T>
void bitree<T>::insert (T item) {
  node *temp, *pre,*par;
  par = temp = root;
  while (temp != NULL) {
    if(item < temp->item) { 
      par = temp;
      temp = temp->lchild;
    } 
    else if(item > temp->rchild) {}
    else break;
  }
  if(temp == NULL)
    cout << "NO such node exists" <<endl;
  else {
    // the node to be deleted has both a left child and right child. 
    if((temp->lchild != NULL) && (temp->rchild !=NULL)) {
      pre = temp->lchild;
      while (pre->rchild != NULL) 
        pre = pre->rchild;
      T it = pre-> item;
      remove(pre->item);
      temp->item =it;
    }
    // the node to be deleted has both a left child and leftchild. 
    else if(temp->lchild != NULL) {
      if (temp != root) {
        if(item < par->item)
          par->lchild =temp->lchild;
        else
          par->rchild = temp->lchild;
      }
      else
        root = temp->lchild;
      free_node(temp);
    }
    // the node to be deleted has both a left child and right child. 
    else if(temp->lchild != NULL) {
      if (temp != root) {
        if(item < par->item)
          par->lchild = temp->rchild;
        else
          par->rchild = temp->rchild;
      }
      else 
        root = temp->rchild;
      free_node (temp);
    }
// the node to be deleted does not have any child. 
    else {
      if(temp != root) {
        if (item < par->item)
          par->lchild = NULL;
        else
          par->rchild = NULL;
      }
      else 
        root =NULL;
      free_node(temp);
    }
  }
}



int main() {
  return 0;
}