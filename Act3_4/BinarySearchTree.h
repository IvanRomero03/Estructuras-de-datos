#ifndef _BIN_SEARCH_TREE_H
#define _BIN_SEARCH_TREE_H

#include <iostream>
#include <queue>
#include <unordered_map>

template <class T>
class BinarySearchTree
{
private:
    int size;
    struct Node
    {
        T val;
        Node *left;
        Node *right;
        Node(T val, Node *left, Node *right)
        {
            this->val = val;
            this->left = left;
            this->right = right;
        }
        Node()
        {
            this->val = T();
            this->left = nullptr;
            this->right = nullptr;
        }
        Node(T val)
        {
            this->val = val;
            this->left = nullptr;
            this->right = nullptr;
        }
        std::ostream &operator<<(std::ostream &os)
        {
            os << this->val;
            return os;
        }
    };
    Node *root;

    void printInOrder(Node *node)
    {
        if (root == nullptr)
        {
            std::cout << "El arbol está vacío" << std::endl;
            return;
        }
        if (node == nullptr)
        {
            return;
        }
        if (node->left != nullptr)
        {
            printInOrder(node->left);
        }
        std::cout << node->val << std::endl;
        if (node->right != nullptr)
        {
            printInOrder(node->right);
        }
    }
    void printPreOrder(Node *node)
    {
        if (root == nullptr)
        {
            std::cout << "El arbol está vacío" << std::endl;
            return;
        }
        if (node == nullptr)
        {
            return;
        }
        std::cout << node->val << std::endl;
        if (node->left != nullptr)
        {
            printPreOrder(node->left);
        }
        if (node->right != nullptr)
        {
            printPreOrder(node->right);
        }
    }
    void printPostOrder(Node *node)
    {
        if (root == nullptr)
        {
            std::cout << "El arbol está vacío" << std::endl;
            return;
        }
        if (node == nullptr)
        {
            return;
        }
        if (node->left != nullptr)
        {
            printPostOrder(node->left);
        }
        if (node->right != nullptr)
        {
            printPostOrder(node->right);
        }
        std::cout << node->val << std::endl;
    }
    void printLevelOrder()
    {
        if (root == nullptr)
        {
            std::cout << "El arbol está vacío" << std::endl;
            return;
        }
        std::queue<Node *> q;
        q.push(root);
        int level = 1;
        while (!q.empty())
        {
            int size = q.size();
            std::cout << "Level: ";
            for (int i = 0; i < size; i++)
            {
                Node *temp = q.front();
                q.pop();
                if (temp->left != nullptr)
                {
                    q.push(temp->left);
                }
                if (temp->right != nullptr)
                {
                    q.push(temp->right);
                }
                std::cout << temp->val << " ";
            }
            level++;
            std::cout << std::endl;
        }
    }

public:
    BinarySearchTree();
    ~BinarySearchTree();
    void clear();
    void insert(T val);
    void deleteNode(T val);
    void print();
    bool find(T val);
    void visit();
    int height();
    void ancestors(T val);
    bool mark(Node *node, T val, std::unordered_map<T, bool> &marked);
    int whatLevelAmI(T val);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = nullptr;
    size = 0;
}

template <class T>
void BinarySearchTree<T>::clear()
{
    std::queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left != nullptr)
        {
            q.push(temp->left);
        }
        if (temp->right != nullptr)
        {
            q.push(temp->right);
        }
        delete temp;
    }
    root = nullptr;
    size = 0;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    clear();
}

