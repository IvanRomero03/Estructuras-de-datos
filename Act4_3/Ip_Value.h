#pragma once
#include <iostream>
#include <string>

struct Ip_Value
{
    std::string ip;
    int value;
    Ip_Value(std::string ip, int value) : ip(ip), value(value) {}
    bool operator<(const Ip_Value &other) const
    {
        return value < other.value;
    }
    bool operator>(const Ip_Value &other) const
    {
        return value > other.value;
    }
    bool operator==(const Ip_Value &other) const
    {
        return value == other.value;
    }
};
