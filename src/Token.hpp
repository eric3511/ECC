#pragma once
#include<memory>

enum class TokenKind
{
    TK_IDENT,   // Identifiers
    TK_PUNCT,   // Punctuators
    TK_KEYWORD, // Keywords
    TK_NUM,     // Numeric literals
    TK_EOF,     // End-of-file markers
};


class Token
{
//public:
    TokenKind kind; // Token kind
    Token* next;    // Next token
    int val;        // If kind is TK_NUM, its value
    char *loc;      // Token location
    uint32_t len;        // Token length

public:
    Token(TokenKind _kind,char* _loc):kind(_kind),loc(_loc){};

    void setLength(uint32_t length){
        this->len = length;
    }
    void setNextToken(Token* next){
        this->next = next;
    }
    void setIntValue(int value){
        this->val = value;
    }

    //just for test
    std::unique_ptr<std::string> getName(){
        return std::make_unique<std::string>(this->loc,this->len);
    }

    Token* getNext(){
        return this->next;
    }
    TokenKind getKind(){
        return this->kind;
    }


};
