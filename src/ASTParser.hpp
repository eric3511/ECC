#pragma once
#include "common"
#include "Token.hpp"


enum class NodeKind
{
  ND_ADD, // +
  ND_SUB, // -
  ND_MUL, // *
  ND_DIV, // /
  ND_EQ,  // ==
  ND_NE,  // !=
  ND_LT,  // <
  ND_LE,  // <=
  ND_NUM, // Integer
};



class Node
{
public:
    NodeKind kind;
    Node* leftSide;
    Node* rightSide;
    long val;  // Used if kind == ND_NUM

};


class ASTParser
{
    Token* token;
private:
    bool consume(char* op);
public:
    static Node* newNode(NodeKind kind);
    static Node* newBinary(NodeKind kidn,Node* left,Node* right);
    static Node* newNumber(int val);

public:
    static Node *expr(void);
    static Node *equality(void);
    static Node *relational(void);
    static Node *add(void);
    static Node *mul(void);
    static Node *unary(void);
    static Node *primary(void);

};