//
//  Strategy.hpp
//  DESIGN_PATERN
//
//  Created by VTI Japan on 2019/05/16.
//  Copyright © 2019 VTI Japan. All rights reserved.
//

#ifndef Strategy_hpp
#define Strategy_hpp
#include <stdio.h>
#include <iostream>
using namespace std;
class SortStrategy
{
public:
    virtual void sort() const = 0;
};

class SortByAmout: public SortStrategy
{
public:
    void sort() const override
    {
        cout << "Sort By Amount" << endl;
    }
};

class SortByAlphabetical: public SortStrategy
{
public:
    void sort() const override
    {
        cout << "Sort By Alphabetical" << endl;
    }
};

class SortList
{
private:
    SortStrategy * mSortStrategy;
public:
    void setSortStrategy(SortStrategy *sortStrategy)
    {
        mSortStrategy = sortStrategy;
    }
    void sort()
    {
        mSortStrategy->sort();
    }
};

#endif /* Strategy_hpp */
