#ifndef _IP_VALUE_H_
#define _IP_VALUE_H_
#include <iostream>
#include <string>

class Ip_Value
{
private:
    std::string ip;
    int value;

public:
    Ip_Value();
    Ip_Value(std::string ip, int value);
    ~Ip_Value();
    std::string getIp();
    int getValue();
    void setValue(int value);
    bool operator<(const Ip_Value &other) const;
    bool operator>(const Ip_Value &other) const;
    bool operator==(const Ip_Value &other) const;
    bool operator!=(const Ip_Value &other) const;
    friend std::ostream &operator<<(std::ostream &out, const Ip_Value &ip_value);
};

Ip_Value::Ip_Value()
{
    ip = "";
    value = 0;
}

Ip_Value::Ip_Value(std::string ip, int value)
{
    this->ip = ip;
    this->value = value;
}

Ip_Value::~Ip_Value()
{
}

std::string Ip_Value::getIp()
{
    return ip;
}

int Ip_Value::getValue()
{
    return value;
}

void Ip_Value::setValue(int value)
{
    this->value = value;
}

bool Ip_Value::operator<(const Ip_Value &other) const
{
    return value < other.value;
}

bool Ip_Value::operator>(const Ip_Value &other) const
{
    return value > other.value;
}

bool Ip_Value::operator==(const Ip_Value &other) const
{
    return value == other.value;
}

bool Ip_Value::operator!=(const Ip_Value &other) const
{
    return value != other.value;
}

std::ostream &operator<<(std::ostream &out, const Ip_Value &ip_value)
{
    out << ip_value.ip << " " << ip_value.value;
    return out;
}

#endif // _IP_VALUE_H_
