#ifndef Iterator_hpp
#define Iterator_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <iterator>

using namespace std;
class Corporate;

const int MAX_EMP_DEVISION = 3;

class Iterator
{
public:
    Iterator(){}
    virtual Corporate *next() = 0;
    virtual bool hasNext() = 0;
};

class Corporate
{
public:
    string name;
    Corporate(){}
    Corporate(string n){ name = n;}
    string getName() {
        return name;
    };
    virtual void add(Corporate *c) = 0;
    virtual void print() = 0;
    virtual Iterator *iterator() = 0;
};

class Employee : public Corporate
{
public:
    string devision;
    Employee(){} // NEED A DEFAULT CONSTRUCTOR TO INIT AN ARRAY OF OBJECT
    Employee(string n, string d);

    void print() override;
    virtual void add(Corporate *c) override{};

    Employee(const Employee* other);
    const Employee& operator=(const Employee other);

    virtual Iterator *iterator() override;
};

class EmployeeIterator : public Iterator
{
public:
    Employee *emp;
    EmployeeIterator(Employee *_emp);

    EmployeeIterator();
    virtual Corporate *next() override;
    virtual bool hasNext() override;
};

class DevisionIterator : public Iterator
{
public:
    std::array<Employee*,MAX_EMP_DEVISION> emps;
    int currentIndex;
    DevisionIterator(std::array<Employee*,MAX_EMP_DEVISION> _emps);

    virtual Corporate *next() override;
    virtual bool hasNext() override;
};

class Devision : public Corporate
{
public:
    std::array<Employee*,MAX_EMP_DEVISION> emps;
    int number_emps;
    Devision(){}
    Devision(string n);
    virtual void add(Corporate *emp) override;
    virtual void print() override;

    virtual Iterator *iterator() override;
};

#endif /* Iterator_hpp */