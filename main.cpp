#include <iostream>
#include <limits>


#include "sdtfun.h"
#include "expfun.h"


using namespace std;

/*
exp_mngr:
    test - testing command returns smth
    end - ends the programm
    add -m (commentary message) --name (expense name, default - noName) --amount (default 0) 
*/

int main(){
    string userInput {"none"};

    while (true) {
        string cmd{};
        
        getline(cin, userInput);
        userInput = userInput + " ";

        if(userInput.find("expence_manager") == 0) {
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

            string command {userInput, cmdPos[0]+1, cmdPos[1]-cmdPos[0]-1};
            cmd = command; //LOG: command call
        }

        if (cmd == "test") {
            testFunc();
        } else if (cmd == "end") {
            return 0;
        }
    }

    return 0;
}