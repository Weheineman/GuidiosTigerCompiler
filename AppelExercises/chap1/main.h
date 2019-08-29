
#include "prog1.h"
#include <list>

int maxArgsStm(A_stm s);

int maxArgsExp(A_exp e);

int maxArgsExpList(A_expList el);

int expListSize(A_expList el);

struct TableNode{
    cString id;
    int value;
};

typedef list<TableNode> *Table;

int lookup(Table t, cString id);

Table interpStm(A_stm s, Table t);
