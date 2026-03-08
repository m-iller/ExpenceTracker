#include <iostream>
#include <fstream>

void logAction(std::string logMsg){
    std::ofstream log;
    log.open("logs/logfile.txt", std::ios::app);

    if(log.is_open()){
        log<<logMsg<<std::endl;
    }

    out.close();
}