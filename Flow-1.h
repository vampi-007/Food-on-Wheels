//
//  Flow-1.h
//  Food-on-Wheels
//
//  Created by Abdulrehman Mughal on 07/08/2022.
//

#ifndef Flow_1_h
#define Flow_1_h
#include "Rider-Class.h"
#include <iostream>
using namespace std;
void programStarts(Rider order){
    int select = 0;
    int choose;
    bool command = true;
    //creating accounts of all classes..
    order.Restuarant::createAccount();
    order.Customer::createAccount();
    order.Rider::createAccount();
    //restaurant adding menu..
    order.Restuarant::login();
    order.addFoodDetails();
    //Customer ordering
    order.Customer::login();
    order.addToCart();
    cout<<"Press 1 to place Order\nPress 2 to Cancel Order\nPress 3 to Update Cart:"<<endl;
    while (command) {
        cin>>select;
        if(select == 1){
            command = false;
            order.placeOrder();
        }else if (select == 2){
            command = false;
            order.cancelOrder();
            orderCancel+=1;
        }else if (select == 3){
            command = false;
            order.updateCart();
        }else{
            cout<<"Kindly press the correct option!!!"<<endl;
        }

    }
    if(orderCancel == 1){
        order.checkOut();
        order.payCashOnDelivery();
        cout<<"For Checking food status press 1: "<<endl;
        while(command == false){
            cin>>choose;
            if(choose == 1){
                command = true;
                order.Restuarant::login();
                order.Restuarant::updateFoodDeliveryStatus();
                order.Rider::login();
                order.Rider::Restuarant::updateFoodDeliveryStatus();
                order.checkFoodDeliveryStatus();
            }
        }
    }else{
        cout<<"*Good Bye*<---"<<order.getCustomerName()<<"--->"<<endl;
    }
    //Rider part starts...
    order.Rider::login();
    order.orderToDeliver();
    order.takingOrder();
    order.cashCollectionUpdate();
    //Admin part...
    order.managePaymentDetails();
    order.manageFoodOrderDetails();
}
#endif /* Flow_1_h */
