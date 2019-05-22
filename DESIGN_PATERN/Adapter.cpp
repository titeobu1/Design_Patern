#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class SimpleName
{
public:
    string name;
    SimpleName(string _name)
    {
        name = _name;
    }
    void setName(string _name)
    {
        name = _name;
    }
    string getName()
    {
        return name;
    }
};

class ComplexName
{
public:
    string firstName;
    string lastName;
    void setFirstName(string _firstName)
    {
        firstName = _firstName;
    }
    string getFirstName()
    {
        return firstName;
    }
    void setLastName(string _lastName)
    {
        lastName = _lastName;
    }
    string getLastName()
    {
        return lastName;
    }
};

class AdapterToComplexName: public ComplexName
{
public:
    AdapterToComplexName(SimpleName simpleName)
    {
        stringstream ssin(simpleName.getName());
        while (ssin.good())
        {
            ssin >> firstName;
            ssin >> lastName;
        }
    }
};