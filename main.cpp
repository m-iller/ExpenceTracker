#include <iostream>
#include <limits>

/*
#include "sdtfun.h"
#include "expfun.h"
*/

using namespace std;

/*
exp_mngr:
    test - testing command returns smth
    endprg - ends the programm
*/

int main(){
    string userInput {"none"};

    while (true) {
        getline(cin, userInput);
        userInput = userInput + " ";

        //cout<<userInput;

        if(userInput.find("exp_mngr") == 0) {
            int count {0};

            size_t cashInpApp;
            size_t cashLastApp {0};

            size_t cmdPos [2];

            while(count<2){
                cashInpApp = userInput.find(" ", cashLastApp+1);

                cmdPos[count] = cashInpApp;

                cashLastApp = cashInpApp;

                cout<<cmdPos[count]<<endl;
                ++count;
            }

            string command {userInput, cmdPos[0], cmdPos[1]-cmdPos[0]-1};
            cout<<command;
        }
    }

    return 0;
}