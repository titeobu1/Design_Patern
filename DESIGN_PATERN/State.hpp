#ifndef State_hpp
#define State_hpp
#include <stdio.h>
#include <iostream>
using namespace std;

enum STATE{
    WATTING_STATE,
    GOT_APPLICATION_STATE,
    HECKING_STATE,
    FULLY_STATE,
    APARTMENT_RENTED_STATE
};

class State
{
public:
    int numberApartments = 3;
    int currentState = WATTING_STATE;
    State(State *state)
    {
        currentState = state->currentState;
        numberApartments = state->numberApartments;
    }
    State(int prevState, int prevNumApart)
    {
        currentState = prevState;
        numberApartments = prevNumApart;
    }
    virtual void handleState() = 0;

    void setCurrentState(int cs)
    {
        currentState = cs;
    }
};

class GotApplicationState: public State
{
public:
    GotApplicationState(int prevState, int prevNumApart) : State(prevState, prevNumApart){};
    GotApplicationState(State *state) : State(state){};
    virtual void handleState() override
    {
        switch (currentState)
        {
            case FULLY_STATE:
                cout << "sorry, no apartment avaliable right now" << endl;
                break;
            case WATTING_STATE:
                cout << "Thank you for your application!" << endl;
                setCurrentState(GOT_APPLICATION_STATE);
                break;
            case GOT_APPLICATION_STATE:
                cout << "we are checking your application" << endl;
                break;
            case APARTMENT_RENTED_STATE:
                cout << "Hang on, we are renting you an apartment" << endl;
                break;
            default:
                cout << "state error" << endl;
                break;
        }
    }
};

class CheckingState: public State
{
public:
    CheckingState(int prevState, int prevNumApart) : State(prevState, prevNumApart){};
    CheckingState(State *state) : State(state){};
    virtual void handleState() override
    {
        switch (currentState)
        {
            case FULLY_STATE:
                cout << "sorry, no apartment avaliable right now" << endl;
                break;
            case WATTING_STATE:
                cout << "Please apply your application first" << endl;
                break;
            case GOT_APPLICATION_STATE:
                if ((rand() % 10) > 4)
                {
                    cout << "Congrat! Your Application has been approved, please wait until getting your key" << endl;
                    cout << "Here are the key" << endl;
                    setCurrentState(APARTMENT_RENTED_STATE);
                }
                else
                {
                    cout << "Unforturnally! Your application has been rejected, good luck next time boy" << endl;
                    setCurrentState(WATTING_STATE);
                }
                break;
            case APARTMENT_RENTED_STATE:
                cout << "Hang on, we are renting you an apartment" << endl;
                break;
            default:
                cout << "state error" << endl;
                break;
        }
    }
};

class ApartmentRentedState: public State
{
public:
    ApartmentRentedState(int prevState, int prevNumApart) : State(prevState, prevNumApart){};
    ApartmentRentedState(State *state) : State(state){};
    virtual void handleState() override
    {
        switch (currentState)
        {
            case FULLY_STATE:
                cout << "sorry, no apartment avaliable right now" << endl;
                break;
            case WATTING_STATE:
                cout << "Please apply your application first" << endl;
                break;
            case GOT_APPLICATION_STATE:
                cout << "You must have your application checked" << endl;
                break;
            case APARTMENT_RENTED_STATE:
                cout << "Renting you an apartment" << endl;
                numberApartments -= 1;
                setCurrentState(APARTMENT_RENTED_STATE);
                break;
            default:
                cout << "state error" << endl;
                break;
        }
    }
};

class PassKeyState: public State
{
public:
    PassKeyState(int prevState, int prevNumApart) : State(prevState, prevNumApart){};
    PassKeyState(State *state) : State(state){};
    virtual void handleState() override
    {
        switch (currentState)
        {
            case FULLY_STATE:
                cout << "sorry, no apartment avaliable right now" << endl;
                break;
            case WATTING_STATE:
                cout << "Please apply your application first" << endl;
                break;
            case GOT_APPLICATION_STATE:
                cout << "You must have your application checked" << endl;
                break;
            case APARTMENT_RENTED_STATE:
                cout << "Here are the key" << endl;
                cout << "the apartment avaliable left: " << numberApartments << endl;
                if(numberApartments <= 0)
                {
                    setCurrentState(FULLY_STATE);
                } else
                {
                    setCurrentState(WATTING_STATE);
                }
                break;
            default:
                cout << "state error" << endl;
                break;
        }
    }
};

class ApartmentContext
{
public:
    State *state = nullptr;
    const int INIT_APARTMENT_NUMBER = 3;

    void applyNewApplication()
    {
        if (state == nullptr)
        {
            state = new GotApplicationState(WATTING_STATE, INIT_APARTMENT_NUMBER);
            state->handleState();
        } else
        {
            state = new GotApplicationState(state);
            state->handleState();
        }

        state = new CheckingState(state);
        state->handleState();

        state = new ApartmentRentedState(state);
        state->handleState();

        state = new PassKeyState(state);
        state->handleState();
    }
};
#endif /* State_hpp */