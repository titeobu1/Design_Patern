//
//  Facade.hpp
//  DESIGN_PATERN
//
//  Created by VTI Japan on 2019/05/17.
//  Copyright © 2019 VTI Japan. All rights reserved.
//

#ifndef Facade_hpp
#define Facade_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class ShippingService
{
public:
    void freeShip();
    void CODShip();
};

class PaymentService
{
public:
    void payByCredit();
    void payByPoint();
    void payByCOD();
};


class ShopFacade
{
private:
    static ShopFacade* INSTANCE ;
    ShippingService shippingService;
    PaymentService paymentService;
public:
    static ShopFacade* getInstance();
    void buyProductByCreditWithFreeShip();
    void buyProductByCOD();
};

#endif /* Facade_hpp */
