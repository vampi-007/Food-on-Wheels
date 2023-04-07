//
//  Menu-class.h
//  Food-on-Wheels
//
//  Created by Abdulrehman Mughal on 07/08/2022.
//

//#ifndef Menu_class_h
//#define Menu_class_h
#include "Global-Variables.h"
#include <iostream>
using namespace std;



class Menu{
protected:
    int prices[5];
    string menu[5][2];
public:
    void viewMenu(){
        for(int row = 0 ;row<5;row++){
            cout<<row+1<<").";
            for(int col = 0; col<2; col++){
                cout<<menu[row][col]<<"   ";
            }
            cout<<endl;
        }
    }
};
//#endif /* Menu_class_h */
