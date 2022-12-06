#pragma once

enum class TokenKind
{
  TK_RESERVED, // Keywords or punctuators
  TK_NUM,      // Integer literals
  TK_EOF,      // End-of-file markers
};


class Token
{
public:
  TokenKind kind; // Token kind
  Token* next;    // Next token
  long val;       // If kind is TK_NUM, its value
  char* str;      // Token string

public:
    Token(TokenKind _kind, char* _str):kind(_kind),str(_str){

    };

};
