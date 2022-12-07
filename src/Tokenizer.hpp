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
    Token* newToken(TokenKind kind, char *start){

        Token *token = new Token(kind,start);
        if(cursorToken){
            cursorToken->setNextToken(token);
            cursorToken = token;
        }else{
            headerToken = cursorToken = token;
        }
        tokenCount++;
        return cursorToken;
    }

    bool isID_1(char c){
        return ('a' <= c && c <= 'z')||('A' <= c && c <= 'Z')|| c == '_';
    }
    bool isID_2(char c){
        return isID_1(c) || ('0' <= c && c <= '9');
    }

    int getPunct(char* p){
        if ( this->startswith(p,(char*)"==") || this->startswith(p,(char*)"!=")
           ||this->startswith(p,(char*)"<=") || this->startswith(p,(char*)">=") ){
            return 2;
        }
        return std::ispunct(*p) ? 1:0;
    }

    Token* tokenize(char *p){

        while(*p){

            if (std::isspace(*p)) {
                p++;
                continue;
            }
            // Number Literal
            if(std::isdigit(*p)){
                Token* tempToken = this->newToken(TokenKind::TK_NUM,p);
                char* q = p;
                tempToken->setIntValue(std::strtoul(p, &p, 10));
                tempToken->setLength(p - q);
                continue;
            }
            //ID && Keywords
            if (isID_1(*p)){
                char* start = p;
                do{
                    p++;
                }while(isID_2(*p));
                Token* tempToken = this->newToken(TokenKind::TK_IDENT,start);
                tempToken->setLength(p-start);
                continue;
            }

            //Punctuator
            int punctuatorLength = this->getPunct(p);
            if( punctuatorLength > 0 ){
                Token* tempToken = this->newToken(TokenKind::TK_PUNCT,p);
                p += punctuatorLength;
                tempToken->setLength(punctuatorLength);
                continue;
            }

            // Error
            Logger::error("invalid token");
            break;
        }
        this->newToken(TokenKind::TK_EOF,p);
        return headerToken;
    }


};