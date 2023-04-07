//
//  Restuarant-Class.h
//  Food-on-Wheels
//
//  Created by Abdulrehman Mughal on 07/08/2022.
//

#ifndef Restuarant_Class_h
#define Restuarant_Class_h
#include "Admin_class.h"



class Restuarant : public Admin{
private:
    string userName;
    int password;
protected:
    int request;
    int paymentReceived;
    string foodDeliveryStatus;
public:
    void addFoodDetails(){
        permissionForNewMenu();
        for(int row = 0 ;row<5;row++){
            cout<<"Enter item then price with space: ";
            for(int col = 0; col<2; col++){
                
                cin>>menu[row][col];
            }
            prices[row] = stoi(menu[row][1]);
        }
    }
    void updateFoodDetails(){
        cout<<"<====Update Food====>"<<endl;
        viewMenu();
        int itemNo;
        cout<<"Enter item number: ";
        cin>>itemNo;
        for(int row = 0 ;row<5;row++){
            if(itemNo-1 == row){
            cout<<"Enter item then price with space: ";
            for(int col = 0; col<2; col++){
                    cin>>menu[row][col];
                }
            }
        }
    }
    void deleteFood(){
        cout<<"<====Delete Food====>"<<endl;
        viewMenu();
        int itemNo;
        cout<<"Enter item number: ";
        cin>>itemNo;
        for(int row = 0 ;row<5;row++){
            if(itemNo-1 == row){
                for(int col = 0; col<2; col++){
                    menu[row][col] = "NULL";
                }
                cout<<"Item on item number "<<itemNo<<" DELETED..."<<endl;
            }
        }
        for(int row = 0 ;row<5;row++){
            for(int col = 0; col<2; col++){
                cout<<menu[row][col]<<"   ";
            }
            cout<<endl;
        }
    }
    void setLogin(){
        cout<<"Enter the Username for new account: ";
        cin>>userName;
        cout<<"Enter password for new account: ";
        cin>>password;
    }
    void login(){
        cout<<"<------Restuarant log-in------->"<<endl;
        string username;
        int passcode;
        bool command = true;
        while (command) {
            cout<<"Enter the Username: ";
            cin>>username;
            if(username == userName){
                command = false;
                bool command2 = true;
                while (command2) {
                    cout<<"Enter password: ";
                    cin>>passcode;
                    if(passcode == password){
                        command2 = false;
                        cout<<"You are logged in.....:0"<<endl;
                        
                    }
                }
            }
        }
    }
    void alert(){
        string alert[2] = {"Your order is in progress!!;)", "Your order is ready to pick up by the rider."};
        int situation;
        bool command = true;
        cout<<"Press 1 if order not ready\nPress 2 if order is ready!!"<<endl;
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
    void createAccount(){
        manageVendors();
        if(req == 1){
            setLogin();
        }
    }
    void calculateDeliveryCharges(){
        int distance;
        int fuelPerKM = 18;
        cout<<"Enter the distance in km b/w restuarant and customer: ";
        cin>>distance;
        deliveryCharges = distance * fuelPerKM;
    }
    void calculateBill(){
        tax = totalPrice * 0.16;
        calculateDeliveryCharges();
        finalBill = totalPrice + tax + deliveryCharges;
    }
    void checkFoodOrder(){
        viewOrder();
    }
    void updateFoodDeliveryStatus(){
        alert();
    }
};

//Raahim Khan part...


#endif /* Restuarant_Class_h */