template <class T>
void BinarySearchTree<T>::insert(T val)
{
    Node *newNode = new Node(val);
    if (root == nullptr)
    {
        root = newNode;
        size++;
        return;
    }
    Node *current = root;
    Node *prev = nullptr;
    while (current != nullptr)
    {
        prev = current;
        if (val == current->val)
        {
            std::cout << "El valor ya existe en el árbol" << std::endl;
            return;
        }
        if (val < current->val)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    if (val < prev->val)
    {
        prev->left = newNode;
    }
    else
    {
        prev->right = newNode;
    }
    size++;
}

template <class T>
void BinarySearchTree<T>::deleteNode(T val)
{
    Node *current = root;
    Node *prev = nullptr;
    while (current != nullptr)
    {
        if (val == current->val)
        {
            break;
        }
        prev = current;
        if (val < current->val)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    if (current == nullptr)
    {
        std::cout << "El valor no existe en el árbol" << std::endl;
        return;
    }
    if (current->left == nullptr && current->right == nullptr)
    {
        if (prev == nullptr)
        {
            root = nullptr;
        }
        else
        {
            if (prev->left == current)
            {
                prev->left = nullptr;
            }
            else
            {
                prev->right = nullptr;
            }
        }
        delete current;
    }
    else if (current->left == nullptr || current->right == nullptr)
    {
        Node *temp = current->left == nullptr ? current->right : current->left;
        if (prev == nullptr)
        {
            root = temp;
        }
        else
        {
            if (prev->left == current)
            {
                prev->left = temp;
            }
            else
            {
                prev->right = temp;
            }
        }
        delete current;
    }
    else
    {
        Node *temp = current->right;
        Node *tempPrev = current;
        while (temp->left != nullptr)
        {
            tempPrev = temp;
            temp = temp->left;
        }
        current->val = temp->val;
        if (tempPrev->left == temp)
        {
            tempPrev->left = temp->right;
        }
        else
        {
            tempPrev->right = temp->right;
        }
        delete temp;
    }
    size--;
}

template <class T>
void BinarySearchTree<T>::print()
{
    std::queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        std::cout << temp->val << " ";
        if (temp->left != nullptr)
        {
            q.push(temp->left);
        }
        if (temp->right != nullptr)
        {
            q.push(temp->right);
        }
    }
    std::cout << std::endl;
}

template <class T>
bool BinarySearchTree<T>::find(T val)
{
    Node *current = root;
    while (current != nullptr)
    {
        if (val == current->val)
        {
            return true;
        }
        if (val < current->val)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return false;
}

template <class T>
void BinarySearchTree<T>::visit()
{
    std::cout << "El árbol tiene " << size << " nodos" << std::endl;
    std::cout << "Escoja una opción:" << std::endl;
    std::cout << "1. Preorder" << std::endl;
    std::cout << "2. Inorder" << std::endl;
    std::cout << "3. Postorder" << std::endl;
    std::cout << "4. Level by Lever" << std::endl;
    int option;
    std::cin >> option;
    switch (option)
    {
    case 1:
        printPreOrder(root);
        break;
    case 2:
        printInOrder(root);
        break;
    case 3:
        printPostOrder(root);
        break;
    case 4:
        printLevelOrder();
        break;
    default:
        std::cout << "Opción inválida" << std::endl;
        break;
    }
}

template <class T>
int BinarySearchTree<T>::height()
{
    std::queue<Node *> level;
    level.push(root);
    int height = 0;
    while (!level.empty())
    {
        int size = level.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = level.front();
            level.pop();
            if (temp->left != nullptr)
            {
                level.push(temp->left);
            }
            if (temp->right != nullptr)
            {
                level.push(temp->right);
            }
        }
        height++;
    }
    return height;
}

template <class T>
bool BinarySearchTree<T>::mark(Node *node, T val, std::unordered_map<T, bool> &marked)
{
    if (node == nullptr)
    {
        return false;
    }
    if (node->val == val)
    {
        marked[node->val] = true;
        return true;
    }
    bool found = false;
    found += mark(node->left, val, marked);
    found += mark(node->right, val, marked);

    if (found)
    {
        marked[node->val] = true;
        return true;
    }
    return false;
}

template <class T>
void BinarySearchTree<T>::ancestors(T val)
{
    std::unordered_map<T, bool> marked;
    bool found = mark(root, val, marked);
    if (!found)
    {
        std::cout << "El nodo no existe en el BST" << std::endl;
        return;
    }
    Node *current = root;
    std::cout << "Los ancestros del nodo son: ";
    while (current != nullptr)
    {
        std::cout << current->val << " ";
        if (current->left != nullptr && marked[current->left->val])
        {
            current = current->right;
        }
        else
        {
            if (current->right != nullptr && marked[current->right->val])
            {
                current = current->left;
            }
            else
            {
                std::cout << std::endl;
                return;
            }
        }
    }

    return;
}

template <class T>
int BinarySearchTree<T>::whatLevelAmI(T val)
{
    Node *current = root;
    int level = 0;
    while (current != nullptr)
    {
        if (val == current->val)
        {
            return level;
        }
        level++;
        if (val < current->val)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    return -1;
}

#endif // _BIN_SEARCH_TREE_H