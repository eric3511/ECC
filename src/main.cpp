#include "common"

#include "Logger.hpp"
#include "Tokenizer.hpp"

int main(int argc, char** argv){

    if (argc != 3){
        Logger::error("invalid number of arguments");
        return -1;
    }

    Tokenizer tokenizer;
    Token* token = tokenizer.tokenize(argv[2]);
    
    if(token == nullptr)
        return -1;
    
    while (token != nullptr)
    {
        std::cout<<static_cast<int>(token->kind);
        Logger::info(token->str);
        token = token->next;
    }

    
    return 0;
}