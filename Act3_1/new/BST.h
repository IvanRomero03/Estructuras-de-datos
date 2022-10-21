#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include "BSTNode.h"

template <class T> 
class BST {
  private:
    BSTNode<T> *root;
    BSTNode<T>* insertRecursive(BSTNode<T> *p, T value);
    BSTNode<T>* getSuccessor(BSTNode<T> *p);
    BSTNode<T>* deleteRecursive(BSTNode<T> *p, T value);
    void print2D(BSTNode<T> *p, int space);
    void recursiveInorder(BSTNode<T> *p);
    void recursivePostorder(BSTNode<T> *p);
    void recursivePreorder(BSTNode<T> *p);

  public:
    BST();
    ~BST();
    void clearMemory(BSTNode<T> *p);
    bool search(T value);
    void insert(T value);
    void deleteNode(T value);
    void print();
    void inorder();
    void postorder();
    void preorder();
    void LevelOrder();
    void visit();
    int height(BSTNode<T> *p);

};

template <class T>
BST<T>::BST() {
  //std::cout << "---> Creando un BinarySearchTree vacio: " <<  this << std::endl;
  root = nullptr;
}
  
template <class T>
BST<T>::~BST() {
  //std::cout << "---> Liberando memoria del BinarySearchTree: " << this << std::endl;
  clearMemory(root);
}

template <class T>
void BST<T>::clearMemory(BSTNode<T> *p) {
  if (p != nullptr) {
    clearMemory(p->left);
    clearMemory(p->right);
    delete p;
    p = nullptr;
  }
}

template <class T>
bool BST<T>::search(T value) {
  BSTNode<T> *p = root;
  while (p != nullptr) {
    if (p->data == value) {
      return true;
    }
    else {
      p = (value < p->data ? p->left : p->right);
    }
  }
  return false;
}

template <class T>
BSTNode<T>* BST<T>::insertRecursive(BSTNode<T> *p, T value) {
  if (p == nullptr) // El BST esta vacio
    p = new BSTNode<T>(value);
  else if (value < p->data)
    p->left = insertRecursive(p->left, value);
  else if (value > p->data)
    p->right = insertRecursive(p->right, value);
  else
    std::cout << "El elemento " << value << " ya existe en el BST" << std::endl;
  return p;
}

template <class T>
void BST<T>::insert(T value) {
  root = insertRecursive(root, value);
}

template <class T>
BSTNode<T> * BST<T>::getSuccessor(BSTNode<T> *p) {
  BSTNode<T> *current = p;
  while (current && current->left != nullptr) {
    current = current->left;
  }
  return current;
}

template <class T>
BSTNode<T>* BST<T>::deleteRecursive(BSTNode<T> *p, T value) {
  BSTNode<T> *current = p;
  // caso base, arbol vacio
  if (p == nullptr)
    return p;
  if (value < p->data)
    p->left = deleteRecursive(p->left, value);
  else if (value > p->data)
    p->right = deleteRecursive(p->right, value);
  else { // Hemos localizado el nodo a borrar
    // El nodo a borrar no tiene ningun hijo
    if (p->left == nullptr && p->right == nullptr) {
      delete p;
      p = nullptr;
      return p;
    }
    else if (p->left == nullptr) { // El nodo a borrar solo tiene hijo derecho
      current = p->right;
      delete p;
      p = nullptr;
      return current;
    } 
    else if (p->right == nullptr) { // El nodo a borrar solo tiene hijo izquierdo
      current = p->left;
      delete p;
      p = nullptr;
      return current;
    }
    // El nodo a borrar tiene dos hijos
    current = getSuccessor(p->right);
    p->data = current->data;
    p->right = deleteRecursive(p->right, current->data);
  }
  return p;
}

template <class T>
void BST<T>::deleteNode(T value) {
   root = deleteRecursive(root, value);
}

