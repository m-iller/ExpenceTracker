#include <iostream>
#include <limits>

#include "sdtfun.h"
#include "expfun.h"

using namespace std;

string firstScrnMsg[3] = {
    "Please select action:",
    "1. Add expence."
    "0. Exit."
};

int main(){
    short int ctrlnum {100};
    int FSMsgSize {sizeof(firstScrnMsg)/sizeof(firstScrnMsg[0])};

    while (true) {
        for (int i {0}; i<FSMsgSize; i++){
            cout<<firstScrnMsg[i]<<"\n"<<endl;
        }

        if (!(cin>>ctrlnum)){
            cout<<"Invalid input..."<<endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            pressEnter();
            ctrlnum = 100;
        }

        switch (ctrlnum)
        {
        case 0:
            return 0;
            break;
        case 100: //always continue; for error handling
            break;
        default:
            break;
        }
    }
}