#ifndef Template_hpp
#define Template_hpp
#include <stdio.h>
#include <iostream>
using namespace std;

class Robot
{
public:
    virtual void start() = 0;
    virtual void test() = 0;
    virtual void run() = 0;
    void go()
    {
        start();
        test();
        run();
    }
};

class FlyBot: public Robot
{
public:
    virtual void start() override
    {
        cout << "Flybot start" << endl;
    }
    virtual void test() override
    {
        cout << "Flybot test" << endl;
    }
    virtual void run() override
    {
        cout << "Flybot run" << endl;
    }
};

class CookingBot: public Robot
{
public:
    void checkRiceIsAbleToBeCook()
    {
        cout << "Rice is ready" << endl;
    }
    virtual void start() override
    {
        cout << "CookingBot start" << endl;
    }
    virtual void test() override
    {
        cout << "CookingBot test" << endl;
        checkRiceIsAbleToBeCook();
    }
    virtual void run() override
    {
        cout << "CookingBot run" << endl;
    }
};
#endif /* Template_hpp */