template <class T>
void BST<T>::print2D(BSTNode<T> *root, int space) {
    // Caso base
    if (root == nullptr)
        return;
    // Incrementa la distancia entre niveles
    space += 5;
 
    // Procesa hijo derecho
    print2D(root->right, space);
    // Imprime el nodo actual despues de los espacios necesarios
    std::cout << std::endl;
    for (int i = 5; i < space; i++)
        std::cout << " ";
    std::cout << root->data << std::endl;
    // Procesa el hijo izquierdo 
    print2D(root->left, space);
}

template <class T>
void BST<T>::print() {
    print2D(root, 0);
}

template <class T>
void BST<T>::recursiveInorder(BSTNode<T> *p) {
  if (p != nullptr) {
    recursiveInorder(p->left);
    std::cout << p->data << " ";
    recursiveInorder(p->right);
  }
}

template <class T>
void BST<T>::inorder() {
    std::cout << "inorder():" << std::endl;
    recursiveInorder(root);
    std::cout << std::endl;
}

template <class T>
void BST<T>::recursivePostorder(BSTNode<T> *p) {
  if (p != nullptr) {
    recursivePostorder(p->left);
    recursivePostorder(p->right);
    std::cout << p->data << " ";
  }
}

template <class T>
void BST<T>::postorder() {
    std::cout << "postorder():" << std::endl;
    recursivePostorder(root);
    std::cout << std::endl;
}

template <class T>
void BST<T>::recursivePreorder(BSTNode<T> *p) {
  if (p != nullptr) {
    std::cout << p->data << " ";
    recursivePreorder(p->left);
    recursivePreorder(p->right);
  }
}

template <class T>
void BST<T>::preorder() {
    std::cout << "preorder():" << std::endl;
    recursivePreorder(root);
    std::cout << std::endl;
}

/*
template <class T>
void LevelOrder()
{
    if(root == nullptr){
        std::cout << "El arbol está vacío" << std::endl;
        return;
    }   
    std::queue<Node*> q;
    q.push(root);
    int level = 1;
    while(!q.empty()){
        int size = q.size();
        std::cout << "Level: ";
        for(int i = 0; i < size; i++){
            Node* temp = q.front();
            q.pop();
            if(temp->left != nullptr){
                q.push(temp->left);
            }
            if(temp->right != nullptr){
                q.push(temp->right);
            }
            std::cout << temp->val << " ";
        }
        level++;
        std::cout << std::endl;
    }
}
*/

template <class T>
void BST<T>::visit()
{
    std::cout << "Escoja una opción:" << std::endl;
    std::cout << "1. Preorder" << std::endl;
    std::cout << "2. Inorder" << std::endl;
    std::cout << "3. Postorder" << std::endl;
    std::cout << "4. Level by Lever" << std::endl;
    int option;
    std::cin >> option;
    switch(option){
        case 1:
            preorder();
            break;
        case 2:
            inorder();
            break;
        case 3:
            postorder();
            break;
        case 4:
            //LevelOrder();
            break;
        default:
            std::cout << "Opción inválida" << std::endl;
            break;
    }
    
}

/*
template <class T>
int BST<T>::height(BSTNode<T>* root)
{
int depth = 0;
 
    queue<Node*> q;
 
    // Pushing first level element along with NULL
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        Node* p = q.front();
        q.pop();
 
        // When NULL encountered, increment the value
        if (p == NULL) {
            depth++;
        }
 
        // If NULL not encountered, keep moving
        if (p != NULL) {
            if (p->left) {
                q.push(p->left);
            }
            if (p->right) {
                q.push(p->right);
            }
        }
 
        // If queue still have elements left,
        // push NULL again to the queue.
        else if (!q.empty()) {
            q.push(NULL);
        }
    }
    return depth;
}
*/

template <class T>
int BST<T>::height(BSTNode<T>* root)
{
    if (root == nullptr)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = height(root->left);
        int rDepth = height(root->right);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}
#endif  //_BST_H_
