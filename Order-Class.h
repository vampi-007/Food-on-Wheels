//
//  Order-Class.h
//  Food-on-Wheels
//
//  Created by Abdulrehman Mughal on 07/08/2022.
//

#ifndef Order_Class_h
#define Order_Class_h
#include "Menu-class.h"
class Order: public Menu{
protected:
    string item;
    int priceOfItem;
    int totalPrice;
    int quantity;
public:
    void selectOption(){
        int choice;
        int command = true;
        cout<<"For select the item Enter its item number: ";
        while(command){
            cin>>choice;
            if(choice == 1){
                command = false;
                item = menu[0][0];
                priceOfItem = stoi(menu[0][1]);
            }else if(choice == 2){
                command = false;
                item = menu[1][0];
                priceOfItem = stoi(menu[1][1]);
            }else if(choice == 3){
                command = false;
                item = menu[2][0];
                priceOfItem = stoi(menu[2][1]);
            }else if(choice == 4){
                command = false;
                item = menu[3][0];
                priceOfItem = stoi(menu[3][1]);
            }else if(choice == 5){
                command = false;
                item = menu[4][0];
                priceOfItem = stoi(menu[4][1]);
            }else{
                cout<<"Sorry enter the correct option"<<endl;
            }
        }
    }
    void enterQuantityOfItem(){
        cout<<"Enter the Number of Quantities: ";
        cin>>quantity;
                totalPrice = priceOfItem * quantity;
        }
    void placeOrder(){
        cout<<"<-----Order----->"<<endl<<"Item-->"<<item<<endl<<"Price-->"<<priceOfItem<<endl<<"Quantity-->"<<quantity<<endl;
    }
    void cancelOrder(){
            item = "Null";
            priceOfItem = 0;
            cout<<"Your Order has been cancelled...;)"<<endl;
    }
    void viewOrder(){
        
            cout<<"ORDER--> "<<item<<endl;
            cout<<"Price--> "<<priceOfItem<<endl;
            cout<<"Total Price--> "<<totalPrice<<endl;
    }
    
};
#endif /* Order_Class_h */
