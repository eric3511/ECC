#pragma once

#include<cctype>
#include<cstdlib>
#include<cstring>

#include "Token.hpp"
#include "Logger.hpp"

class Tokenizer
{
    Token* cursorToken = nullptr;
    Token* headerToken = nullptr;

    unsigned int tokenCount = 0;
private:
    bool startswith(char *p, char *q){
        return std::strncmp(p,q,std::strlen(q)) == 0;
    }
    
public:
    Token* newToken(TokenKind kind, char *str){

        Token *token = new Token(kind,str);
        if(cursorToken){
            cursorToken->next = token;
            cursorToken = token;
        }else{
            headerToken = cursorToken = token;
        }

        return cursorToken;
    }

    Token* tokenize(char *p){

        while(*p){

            if (std::isspace(*p)) {
                p++;
                continue;
            }

            if (  this->startswith(p,"==") || this->startswith(p,"!=")
                ||this->startswith(p,"<=") || this->startswith(p,">=") ){
                p += 2;
                this->newToken(TokenKind::TK_RESERVED,p);
                tokenCount++;
                continue;
            }
            // TODO continue;

            if ( *p == '+' || *p == '-') {
                this->newToken(TokenKind::TK_RESERVED,p++);
                tokenCount++;
                continue;
            }
            
            if(std::isdigit(*p)) {
                this->newToken(TokenKind::TK_NUM,p);
                //TODO think a lot
                this->cursorToken->val = strtol(p, &p, 10);
                tokenCount++;
                continue;
            }
            Logger::error("invalid token");    
        }
        this->newToken(TokenKind::TK_EOF,p);
        return headerToken;
    }


};