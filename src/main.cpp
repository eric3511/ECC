#include "common"

#include "Logger.hpp"
#include "Tokenizer.hpp"

int main(int argc, char** argv){

//    if (argc != 3){
//        Logger::error("invalid number of arguments");
//        return -1;
//    }
    std::string buffer{"var64-2+35"};
    Tokenizer tokenizer;
    Token* token = tokenizer.tokenize(buffer.data());
    
    if(token == nullptr)
        return -1;
    std::cout<<"=========================start============"<<std::endl;
    while (token != nullptr)
    {
        std::cout<<"KIND:"<<static_cast<int>(token->getKind())<<std::endl;
        std::cout<<*token->getName()<<std::endl;
        token = token->getNext();
    }

    
    return 0;
}