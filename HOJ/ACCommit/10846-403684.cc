#include<cstdio>
#include<queue>
using namespace std;
char str[100];
struct Node {
    int time, value;
    Node *left, *right;
    Node() {
        time=0;
        value=0;
        left=right=NULL;
    }
};
struct Tree {
    Node *head;
    void Create() {
        head = new Node;
    }
    void Destroy( Node *pos ) {
        if( pos->left ) Destroy( pos->left );
        if( pos->right ) Destroy( pos->right );
        delete pos;
    }
    void Add( char *str ) {
        int v, si;
        sscanf( str, "(%d", &v );
        for( si=1; str[si]!=\',\'; ++si );
        Node *p=head;
        for( ; str[si]; ++si ) {
            if( str[si]==\'L\' ) {
                if( p->left==NULL )
                    p->left=new Node;
                p=p->left;
            }
            if( str[si]==\'R\' ) {
                if( p->right==NULL )
                    p->right=new Node;
                p=p->right;
            }
        }
        ++(p->time);
        p->value=v;
    }
    bool Check( Node *pos ) {
        if( pos==NULL ) return true;
        if( pos->time!=1 ) return false;
        return Check( pos->left ) && Check( pos->right );
    }
    void Output() {;
        queue<Node*> aqe;
        aqe.push( head );
        while( !aqe.empty() ) {
            if( aqe.front()->left )
                aqe.push( aqe.front()->left );
            if( aqe.front()->right )
                aqe.push( aqe.front()->right );
            printf( "%d", aqe.front()->value );
            if( aqe.size()>1 ) putchar(\' \');
            aqe.pop();
        }
        putchar(\'\n\');
    }
};
int main() {
    Tree atr;
    atr.Create();
    while( EOF != scanf( "%s", str ) ) {
        if( str[1]==\')\' ) {
            if( atr.head==NULL || atr.Check( atr.head )==false )
                printf( "not complete\n" );
            else atr.Output();
            atr.Destroy( atr.head );
            atr.Create();
        }else atr.Add( str );
    }
    return 0;
}