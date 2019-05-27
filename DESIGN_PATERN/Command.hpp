#ifndef Command_hpp
#define Command_hpp
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

enum ORDER
{
    CUA_RANG_ME = 1,
    CANH_CHUA
};
class Chef
{
public:
    void Lam_Cua_Rang_Me()
    {
        cout << "Dau bep dang lam mon cua rang me" << endl;
    }
    void Nau_Canh_Chua()
    {
        cout << "Dau bep dang nau canh chua" << endl;
    }
};
class Order
{
public:
    Chef chef;
    virtual void execute() = 0;
};
class Cua_Rang_Me : public Order
{
public:
    virtual void execute() override
    {
        chef.Lam_Cua_Rang_Me();
    }
};
class Canh_Chua : public Order
{
public:
    virtual void execute() override
    {
        chef.Nau_Canh_Chua();
    }
};
class Waiter
{
public:
    vector<Order*> orders;
    void listOrder(Order *order)
    {
        orders.push_back(order);
    }
    void executeOrder()
    {
        cout << "Phuc vu nhan duoc order moi" << endl;
        for ( auto &it : orders ) {
            it->execute();
        }
    }
};
#endif //Command_hpp