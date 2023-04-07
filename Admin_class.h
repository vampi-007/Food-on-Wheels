//
//  Admin_class.h
//  Food-on-Wheels
//
//  Created by Abdulrehman Mughal on 07/08/2022.
//

#ifndef Admin_class_h
#define Admin_class_h
#include "Order-Class.h"


class Admin : public Order{
private:
    string customerName, customerAddress, customerCountry;
    int customerPhoneNo, customerID, cardNo, cardPin;
    string riderName, riderAddress, riderCountry;
    int riderPhoneNo, riderID;
    string vendorName, vendorAddress, vendorCountry;
    int vendorPhoneNo, vendorID;
    string userName;
    int password;
protected:
    string riderUserName;
    int riderPassword;
    string CustomerUserName;
    int CustomerPassword;
    int block;
    int tax;
    int finalBill;
    int deliveryCharges;
public:
    string getCustomerName(){
        return CustomerUserName;
    }
    void getRiderInfo(){
        cout<<"Enter name: ";
        getline(cin, riderName);
        cout<<"Enter address: ";
        getline(cin, riderAddress);
        cout<<"Enter country: ";
        cin.ignore();
        cin>>riderCountry;
        cout<<"Enter Phone No: ";
        cin>>riderPhoneNo;
        cout<<"Enter id: ";
        cin>>riderID;
    }
    void getCustomersInfo(){
        cout<<"Enter name: ";
        getline(cin, customerName);
        cout<<"Enter address: ";
        getline(cin, customerAddress);
        cout<<"Enter country: ";
        cin.ignore();
        cin>>customerCountry;
        cout<<"Enter Phone No: ";
        cin>>customerPhoneNo;
        cout<<"Enter id: ";
        cin>>customerID;
    }
    void getVendorsInfo(){
        cout<<"Enter name: ";
        getline(cin, vendorName);
        cout<<"Enter address: ";
        getline(cin, vendorAddress);
        cout<<"Enter country: ";
        cin.ignore();
        cin>>vendorCountry;
        cout<<"Enter Phone No: ";
        cin>>vendorPhoneNo;
        cout<<"Enter id: ";
        cin>>vendorID;
    }
    void showVendorInfo(){
        cout<<"<------Vendor info------>"<<endl;
        cout<<"Name: "<<vendorName<<endl;
        cout<<"address: "<<vendorAddress<<endl;
        cout<<"Country: "<<vendorCountry<<endl;
        cout<<"Id: "<<vendorID<<endl;
        cout<<"Phone Number: "<<vendorPhoneNo<<endl;
    }
    void showCustomerInfo(){
        cout<<"<------Customer info------>"<<endl;
        cout<<"Name: "<<customerName<<endl;
        cout<<"address: "<<customerAddress<<endl;
        cout<<"Country: "<<customerCountry<<endl;
        cout<<"Id: "<<customerID<<endl;
        cout<<"Phone Number: "<<customerPhoneNo<<endl;
    }
    void showRiderInfo(){
        cout<<"<------Rider info------>"<<endl;
        cout<<"Name: "<<riderName<<endl;
        cout<<"Id: "<<riderID<<endl;
        cout<<"Phone Number: "<<riderPhoneNo<<endl;
    }
    void getPaymentDetails(){
        cout<<"Welcome to the Online Payment Method!!!"<<endl;
        cout<<"Enter the Card Number: ";
        cin>>cardNo;
        cout<<"Enter Card Pin: ";
        cin>>cardPin;
    }
    void showPaymentDetails(){
        cout<<"<------Customer info------>"<<endl;
        cout<<"Name: "<<customerName<<endl;
        cout<<"address: "<<customerAddress<<endl;
        cout<<"Id: "<<customerID<<endl;
        cout<<"Phone Number: "<<customerPhoneNo<<endl;
        cout<<"Card no: "<<cardNo<<endl;
        cout<<"Final Bill: "<<finalBill<<endl;
    }
    void paymentMethod(){
        login();
        int permission;
        bool command = true;
        while (command) {
            cout<<"<-----Select Payment Method----->\nPress 1 to Select Online Payment\nPress 2 for Cash On delivery payment "<<endl;
            cin>>permission;
            if(permission == 1){
                command = false;
                getPaymentDetails();
                cout<<"The Amount has been deducted from your account!!! Thank you! "<<endl;
            }else if(permission == 2){
                command = false;
                cout<<"<------Your Rider Details------>"<<endl;
                showRiderInfo();
                cout<<"Kindly pay your bill to the rider!!!"<<endl;
                cout<<"<-----Bill----->"<<endl<<finalBill<<endl;
            }
        }
    }
    void blockingCustomer(){
        if(block == 1){
            login();
            CustomerUserName = "NULL";
            CustomerPassword = 0000;
        }
    }
    void permissionForNewMenu(){
        cout<<"<------Permission for Menu------>"<<endl;
        login();
        int permission;
        bool command = true;
        while (command) {
            cout<<"Press 1 to permit this restuarant\nPress 2 for decline the request: "<<endl;
            cin>>permission;
            if(permission == 1){
                command = false;
            }else if(permission == 2){
                command = false;
                cout<<"sorry you cannot create menu!!!"<<endl;
            }
        }
    }
    void permissionForNewAccount(){
        login();
        int permission;
        bool command = true;
        while (command) {
            cout<<"Press 1 to permit this user\nPress 2 for decline the request: "<<endl;
            cin>>permission;
            cin.ignore();
            if(permission == 1){
                command = false;
                int _permission;
                cout<<"Who you want to give permission\nFor rider press 1\nFor vendor press 2\nFor customer press 3: ";
                cin>>_permission;
                cin.ignore();
                if(_permission == 1){
                    req = 1;
                    getRiderInfo();
                }else if(_permission == 2){
                    req = 1;
                    getVendorsInfo();
                }else{
                    req = 1;
                    getCustomersInfo();
                }
            }else if(permission == 2){
                command = false;
                cout<<"sorry you cannot create an account!!!"<<endl;
                req = 0;
            }
        }
    }
    void showFinalBill(){
        cout<<"Tax: "<<tax<<endl;
        cout<<"Delivery Charges: "<<deliveryCharges<<endl;
        cout<<"Total Price: "<<totalPrice<<endl;
        cout<<"Final Bill: "<<finalBill<<endl;
    }
    void manageRiders(){
        permissionForNewAccount();
    }
    void managePaymentDetails(){
        cout<<"<===Payment Details===>"<<endl;
        login();
        showFinalBill();
    }
    void manageFoodOrderDetails(){
        login();
        showRiderInfo();
        cout<<"address: "<<riderAddress<<endl;
        cout<<"Country: "<<riderCountry<<endl;
        showPaymentDetails();
        showFinalBill();
    }
    void manageCustomers(){
        permissionForNewAccount();
    }
    void manageVendorsFood(){
        permissionForNewMenu();
    }
    void manageVendors(){
        permissionForNewAccount();
    }
    void login(){
        cout<<"<------Admin Log-in------->"<<endl;
        bool command = true;
        cout<<"Username: ";
        while (command) {
            cin>>userName;
            if(userName == "admin"){
                command = false;
                bool command2 = true;
                cout<<"Password:";
                while (command2) {
                    cin>>password;
                    if(password == 123){
                        command2 = false;
                        
                    }else{
                        cout<<"Kindly enter the correct Password: "<<endl;
                    }
                }
            }else{
                cout<<"Kindly enter the correct Username: "<<endl;
            }
        }
    }
        
};
#endif /* Admin_class_h */
