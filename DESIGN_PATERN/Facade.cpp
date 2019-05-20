//
//  Facade.cpp
//  DESIGN_PATERN
//
//  Created by VTI Japan on 2019/05/17.
//  Copyright © 2019 VTI Japan. All rights reserved.
//

#include "Facade.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

ShopFacade* ShopFacade::INSTANCE = NULL;

// ShippingService
void ShippingService::freeShip()
{
    cout << "FREE SHIPPING" << endl;
}
void ShippingService::CODShip()
{
    cout << "COD SHIPPING" << endl;
}

// PaymentService
void PaymentService::payByCredit()
{
    cout << "PAY BY CREDIT" << endl;
}
void PaymentService::payByPoint()
{
    cout << "PAY BY POINT" << endl;
}
void PaymentService::payByCOD()
{
    cout << "PAY BY COD + SHIP FEE" << endl;
}

// ShopFacade
ShopFacade* ShopFacade::getInstance()
{
    return INSTANCE ? INSTANCE : (INSTANCE = new ShopFacade());
}

void ShopFacade::buyProductByCreditWithFreeShip()
{
    paymentService.payByCredit();
    shippingService.freeShip();
}

void ShopFacade::buyProductByCOD()
{
    paymentService.payByCOD();
    shippingService.CODShip();
}

