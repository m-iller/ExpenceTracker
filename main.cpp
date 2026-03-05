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
        cin>>userInput;
        userInput += " ";

        if(userInput.find("exp_mngr") == 0) {
            int count {0};

            size_t cashInpApp;
            size_t cashLastApp {0};

            size_t cmdPos [2];

            while(count<=2){
                cashInpApp = userInput.find(" ", cashLastApp);

                cmdPos[count] = cashInpApp;

                cashLastApp = cashInpApp;

                ++count;
            }

            string command {userInput, cmdPos[0], cmdPos[1]-cmdPos[0]};
            cout<<command;
        }

        userInput = ;
    }

    return 0;
}