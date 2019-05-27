#ifndef Prototype_hpp
#define Prototype_hpp
#include <stdio.h>
#include <iostream>
#include "Builder.hpp"
#include <map>
#include <vector>
#include <iterator>
using namespace std;

enum ROBOT_TYPE{
    FLY_BOT = 0,
    COOKIE_BOT
};

enum ROBOT_ACTIONS{
    START = 1,
    TEST,
    RUN
};

class CloneAble
{
public:
    virtual CloneAble * clone() const
    {
        return new CloneAble(*this);
    };
};

class FlyBotBuildAndCloneAble : public CloneAble, public RobotBuildAble
{
public:
    virtual void start() override
    {
        cout << name << ", the FlyBot, start" << endl;
    }
    virtual void test() override
    {
        cout << name << ", the FlyBot, test" << endl;
    }
    virtual void run() override
    {
        cout << name << ", the FlyBot, run" << endl;
    }

    virtual FlyBotBuildAndCloneAble * clone() const override
    {
        return new FlyBotBuildAndCloneAble(*this);
    };
};

class CookingBotBuildAndCloneAble : public CloneAble, public RobotBuildAble
{
public:
    void checkRiceIsAbleToBeCook()
    {
        cout << "Rice is checking" << endl;
        cout << "Rice is ready" << endl;
    }
    virtual void start() override
    {
        cout << name << ", the CookieBot, start" << endl;
    }
    virtual void test() override
    {
        cout << name << ", the CookieBot, test" << endl;
        checkRiceIsAbleToBeCook();
    }
    virtual void run() override
    {
        cout << name << ", the CookieBot, run" << endl;
    }

    virtual CookingBotBuildAndCloneAble * clone() const override
    {
        return new CookingBotBuildAndCloneAble(*this);
    };
};

class RobotFactory
{
public:
    static RobotBuildAble *createNewRobot(pair<ROBOT_TYPE, vector<ROBOT_ACTIONS> > robot_detail)
    {
        RobotBuildAble *res;
        switch (robot_detail.first)
        {
            case FLY_BOT:
                res = new FlyBotBuildAndCloneAble();
                break;
            case COOKIE_BOT:
                res = new CookingBotBuildAndCloneAble();
                break;
            default:
                throw std::invalid_argument("NOT SUPPORT THIS KIND OF ROBOT!");
                break;
        }
        for ( auto &it : robot_detail.second ) 
        {
            switch (it)
            {
                case START:
                    res->addStart();
                    break;
                case TEST:
                    res->addTest();
                    break;
                case RUN:
                    res->addRun();
                    break;
                default:
                    throw std::invalid_argument("NOT SUPPORT THIS ACTION!");
                    break;
                
            }
        }
        return res;
    }
    static map<pair<ROBOT_TYPE, vector<ROBOT_ACTIONS> >, RobotBuildAble *> ROBOT_CACHE;
    static RobotBuildAble *getRobot(pair<ROBOT_TYPE, vector<ROBOT_ACTIONS> > robot_detail, string robot_name)
    {
        RobotBuildAble *res;
        map<pair<ROBOT_TYPE, vector<ROBOT_ACTIONS> >, RobotBuildAble *>::iterator it = ROBOT_CACHE.find(robot_detail);
        if(it != ROBOT_CACHE.end())
        {
            cout << "Your kind of robot is already exist before with the name: " << it->second->name << endl;
            cout << "No need to create new, clone the robot with the new name: " << robot_name << endl;
            res = it->second;
        } else
        {
            cout << "Your kind of robot is not created before yet." << endl;
            cout << "Create new robot with the name: " << robot_name << endl;
            res = createNewRobot(robot_detail);
            ROBOT_CACHE.insert(make_pair(robot_detail, res));
        }
        res->setName(robot_name);
        return res;
    }

};
map<pair<ROBOT_TYPE, vector<ROBOT_ACTIONS> >, RobotBuildAble *> RobotFactory::ROBOT_CACHE;

#endif //Prototype_hpp