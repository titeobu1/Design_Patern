#ifndef ChainOfResponsibility_hpp
#define ChainOfResponsibility_hpp
#include <stdio.h>
#include <iostream>
using namespace std;

class LeaveRequest
{
public:
    int days;
    LeaveRequest(int d)
    {
        days = d;
    }
};
class Approver
{
public:
    Approver *nextApprover;
    virtual bool canApprove(LeaveRequest req) = 0;
    virtual void doApproving(LeaveRequest req) = 0;
    void setNext(Approver *approver)
    {
        nextApprover = approver;
    }
    void approveLeave(LeaveRequest req)
    {
        if(canApprove(req))
        {
            doApproving(req);
        } else
        {
            if(nextApprover != nullptr)
            {
                nextApprover->approveLeave(req);
            } else
            {
                cout << "No one has enough permission to approve the request of " << req.days << " days" << endl;
            }
            
        }
    }
};
class Supervisor : public Approver
{
public:
    virtual bool canApprove(LeaveRequest req) override
    {
        bool b = (req.days <= 3);
        if(!b)
        {
            cout << "Supervisor has not enough permission to approve your request" << endl;
        }
        return b;
    }
    virtual void doApproving(LeaveRequest req) override
    {
        cout << "Supervisor has approved your request" << endl;
    }
};
class Manager : public Approver
{
public:
    virtual bool canApprove(LeaveRequest req) override
    {
        bool b = (req.days <= 5);
        if(!b)
        {
            cout << "Manager has not enough permission to approve your request" << endl;
        }
        return b;
    }
    virtual void doApproving(LeaveRequest req) override
    {
        cout << "Manager has approved your request" << endl;
    }
};
class Director : public Approver
{
public:
    virtual bool canApprove(LeaveRequest req) override
    {
        bool b = (req.days <= 10);
        if(!b)
        {
            cout << "Director has not enough permission to approve your request" << endl;
        }
        return b;
    }
    virtual void doApproving(LeaveRequest req) override
    {
        cout << "Director has approved your request" << endl;
    }
};
#endif //ChainOfResponsibility_hpp