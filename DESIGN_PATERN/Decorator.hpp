//
//  Decorator_hpp
//  DESIGN_PATERN
//
//  Created by VTI Japan on 2019/05/20.
//  Copyright © 2019 VTI Japan. All rights reserved.
//

#ifndef Decorator_hpp
#define Decorator_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class BuyAHamburger
{
public:
    virtual void getDescription() = 0;
};

class MyHamBurger : public BuyAHamburger
{
public:
    MyHamBurger(){}
    void getDescription()
    {
        cout << "You are buying a hamburger" << endl;
    }
};

class Hamburger : public BuyAHamburger
{
private:
    BuyAHamburger* buyAHamburger;
public:
    Hamburger(BuyAHamburger* _buyAHamburger)
    {
        buyAHamburger = _buyAHamburger;
    }
    void getDescription()
    {
        buyAHamburger->getDescription();
    }

};

class Beef : public Hamburger
{
private:
    BuyAHamburger* buyAHamburger;
public:
    Beef(BuyAHamburger* _buyAHamburger): Hamburger(_buyAHamburger){}
    virtual void getDescription()
    {
        Hamburger::getDescription();
        cout << " and a beef" << endl;
    }
};

class Salad : public Hamburger
{
public:
    Salad(BuyAHamburger* _buyAHamburger): Hamburger(_buyAHamburger){}
    void getDescription()
    {
        Hamburger::getDescription();
        cout << " and a salad" << endl;
    }
};

class Tomato : public Hamburger
{
private:
    BuyAHamburger* buyAHamburger;
public:
    Tomato(BuyAHamburger* _buyAHamburger): Hamburger(_buyAHamburger){}
    void getDescription()
    {
        Hamburger::getDescription();
        cout << " and a tomato" << endl;
    }
};


#endif /* Decorator_hpp */
