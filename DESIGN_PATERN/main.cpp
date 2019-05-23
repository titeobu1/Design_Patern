//
//  main.cpp
//  DESIGN_PATERN
//
//  Created by VTI Japan on 2019/05/16.
//  Copyright © 2019 VTI Japan. All rights reserved.
//

#include <iostream>
#include <string>
#include "Strategy.hpp"
#include "Observer.hpp"
#include "Facade.cpp"
#include "Decorator.hpp"
#include "Factory.cpp"
#include "Adapter.cpp"
#include "Iterator.hpp"
#include "Template.hpp"
void testStrategy();
void testObserver();
void testFacadeAndSingleton();
void testDecorator();
void testFactory();
void testAdapter();
void testIterator();
void testTemplate();

int main(int argc, const char * argv[]) {
//    testStrategy();
//    testObserver();
    // testFacadeAndSingleton();
    // testDecorator();
    // testFactory();
    // testAdapter();
    // testIterator();
    testTemplate();
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

void testFactory()
{
    FurnitureAbstractFactory *myWoodFactory = SuperFactory::getFactory(SuperFactory::FactoryType::WOOD);
    Chair *myFirstChair = myWoodFactory->createChair();
    myFirstChair->create();
    Table *myFirstTable = myWoodFactory->createTable();
    myFirstTable->create();

    cout << "Creating Plastic table and chair" << endl;

    FurnitureAbstractFactory *myPlasticFactory = SuperFactory::getFactory(SuperFactory::FactoryType::PLASTIC);
    Chair *mySecondChair = myPlasticFactory->createChair();
    mySecondChair->create();
    Table *mySecondTable = myPlasticFactory->createTable();
    mySecondTable->create();
}

void testAdapter()
{
    SimpleName simpleName("NGUYEN HAI");
    ComplexName *compleName = new AdapterToComplexName(simpleName);
    cout << "Your First Name is: " << compleName->getFirstName() << endl;
    cout << "Your Last Name is: " << compleName->getLastName() << endl;

    cout << "Changing Your First Name to Ly: " <<  endl;
    compleName->setFirstName("Ly");

    cout << "Your First Name is: " << compleName->getFirstName() << endl;
    cout << "Your Last Name is: " << compleName->getLastName() << endl;

    cout << "You are a Singer now" <<  endl;
}

void testIterator()
{
    Devision *sale = new Devision("sale");
    sale->add(static_cast<Corporate*>(new Employee("Hai", sale->getName())));
    sale->add(static_cast<Corporate*>(new Employee("Hai Sida", sale->getName())));

    Devision *HR = new Devision("HR");
    HR->add(static_cast<Corporate*>(new Employee("SEN 1", sale->getName())));
    HR->add(static_cast<Corporate*>(new Employee("SEN 2", sale->getName())));
    HR->add(static_cast<Corporate*>(new Employee("SEN 3", sale->getName())));

    sale->add(HR);

    sale->print();
}

void testTemplate()
{
    FlyBot flyBot;
    flyBot.go();
    CookingBot cookBot;
    cookBot.go();
}