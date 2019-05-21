#include <stdio.h>
#include <iostream>
using namespace std;

class Chair
{
public:
    virtual void create() const = 0;
};

class Table
{
public:
    virtual void create() const = 0;
};

class WoodChair: public Chair
{
public:
    virtual void create() const override
    {
        cout << "create a wood Chair" << endl;
    }
};

class PlasticChair: public Chair
{
public:
    virtual void create() const override
    {
        cout << "create a plastic Chair" << endl;
    }
};

class WoodTable: public Table
{
public:
    virtual void create() const override
    {
        cout << "create a wood Table" << endl;
    }
};

class PlasticTable: public Table
{
public:
    virtual void create() const override
    {
        cout << "create a plastic Table" << endl;
    }
};

class FurnitureAbstractFactory
{
public:
    virtual Chair *createChair() const = 0;
    virtual Table *createTable() const = 0; 
};

class WoodFactory : public FurnitureAbstractFactory
{
public:
    virtual Chair *createChair() const override
    {
        return (new WoodChair());
    }

    virtual Table *createTable() const override
    {
        return (new WoodTable());
    }
    
};

class PlasticFactory : public FurnitureAbstractFactory
{
    virtual Chair *createChair() const override
    {
        return (new PlasticChair());
    }

    virtual Table *createTable() const override
    {
        return (new PlasticTable());
    }
    
};


class SuperFactory
{
public:
    enum FactoryType {
        WOOD, PLASTIC
    };
    static FurnitureAbstractFactory *getFactory(FactoryType type)
    {
        switch(type)
        {
            case WOOD:
            {
                return new WoodFactory();
                break;
            }
            case PLASTIC:
            {
                return new PlasticFactory();
                break;
            }
            default:
            {
                cout << "Don't Support this type" << endl;
                nullptr;
            }
        }
    }
};