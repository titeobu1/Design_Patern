#ifndef Protection_hpp
#define Protection_hpp
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum PERMISSION
{
    CUSTOMER = 1,
    ADMIN
};
class ProtectionUser
{
public:
    string id;
    string name;
    ProtectionUser(string _id, string _name)
    {
        id = _id;
        name = _name;
    }
};

class UserService
{
public:
    virtual void listUsers() = 0;
    virtual void inserUser(ProtectionUser u, int permission) = 0;
};

class UserServiceImpl : public UserService
{
public:
    vector<ProtectionUser> listUser;
    virtual void listUsers() override
    {
        cout << "Below is the list of users" << endl;
        for (auto it : listUser)
        {
            cout << "id: " << it.id << ", name: " << it.name <<  endl;
        }
    }
    virtual void inserUser(ProtectionUser u, int permission) override
    {
        listUser.push_back(u);
    }
};

class UserServiceProxy : public UserService
{
public:
    UserServiceImpl userService;
    virtual void listUsers() override
    {
        if (userService.listUser.size() == 0)
        {
            cout << "No users!" << endl;
            return;
        }
        userService.listUsers();
    }
    virtual void inserUser(ProtectionUser u, int permission) override
    {
        switch (permission)
        {
            case ADMIN:
                userService.inserUser(u, permission);
                break;
            case CUSTOMER:
            default:
                cout << "Sorry you have no permission to do this action" << endl;
                break;
        }
    }
};
#endif //Protection_hpp