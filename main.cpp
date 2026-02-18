#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    short int ctrlnum {1};

    while (true) {
        cout<<"Type 0 to exit:"<<endl;
        cin>>ctrlnum;
        cout<<ctrlnum<<endl; //neverending loop idk

        switch (ctrlnum)
        {
        case 0:
            return 0;
            break;
        
        default:
            break;
        }
    }
}