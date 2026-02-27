#include <iostream>
#include <limits>

#include "sdtfun.h"
#include "expfun.h"

using namespace std;

string firstScrnMsg[3] = {
    "Please select action:",
    "1. Add expence.",
    "0. Exit."
};

int main(){
    short int ctrlnum {100};
    
    string expUnform {"Default"};

    int FSMsgSize {sizeof(firstScrnMsg)/sizeof(firstScrnMsg[0])};

    while (ctrlnum!=0) {
        for (int i {0}; i<FSMsgSize; i++){
            cout<<firstScrnMsg[i]<<endl;
        }

        if (!(cin>>ctrlnum)){//Input validation
            cout<<"Invalid input..."<<endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            pressEnter();
            ctrlnum = 100;
        }

        switch (ctrlnum)
        {
        case 0: //Exit
            break;
        case 1: //Add expence
            cout<<"Creating new expence...\n Please enter expence:\nFormat - Amount;DD;MM;Description;\n>>>\t";
            cin>>expUnform;

        case 100: //pass; for error handling
            break;
        default:
            break;
        }
    }

    return 0;
}