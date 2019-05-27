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
#include "Builder.hpp"
#include "State.hpp"
#include "Prototype.hpp"
#include "Command.hpp"
#include "ChainOfResponsibility.hpp"
void testStrategy();
void testObserver();
void testFacadeAndSingleton();
void testDecorator();
void testFactory();
void testAdapter();
void testIterator();
void testTemplate();
void testBuilder();
void testState();
void testPrototype();
void testCommand();
void testChainOfResponsibility();

int main(int argc, const char * argv[]) {
    // testStrategy();
    // testObserver();
    // testFacadeAndSingleton();
    // testDecorator();
    // testFactory();
    // testAdapter();
    // testIterator();
    // testTemplate();
    // testBuilder();
    // testState();
    // testPrototype();
    // testCommand();
    testChainOfResponsibility();
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

void testBuilder()
{
    RobotBuildAble *robotBuildAble;
    int robotType, key;
    string robotName;
    chooseARobot :
    cout << "Enter the the robot type you want to build, FlyBot(1), CookieBot(2): "; 
    cin >> robotType; // input the type
    switch (robotType)
    {
        case 1:
            robotBuildAble = new FlyBotBuildable();
            break;
        case 2:
            robotBuildAble = new CookingBotBuildable();
            break;
        default:
            cout << "Don't support this type, please choose again!" << endl;
            goto chooseARobot;
    }
    robotBuildAble->addStart();
    robotBuildAble->addTest();
    robotBuildAble->addTest();
    robotBuildAble->addRun();
    cout << "Enter robot name: ";
    cin >> robotName;
    if(!robotName.empty())
    {
        robotBuildAble->setName(robotName);
    }
    robotBuildAble->go();
    cout << "Do you want to create another robot, YES(1), No(Any Key): "; 
    cin >> key;
    if (key == 1)
    {
        goto chooseARobot;
    }
}

void testState()
{
    ApartmentContext *atc = new ApartmentContext();
    atc->applyNewApplication();
    atc->applyNewApplication();
    atc->applyNewApplication();
    atc->applyNewApplication();
    atc->applyNewApplication();
}

void testPrototype()
{
    chooseARobot :
    RobotBuildAble *res;
    pair<ROBOT_TYPE, vector<ROBOT_ACTIONS> > robot_detail;
    ROBOT_TYPE robotType;
    int key;
    int tmp;
    ROBOT_ACTIONS robot_action;
    vector<ROBOT_ACTIONS> robot_actions;
    string robot_name;
    cout << "Enter the the robot type you want to build, FlyBot(1), CookieBot(2): "; 
    cin >> tmp;
    robotType = static_cast<ROBOT_TYPE>(tmp); // input the type
    switch (robotType)
    {
        case 1:
            robotType = ROBOT_TYPE::FLY_BOT;
            break;
        case 2:
            robotType = ROBOT_TYPE::COOKIE_BOT;
            break;
        default:
            cout << "Don't support this type, please choose again!" << endl;
            goto chooseARobot;
    }
    designActions :
    {
        cout << "Let's design your robot actions, start(1), test(2), run(3), finish create(0): "; 
        cin >> tmp;
        robot_action = static_cast<ROBOT_ACTIONS>(tmp);
        if(robot_action != 0)
        {
            robot_actions.push_back(robot_action);
            goto designActions;
        }
    }
    cout << "Enter robot name: ";
    cin >> robot_name;
    robot_detail = make_pair(robotType, robot_actions);
    res = RobotFactory::getRobot(robot_detail, robot_name);
    res->go();
    cout << "Do you want to create another robot, YES(1), No(Any Key): "; 
    cin >> key;
    if (key == 1)
    {
        goto chooseARobot;
    }
}
void testCommand()
{
    Waiter waiter;
    Order *order;
    int tmp;
    chooseAFood :
    cout << "Hay chon mon an ban muon goi, Cua_Rang_Me(1), Canh_Chua(2): "; 
    cin >> tmp; // input the type
    switch (static_cast<ORDER>(tmp))
    {
        case ORDER::CUA_RANG_ME:
            order = new Cua_Rang_Me();
            break;
        case ORDER::CANH_CHUA:
            order = new Canh_Chua();
            break;
        default:
            cout << "Xin chon lai mon khac anh ei!" << endl;
            goto chooseAFood;
    }
    waiter.listOrder(order);
    cout << "Ban co muon chon them mon khac khong, YES(1), No(Any Key): "; 
    cin >> tmp;
    if (tmp == 1)
    {
        goto chooseAFood;
    }
    waiter.executeOrder();
}

void testChainOfResponsibility()
{
    
    Supervisor *sup = new Supervisor();
    Manager *mng = new Manager();
    Director *director = new Director();

    sup->setNext(mng);
    mng->setNext(director);

    beginApprove:
    int tmp;
    cout << "Enter your number of days you want to approve: "; 
    cin >> tmp; 

    LeaveRequest req(tmp);
    sup->approveLeave(req);
    goto beginApprove;
}