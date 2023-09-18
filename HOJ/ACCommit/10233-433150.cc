#include <cstdio>

struct Node{
    char val;
    int count;
    Node *son, *brother;
    void set( char v, Node *nb ) {
        val = v;
        brother = nb;
        son = NULL;
        count = 0;
    }
};

const int N = 200000;
Node tree[N]; int id;

void init() {
    tree[0].count = -1;
    tree[0].son = NULL;
    tree[0].brother = NULL;
    id = 1;
}

void insert( char *ss ) {
    Node *p1, *p2, ntmp, *pre;
    pre = tree;
    ntmp.val = -1;
    for( char *pc=ss; *pc; ++pc ) {
        ntmp.brother = pre->son;
        p1 = &ntmp; p2 = p1->brother;
        while( p2 && p2->val<=*pc ) {
            p1 = p2;
            p2 = p2->brother;
        }
        if( p1->val<*pc ) {
            tree[id].set( *pc, p2 );
            p1->brother = tree+id;
            p1 = tree+id;
            ++id;
        }
        pre->son = ntmp.brother;
        pre = p1;
    }
    ++(pre->count);
}
int amount;
char str[40];
void visit( Node *p, int lv ) {
    if( !p ) return;
    for( ; p; p=p->brother ) {
        str[lv] = p->val;
        if( p->count ) {
            str[lv+1] = 0;
            printf( "%s %.4lf\n", str, (double)p->count*100/amount );
        }
        visit( p->son, lv+1 );
    }
}

int main() {
    char str[40];
    amount = 0;
    init();
    while( gets(str) ) {
        if( str[0]==0 ) continue;
        insert( str );
        ++amount;
    }
    visit( tree[0].son, 0 );
}
