// g++ -std=c++17 -Wall -O3 -o main *.cpp


#include <iostream>
#include "BinarySearchTree.h"

int main()
{
    std::cout << "Ejemplo de un Binary Search Tree (BST)\n";

  BinarySearchTree<int> myBST;
  myBST.insert(10);
  myBST.insert(20);
  myBST.insert(30);
  myBST.insert(15);
  myBST.insert(5);
  myBST.insert(115);
  myBST.insert(3);
  myBST.insert(3);
  

  myBST.print();
  // myBST.print
  // myBST.printPreOrder();
  // myBST.printPostOrder();
  // myBST.printInOrder();

 
  std::cout << "search(15) " << std::boolalpha << myBST.find(15) << std::endl;
  std::cout << "search(22) " << std::boolalpha << myBST.find(22) << std::endl;
  std::cout << "search(3) " << std::boolalpha << myBST.find(3) << std::endl;
  
  // Borrar nodo sin hijos
  std::cout << "deleteNode(115) " << std::endl;
  myBST.deleteNode(115);
  myBST.print();

  // Borrar nodo con un hijo
  std::cout << "deleteNode(5) " << std::endl;
  myBST.deleteNode(5);
  myBST.print();

  // Borrar nodo con dos hijos
  std::cout << "deleteNode(20) " << std::endl;
  myBST.deleteNode(20);
  myBST.print();

  myBST.visit();
  myBST.height();

  myBST.ancestors(3);

  std::cout<<"level (3): "<<myBST.whatLevelAmI(3)<<std::endl;
  std::cout<<"level (10): "<<myBST.whatLevelAmI(10)<<std::endl;
}
