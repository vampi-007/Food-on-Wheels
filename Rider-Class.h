//
//  Rider-Class.h
//  Food-on-Wheels
//
//  Created by Abdulrehman Mughal on 07/08/2022.
//

#ifndef Rider_Class_h
#define Rider_Class_h
#include "Customer-Class.h"


class Rider:public Customer{
private:
    
public:
    void createAccount(){
        manageVendors();
        if(req == 1){
            setLogin();
        }
    }
    void setLogin(){
        cout<<"Enter the Username foe new account: ";
        cin>>riderUserName;
        cout<<"Enter password for new account: ";
        cin>>riderPassword;
    }
    void login(){
        cout<<"<------Rider log-in------->"<<endl;
        string username;
        int passcode;
        bool command = true;
        while (command) {
            cout<<"Enter the Username: ";
            cin>>username;
            if(username == riderUserName){
                command = false;
                bool command2 = true;
                while (command2) {
                    cout<<"Enter password: ";
                    cin>>passcode;
                    if(passcode == riderPassword){
                        command2 = false;
                        cout<<"You are logged in.....:0"<<endl;
                        
                    }
                }
            }
        }
    }
    void orderToDeliver(){
        viewOrder();
        showCustomerInfo();
        showBill();
    }
    void takingOrder(){
        cout<<"Press 1 for Accepting the Order\nPress 2 for rejecting the Order: "<<endl;
        cin>>request;
        bool permission = true;
        while(permission){
            if(request == 1){
                permission = false;
                cout<<"You have accepted this order..."<<endl;
            }else if(request == 2){
                permission = false;
                cout<<"The request has been declined..."<<endl;
            }
        }
    }
    void alert(){
        string alert[2] = {"Your order is in on the way!!;)", "Your order is ready to pick up."};
        int situation;
        bool command = true;
        cout<<"Press 1 if order is on the way.\nPress 2 if order is ready to pick up!!!"<<endl;
        cin>>situation;
        while (command) {
            if(situation == 1){
                command = false;
                foodDeliveryStatus = alert[0];
                cout<<foodDeliveryStatus<<endl;
            }else if (situation == 2){
                command = false;
                foodDeliveryStatus = alert[1];
                cout<<foodDeliveryStatus<<endl;
            }
        }
    }
    void updateFoodDeliveryStatus(){
        alert();
    }
    void cashCollectionUpdate(){
        cout<<"press 1 if customer pay the bill\npress 2 if customer did not pay the bill:";
        cin>>paymentReceived;
        if(paymentReceived == 1){
            cout<<"Customer payed the bill..."<<endl;
        }else if (paymentReceived == 2){
            cout<<"Customer did not pay the bill..."<<endl<<endl;
            cout<<"Do you want to block the customer??\nif yes press 1\nif no press 2..."<<endl;
            cin>>block;
            blockingCustomer();
        }
    }
};
#endif /* Rider_Class_h */
