#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> //tf is this ???
#include <ctime>

#include "logging.h"

void testFunc() {
    std::cout<<"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas vitae justo quis sapien varius accumsan."<<std::endl;
}

int addExpence(std::string userInputLine){ // e.g. command == "expence-tracker add --description "Dinner" --amount 20"
    userInputLine = userInputLine+" ";

    //need to write ID, Date, Desc, amount
    int expenceID;
    std::string expenceDesc;
    std::string expenceAmount;
    
    //getting last available ID
    std::ifstream fetchIDstream("data/expences.csv");
    std::string line;
    std::string lastline{""};
    if (fetchIDstream.is_open()) {
        while(getline(fetchIDstream, line)){
            if (line == ""){    break;  }
            lastline = line;
        } //TODO: Make it more effective than just reading all lines one by one (read  only last one)
        
        if(!(line=="")){
            size_t idEndIndex {line.find(",")};
            expenceID = stoi(line.substr(0, idEndIndex)) + 1;
        } else if(!(lastline=="")){
            size_t idEndIndex {lastline.find(",")};
            expenceID = stoi(lastline.substr(0, idEndIndex)) + 1;
        } else {expenceID = 0;}
    }
    fetchIDstream.close();

    logAction("Adding new expence id" + std::to_string(expenceID));

    //getting desc&amount
    size_t descIndex {userInputLine.rfind("--description")};
    size_t amountIndex {userInputLine.rfind("--amount")};

    if(descIndex==std::string::npos or amountIndex==std::string::npos){
        logAction("Command input failed//Invalid command arguments");
        std::cerr<<"Invalid command arguments"<<std::endl;

        return 0;
    }

    int count{0};
    size_t cash_amountIndex;
    size_t amountPos[2];
    size_t cash_LastAmountIndex{amountIndex};
    while(count<2){
        cash_amountIndex = userInputLine.find(" ", cash_LastAmountIndex+1);
        amountPos[count] = cash_amountIndex;
        cash_LastAmountIndex = cash_amountIndex;
        ++count;
    }
    expenceAmount = userInputLine.substr(amountPos[0]+1, amountPos[1]-amountPos[0]-1);

    count = 0;
    size_t cash_descIndex;
    size_t descPos[2];
    size_t cash_LastDescIndex{descIndex};
    while(count<2){
        cash_descIndex = userInputLine.find("\"", cash_LastDescIndex+1);
        descPos[count] = cash_descIndex;
        cash_LastDescIndex = cash_descIndex;
        ++count;
    }
    expenceDesc = userInputLine.substr(descPos[0]+1, descPos[1]-descPos[0]-1);

    //writing in datafile
    std::ofstream fetchInputStream("data/expences.csv",std::ios::app);

    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    if(fetchInputStream.is_open()){
        fetchInputStream<<expenceID<<","<<expenceDesc<<","+expenceAmount<<","<<std::put_time(&tm, "%Y-%m-%d")<<"\n";
    }
    fetchInputStream.close();

    return 0;
}