#pragma once
#include "common"


class Logger
{
public:
    //TODO refactor
    
    static void info(std::string info){
        std::cout<<"Info:"<<info<<std::endl;
    }
    
    static void error(std::string info){
        std::cout<<"Error:"<<info<<std::endl;
    };

};