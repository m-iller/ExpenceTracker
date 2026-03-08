#include <iostream>
#include <limits>

#include "expfun.h"
#include "logging.h"


using namespace std;

/*
expence-tracker:
    test - testing command returns smth
    end - ends the programm
    add --description --amount 
*/

int main(){
    string userInput {"none"};

    while (true) {
        string cmd{};
        
        getline(cin, userInput);
        userInput = userInput + " ";

        if(userInput.find("expence-tracker") == 0) {
            int count {0};

            size_t cashInpApp;
            size_t cashLastApp {0};

            size_t cmdPos [2];

            while(count<2){
                cashInpApp = userInput.find(" ", cashLastApp+1);
                cmdPos[count] = cashInpApp;
                cashLastApp = cashInpApp;
                ++count;
            }

            string command {userInput, cmdPos[0]+1, cmdPos[1]-cmdPos[0]-1};
            cmd = command; 
            logAction("User has called a command");
        } 

        if (cmd == "test") {
            testFunc();
        } else if (cmd == "end") {
            return 0;
        } else if (cmd == "add") {
            addExpence(userInput);
        } else {
            logAction("Command input failed//Invalid command input");
            cerr<<"Invalid command input"<<endl;
        }
    }

    return 0;
}