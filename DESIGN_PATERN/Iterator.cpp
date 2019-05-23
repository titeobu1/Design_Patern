
#include "Iterator.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <iterator>
using namespace std;
class EmployeeIterator;

//Employee
Employee::Employee(string n, string d)
{
    name = n;
    devision = d;
}

void Employee::print()
{
    cout << "name: " << Employee::getName() << ", devision: " << devision << endl;
}

Employee::Employee(const Employee* other)
{
    Employee::name = other->name;
    Employee::devision = other->devision;
}
const Employee& Employee::operator=(const Employee other)
{
    Employee::name = other.name;
    Employee::devision = other.devision;
    return *this;
}

Iterator *Employee::iterator()
{
    return new EmployeeIterator();
}

//EmployeeIterator
EmployeeIterator::EmployeeIterator(Employee *_emp)
{
    EmployeeIterator::emp = _emp;
}

EmployeeIterator::EmployeeIterator()
{
}
Corporate *EmployeeIterator::next() 
{
    return EmployeeIterator::emp;
}
bool EmployeeIterator::hasNext()
{
    return false;
}

// DevisionIterator
DevisionIterator::DevisionIterator(std::array<Employee*,MAX_EMP_DEVISION> _emps)
{
    DevisionIterator::emps = _emps;
    DevisionIterator::currentIndex = 0;
}

Corporate *DevisionIterator::next()
{
    return DevisionIterator::emps[currentIndex++];
}

bool DevisionIterator::hasNext()
{
    return (DevisionIterator::emps.size() > DevisionIterator::currentIndex && DevisionIterator::emps[currentIndex]->name != "")  ? true : false;
}

// Devision
Devision::Devision(string n)
{
    Devision::name = n;
    Devision::number_emps = 0;
}
void Devision::add(Corporate *emp)
{
    Devision::emps[Devision::number_emps++] = static_cast<Employee*>(emp);
}

Iterator *Devision::iterator()
{
    return new DevisionIterator(emps);
}

void Devision::print()
{
    Iterator *ite = Devision::iterator();
    while(ite->hasNext())
    {
        Employee *emp = static_cast<Employee*>(ite->next());
        emp->print();
    }
}

