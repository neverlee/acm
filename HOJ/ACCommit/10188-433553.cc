#include <cstdio>
#include <cstring>
#include <cctype>

int inum;
char istr[60];
int input() {
    char c;
    while( (c=getchar()), !isalpha(c)&&!isdigit(c) ) putchar(c);
    if( isalpha(c) ) {
        istr[0] = c;
        int i;
        for( i=1; (c=getchar()), isalpha(c); ++i) istr[i]=c;
        istr[i] = 0;
        ungetc(c, stdin);
        return 0;
    }else {
        inum = c-\'0\';
        while( c=getchar(), isdigit(c) ) inum = inum*10+c-\'0\';
        ungetc(c, stdin);
        if( inum==0 ) return 2;
        return 1;
    }
}

//  queue
struct Node{
    char s[51];
    Node *next;
};
const int N = 10001;
Node lst[N], *head;
int id;
void init_list() {
    head = lst;
    id = 1;
    head->next = NULL;
}
void insert() {
    printf( "%s", istr );
    strcpy( lst[id].s, istr );
    lst[id].next = head->next;
    head->next = lst+id;
    ++id;
}
void find( int n ) {
    Node *p1, *p2;
    p1=head; p2=p1->next;
    while( --n>0 ) {
        p1=p2;
        p2=p1->next;
    }
    printf( "%s", p2->s );
    p1->next = p2->next;
    p2->next = head->next;
    head->next = p2;
}

int main() {
    int r;
    init_list();
    while( (r=input())!=2 ) {
        if( r==0 ) {
            insert();
        }else find( inum );
    }
}
