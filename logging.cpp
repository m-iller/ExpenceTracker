#include <iostream>
#include <fstream>

void logAction(std::string logMsg){ //adds a log message to the file
    std::ofstream log;
    log.open("logs/logfile.txt", std::ios::app);

    if(log.is_open()){
        log<<logMsg<<std::endl;
    }

    log.close();
}