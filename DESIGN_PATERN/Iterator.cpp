#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <iterator>
using namespace std;

const int MAX_EMP_DEVISION = 5;

class Employee
{
public:
    string name;
    string devision;
    Employee(){} // NEED A DEFAULT CONSTRUCTOR TO INIT AN ARRAY OF OBJECT
    Employee(string n, string d)
    {
        name = n;
        devision = d;
    }

    void print()
    {
        cout << "name: " << name << ", devision: " << devision << endl;
    }

    Employee(const Employee& other)
    {
        this->name = other.name;
        this->devision = other.devision;
    }
    const Employee& operator=(const Employee other)
    {
        this->name = other.name;
        this->devision = other.devision;
        return *this;
    }
};

template <typename T>
class Iterator
{
public:
    Iterator(){}
    virtual T next() = 0;
    virtual bool hasNext() = 0;
};

class DevisionIterator : public Iterator<Employee>
{
public:
    std::array<Employee,MAX_EMP_DEVISION> emps;
    int currentIndex;
    DevisionIterator(std::array<Employee,MAX_EMP_DEVISION> _emps)
    {
        emps = _emps;
        currentIndex = 0;
    }

    virtual Employee next() override
    {
        return emps[currentIndex++];
    }

    virtual bool hasNext() override
    {
        return (emps.size() > currentIndex && emps[currentIndex].name != "")  ? true : false;
    }

};

class Devision
{
public:
    string name;
    std::array<Employee,MAX_EMP_DEVISION> emps;
    int number_emps;
    Devision(string n)
    {
        name = n;
        number_emps = 0;
    }
    void addMem(Employee emp)
    {
        emps[number_emps++] = emp;
    }

    string getName()
    {
        return name;
    }

    DevisionIterator iterator()
    {
        return DevisionIterator(emps);
    }
};


