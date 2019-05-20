//
//  main.cpp
//  DESIGN_PATERN
//
//  Created by VTI Japan on 2019/05/16.
//  Copyright © 2019 VTI Japan. All rights reserved.
//

#include <iostream>
#include "Strategy.hpp"
#include "Observer.hpp"
#include "Facade.cpp"
#include "Decorator.hpp"
void testStrategy();
void testObserver();
void testFacadeAndSingleton();
void testDecorator();

int main(int argc, const char * argv[]) {
//    testStrategy();
//    testObserver();
    // testFacadeAndSingleton();
    testDecorator();
    return 0;
}

void testStrategy()
{
    SortByAlphabetical sortByAlphabetical;
    SortByAmout sortByAmout;
    
    SortList sortList;
    sortList.setSortStrategy(&sortByAlphabetical);
    sortList.sort();
    
    sortList.setSortStrategy(&sortByAmout);
    sortList.sort();
}

void testObserver()
{
    AccountService as;
    as.attach(new Email());
    as.attach(new Logger());
    
    as.loginSuccess();
    as.loginFail();
    as.loginExpired();
    as.loginInvalid();
    
}

void testFacadeAndSingleton()
{
    //ShopFacade::getInstance()->buyProductByCreditWithFreeShip();
    ShopFacade::getInstance()->buyProductByCOD();
}

void testDecorator()
{
    BuyAHamburger *aHamburger = new Tomato(new Salad(new Beef(new Hamburger(new MyHamBurger()))));
    aHamburger->getDescription();

}
