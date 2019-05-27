#ifndef Builder_hpp
#define Builder_hpp
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int ACTION_START = 0;
const int ACTION_TEST = ACTION_START + 1;
const int ACTION_RUN = ACTION_TEST + 1;

class RobotBuildAble
{
public:
    vector<int> actions;
    string name;
    void setName(string n)
    {
        name = n;
    }
    void addStart()
    {
        actions.push_back(ACTION_START);
    }
    void addTest()
    {
        actions.push_back(ACTION_TEST);
    }
    void addRun()
    {
        actions.push_back(ACTION_RUN);
    }
    virtual void start() = 0;
    virtual void test() = 0;
    virtual void run() = 0;
    void go()
    {
        if (actions.size() == 0)
        {
            cout << "Please build your robot's action before going" << endl;
            return;
        }
        if (!name.empty())
        {
            cout << name << " is preparing to go" << endl;
        }
        // for(vector<int>::iterator it = actions.begin(); it != actions.end(); ++it) {
        for ( auto &it : actions ) {
            switch (it)
            {
                case ACTION_START:
                    start();
                    continue;
                case ACTION_TEST:
                    test();
                    continue;
                case ACTION_RUN:
                    run();
                    continue;
                default:
                    cout << "NOT SUPPORT THIS ACTION" << endl;
            }
        }
    }
};

class FlyBotBuildable : public RobotBuildAble
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

class CookingBotBuildable : public RobotBuildAble
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

#endif /* Builder_hpp */