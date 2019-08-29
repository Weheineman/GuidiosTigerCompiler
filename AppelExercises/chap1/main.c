#include <stdio.h>
#include "main.h"
// #include <algorithm>

int max(int a, int b){
    return a < b ? b : a;
}

int maxArgsStm(A_stm s){
    int ans = 0;
    switch(s->kind){
        case A_compoundStm:
            ans = max(maxArgsStm(s->u.compound.stm1),
                      maxArgsStm(s->u.compound.stm2));
            break;

        case A_assignStm:
            ans = maxArgsExp(s->u.assign.exp);
            break;

        case A_printStm:
            ans = maxArgsExpList(s->u.print.exps);
            ans = max(ans, expListSize(s->u.print.exps));
            break;
    }

    return ans;
}

int maxArgsExp(A_exp e){
    int ans = 0;
    switch(e->kind) {
        case A_idExp:
            break;

        case A_numExp:
            break;

        case A_opExp:
            break;

        case A_eseqExp:
            ans = maxArgsStm(e->u.eseq.stm);
            ans = max(ans, maxArgsExp(e->u.eseq.exp));
            break;
    }

    return ans;
}

int maxArgsExpList(A_expList el){
    int ans = 0;
    switch (el->kind) {
        case A_pairExpList:
            ans = maxArgsExp(el->u.pair.head);
            ans = max(ans, maxArgsExpList(el->u.pair.tail));
            break;
        case A_lastExpList:
            ans = maxArgsExp(el->u.last);
            break;
    }
    return ans;
}

int expListSize(A_expList el){
    switch (el->kind) {
        case A_pairExpList:
            return 1 + expListSize(el->u.pair.tail);

        case A_lastExpList:
            return 1;
    }
}


Table interpStm(A_stm s, Table t){
    switch(s->kind){
        case A_compoundStm:
            ans = max(maxArgsStm(s->u.compound.stm1),
                      maxArgsStm(s->u.compound.stm2));
            break;

        case A_assignStm:
            ans = maxArgsExp(s->u.assign.exp);
            break;

        case A_printStm:
            ans = maxArgsExpList(s->u.print.exps);
            ans = max(ans, expListSize(s->u.print.exps));
            break;
    }
}

int main(){
    printf("%d\n", maxArgsStm(prog()));
    return 0;
}
