//
//  Customer-Class.h
//  Food-on-Wheels
//
//  Created by Abdulrehman Mughal on 07/08/2022.
//

#ifndef Customer_Class_h
#define Customer_Class_h

#include "Restuarant-Class.h"

class Customer:public Restuarant{
private:
    
public:
    void createAccount(){
        manageVendors();
        if(req == 1){
            setLogin();
        }
    }
    void setLogin(){
        cout<<"Enter the Username for new account: ";
        cin>>CustomerUserName;
        cout<<"Enter password for new account: ";
        cin>>CustomerPassword;
    }
    void login(){
        cout<<"<------Customer log-in------->"<<endl;
        string username;
        int passcode;
        bool command = true;
        while (command) {
            cout<<"Enter the Username: ";
            cin>>username;
            if(username == CustomerUserName){
                command = false;
                bool command2 = true;
                while (command2) {
                    cout<<"Enter password: ";
                    cin>>passcode;
                    if(passcode == CustomerPassword){
                        command2 = false;
                        cout<<"You are logged in.....:0"<<endl;
                        
                    }
                }
            }
        }
    }

    void viewFoodDetails(){
        viewMenu();
    }
    void addToCart(){
        viewFoodDetails();
        selectOption();
        enterQuantityOfItem();
        placeOrder();
    }
    void showBill(){
        cout<<"<------Bill------>"<<endl;
        cout<<"16% sales Tax: "<<tax<<endl;
        cout<<"Delviery Charges: "<<deliveryCharges<<endl;
        cout<<"Total Price: "<<totalPrice<<endl;
        cout<<"Final Bill: "<<finalBill<<endl;
    }
    void checkFoodDeliveryStatus(){
        cout<<"<=====Food Delivery Status=====>"<<endl;
        cout<<foodDeliveryStatus<<endl;
    }
    void checkOut(){
        calculateBill();
        viewOrder();
        showCustomerInfo();
        showBill();
    }
    void updateCart(){
        cout<<"Update your cart..."<<endl;
        addToCart();
    }
    void payCashOnDelivery(){
        paymentMethod();
    }
};
#endif /* Customer_Class_h */
