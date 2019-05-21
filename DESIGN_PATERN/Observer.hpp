//
//  Observer.hpp
//  DESIGN_PATERN
//
//  Created by VTI Japan on 2019/05/17.
//  Copyright © 2019 VTI Japan. All rights reserved.
//

#ifndef Observer_hpp
#define Observer_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
using std::vector;

enum LoginStatus {
    SUCCESS, FAILURE, INVALID, EXPIRED
};

class User
{
public:
    char* email;
    char* ip;
    LoginStatus status;
};

class Observer
{
public:
    virtual void update(User user) const = 0;
};

class Email : public Observer
{
public:
    virtual void update(User user) const override
    {
        if (user.status != SUCCESS)
        {
            cout << "Email Log in " << user.status << endl;
        }
    }
};

class Logger : public Observer
{
public:
    virtual void update(User user) const override
    {
        cout << "Logger Log in " << user.status << endl;
    }
};

class Service
{
public:
    virtual void attach(Observer *observer)  = 0;
    virtual void notifyAllObserver()  = 0;
};

class AccountService : Service
{
public:
    vector<Observer *> m_observers;
    User user;
    virtual void attach(Observer *observer) override
    {
        m_observers.push_back(observer);
    }
    virtual void notifyAllObserver() override
    {
        for (auto it = m_observers.begin();it !=m_observers.end();it++)
        {
            (*it)->update(user);
        }
    }
    
    void loginSuccess()
    {
        user.status = SUCCESS;
        notifyAllObserver();
    }
    
    void loginFail()
    {
        user.status = FAILURE;
        notifyAllObserver();
    }
    
    void loginExpired()
    {
        user.status = EXPIRED;
        notifyAllObserver();
    }
    
    void loginInvalid()
    {
        user.status = INVALID;
        notifyAllObserver();
    }
};

#endif /* Observer_hpp */
