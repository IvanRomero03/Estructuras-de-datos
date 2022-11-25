#ifndef _HASH_NODE_H_
#define _HASH_NODE_H_

#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include "NodeInfo.h"

class HashNode
{
private:
    std::string ip;
    NodeInfo data;
    int status;
    std::vector<int> overflow;

public:
    HashNode();
    HashNode(std::string ip);
    std::string getIp();
    void setIp(std::string ip);
    NodeInfo getData();
    void setData(NodeInfo data);
    void addOut(std::string ip);
    void addIn(std::string ip);
    int getStatus();
    void setStatus(int);
    void clearData();
    void addToOverflow(int hashIndex);
    int getOverflowSize();
    int getOverflowAt(int index);
    void removeFromOverflow(int value);
};

HashNode::HashNode()
{
    this->ip = "";
    this->status = 0;
}

HashNode::HashNode(std::string ip)
{
    this->ip = ip;
    this->status = 1;
    this->data = NodeInfo(ip);
}

std::string HashNode::getIp()
{
    return ip;
}
void HashNode::setIp(std::string ip)
{
    this->ip = ip;
}

NodeInfo HashNode::getData()
{
    return data;
}
void HashNode::setData(NodeInfo data)
{
    this->data = data;
}

void HashNode::addOut(std::string ip)
{
    data.addOut(ip);
}

void HashNode::addIn(std::string ip)
{
    data.addIn(ip);
}

int HashNode::getStatus()
{
    return status;
}

void HashNode::setStatus(int status)
{
    this->status = status;
}

void HashNode::clearData()
{
    ip = "";
    data = NodeInfo();
    status = 2;
    overflow.clear();
}

void HashNode::addToOverflow(int hashIndex)
{
    overflow.push_back(hashIndex);
}

int HashNode::getOverflowSize()
{
    return overflow.size();
}

int HashNode::getOverflowAt(int index)
{
    return overflow[index];
}

void HashNode::removeFromOverflow(int value)
{
    overflow.erase(
        std::remove(
            overflow.begin(), overflow.end(), value),
        overflow.end());
}

#endif // _HASH_NODE_H_