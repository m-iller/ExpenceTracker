#include <iostream>

using namespace std;

string firstScrnMsg[2] = {
    "Please select action:",
    "0. Exit"
};

int main(){
    short int ctrlnum {100};
    int FSMsgSize {sizeof(firstScrnMsg)/sizeof(firstScrnMsg[0])};

    while (true) {
        for (int i {0}; i<FSMsgSize; i++){
            cout<<firstScrnMsg[i]<<endl;
        }

        if (!(cin>>ctrlnum)){
            cout<<"Invalid input..."<<endl;
            cin.clear();
            cin.ignore();

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

        cout<<"\x1b[2J\x1b[1;1H"; //ANSI code to clean up terminal
        cout.flush();
    }
}