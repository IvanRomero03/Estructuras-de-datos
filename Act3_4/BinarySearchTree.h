#ifndef _BIN_SEARCH_TREE_H
#define _BIN_SEARCH_TREE_H

#include <iostream>
#include <queue>
#include <unordered_map>
#include "Node.h"
#include "Registro_Count.h"
#include "Registro.h"

class BinarySearchTree
{
private:
    int size;
    Node<Registro_Count> *root;
    void clear_helper(Node<Registro_Count> *node);
    void remove_helper(Node<Registro_Count> *node, Registro_Count data);
    void print_helper(Node<Registro_Count> *node);
    bool find_helper(Node<Registro_Count> *node, Registro_Count data);

public:
    BinarySearchTree();
    ~BinarySearchTree();
    void clear();
    void insert(Registro_Count val);
    void deleteNode(Registro_Count val);
    void print();
    bool find(Registro_Count val);
    bool find(Registro val);
    void addAt(Registro val);
    Registro_Count getBiggest();
};

BinarySearchTree::BinarySearchTree()
{
    // O(1)
    size = 0;
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    // O(1)
    clear();
}

void BinarySearchTree::clear()
{
    // O(n)
    clear_helper(root);
}

void BinarySearchTree::clear_helper(Node<Registro_Count> *node)
{
    // O(n)
    if (node == nullptr)
    {
        return;
    }
    clear_helper(node->getLeft());
    clear_helper(node->getRight());
    delete node;
}

void BinarySearchTree::insert(Registro_Count val)
{
    // O(log n)
    if (root == nullptr)
    {
        root = new Node<Registro_Count>(val);
        size++;
        return;
    }
    Node<Registro_Count> *current = root;
    while (current != nullptr)
    {
        if (val == current->getData())
        {
            Node<Registro_Count> *temp = current;
            while (temp->getRight() != nullptr)
            {
                temp = temp->getRight();
            }
            temp->setRight(new Node<Registro_Count>(val));
            return;
        }
        else if (val < current->getData())
        {
            if (current->getLeft() == nullptr)
            {
                current->setLeft(new Node<Registro_Count>(val));
                size++;
                return;
            }
            current = current->getLeft();
        }
        else
        {
            if (current->getRight() == nullptr)
            {
                current->setRight(new Node<Registro_Count>(val));
                size++;
                return;
            }
            current = current->getRight();
        }
    }
}

void BinarySearchTree::deleteNode(Registro_Count val)
{
    // O(log n)
    remove_helper(root, val);
}

void BinarySearchTree::remove_helper(Node<Registro_Count> *node, Registro_Count data)
{
    // O(log n)
    if (node == nullptr)
    {
        return;
    }
    if (data < node->getData())
    {
        remove_helper(node->getLeft(), data);
    }
    else if (data > node->getData())
    {
        remove_helper(node->getRight(), data);
    }
    else
    {
        if (node->getData().getRegistro() == data.getRegistro())
        {
            if (node->getLeft() == nullptr && node->getRight() == nullptr)
            {
                delete node;
                size--;
                return;
            }
            else if (node->getLeft() != nullptr && node->getRight() == nullptr)
            {
                Node<Registro_Count> *temp = node->getLeft();
                node->setData(temp->getData());
                node->setLeft(temp->getLeft());
                node->setRight(temp->getRight());
                delete temp;
                size--;
                return;
            }
            else if (node->getLeft() == nullptr && node->getRight() != nullptr)
            {
                Node<Registro_Count> *temp = node->getRight();
                node->setData(temp->getData());
                node->setLeft(temp->getLeft());
                node->setRight(temp->getRight());
                delete temp;
                size--;
                return;
            }
            else
            {
                Node<Registro_Count> *temp = node->getRight();
                while (temp->getLeft() != nullptr)
                {
                    temp = temp->getLeft();
                }
                node->setData(temp->getData());
                remove_helper(node->getRight(), temp->getData());
                return;
            }
        }
        else
        {
            remove_helper(node->getRight(), data);

            // remove_helper(node->getLeft(), data);
            //  FIXME: remove_helper(node->getRight(), data);
        }
    }
}

void BinarySearchTree::print()
{
    // O(n)
    print_helper(root);
}

void BinarySearchTree::print_helper(Node<Registro_Count> *node)
{
    // O(n)
    if (node == nullptr)
    {
        return;
    }
    std::cout << node->getData() << " ";
    print_helper(node->getLeft());
    print_helper(node->getRight());
}

bool BinarySearchTree::find(Registro_Count val)
{
    // O(log n)
    return find_helper(root, val);
}

bool BinarySearchTree::find(Registro val)
{
    // O(n)
    if (root == nullptr)
    {
        return false;
    }
    std::queue<Node<Registro_Count> *> q;
    q.push(root);
    while (!q.empty())
    {
        Node<Registro_Count> *current = q.front();
        q.pop();
        if (current->getData().getRegistro() == val)
        {
            return true;
        }
        if (current->getLeft() != nullptr)
        {
            q.push(current->getLeft());
        }
        if (current->getRight() != nullptr)
        {
            q.push(current->getRight());
        }
    }
    return false;
}

void BinarySearchTree::addAt(Registro val)
{
    // O(n)
    if (root == nullptr)
    {
        throw std::runtime_error("Empty tree");
    }
    std::queue<Node<Registro_Count> *> q;
    q.push(root);
    while (!q.empty())
    {
        Node<Registro_Count> *current = q.front();
        q.pop();
        if (current->getData().getRegistro() == val)
        {
            Registro temp = current->getData().getRegistro();
            int count = current->getData().getCount();
            deleteNode(current->getData());
            insert(Registro_Count(temp, count + 1));
            return;
        }
        if (current->getLeft() != nullptr)
        {
            q.push(current->getLeft());
        }
        if (current->getRight() != nullptr)
        {
            q.push(current->getRight());
        }
    }
}

bool BinarySearchTree::find_helper(Node<Registro_Count> *node, Registro_Count data)
{
    // O(log n)
    if (node == nullptr)
    {
        return false;
    }
    if (data < node->getData())
    {
        return find_helper(node->getLeft(), data);
    }
    else if (data > node->getData())
    {
        return find_helper(node->getRight(), data);
    }
    else
    {
        return true;
    }
}

Registro_Count BinarySearchTree::getBiggest()
{
    // O(log n)
    Node<Registro_Count> *temp = root;
    if (temp == nullptr)
    {
        std::cout << "Empty tree" << std::endl;
        return Registro_Count();
    }
    while (temp->getRight() != nullptr)
    {
        temp = temp->getRight();
    }
    return temp->getData();
}

#endif // _BIN_SEARCH_TREE_H