#include <iostream>
#include <fstream>
#include <filesystem>

void ensureDataEnvironment(){
    namespace fs = std::filesystem;
    fs::create_directories("data");
    fs::create_directories("logs");
    const char* dataPath {"data/expences.csv"};
    if (!fs::exists(dataPath)){
        std::ofstream createData(dataPath);
        createData.close();
    }
    const char* logPath {"logs/logfile.txt"};
    if (!fs::exists(logPath)){
        std::ofstream createLog(logPath);
        createLog.close();
    }
}

void logAction(std::string logMsg){ //adds a log message to the file
    ensureDataEnvironment();
    std::ofstream log;
    log.open("logs/logfile.txt", std::ios::app);

    if(log.is_open()){
        log<<logMsg<<std::endl;
    }

    log.close();
}