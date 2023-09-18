#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int imoney, icity, iroad;
const int UNLIMIT = 0x0fffffff;

int least[101];
struct DataCmp{
    bool operator() ( const int &a, const int &b ) {
        return least[a]>least[b];
    }
};
class DataMap{
protected:
    int data[101][101];
public:
    DataMap() {
        int i, j;
        for( i=0; i<=icity; ++i )
            for( j=0; j<=icity; ++j )
                data[i][j]=UNLIMIT;
    }
    void insert( int s, int t, int p ) {
        if( data[t][s]>p ) data[t][s]=p;
    }
    void dijstra() {
        int i;
        for( i=0; i<=icity; ++i ) least[i] = UNLIMIT;
        least[icity]=0;
        priority_queue<int, vector<int>, DataCmp> pq;
        pq.push( icity );
        while( !pq.empty() ) {
            int now = pq.top();
            do{
                pq.pop();
            }while( !pq.empty() && pq.top()==now );
            for( i=1; i<=icity; ++i )
            if( data[now][i]+least[now] < least[i] ) {
                least[i] = data[now][i]+least[now];
                pq.push( i );
            }
        }
        /*for( i=1; i<=icity; ++i )
            printf( "%4d", least[i] );
        printf("\n");*/
    }
};
struct Node{
    int to;
    int length, price;
    Node *next;
    void set( int t, int l, int p ) {
        to = t;
        length = l;
        price = p;
    }
    Node( int t=0, int l=0, int p=0, Node *n=NULL  ) {
        set( t, l, p );
        next = n;
    }
};
int fs[1100000];
struct FsCmp {
    bool operator() ( const int &a, const int &b ) {
        return fs[a]>fs[b];
    }
};
class Graph{
protected:
    Node *data[101];
public:
    Graph() {
        memset( data, 0, sizeof(data) );
    }
    void insert( int s, int t, int l, int p ) {
        data[s] = new Node( t, l, p, data[s] );
    }
    void init_status() {
        int i, ie;
        ie = (imoney+1)*icity;
        for( i=0; i<=ie; ++i ) fs[i]=UNLIMIT;
    }
    void dijstra() {
        int base = imoney+1;
        priority_queue< int, vector<int>, FsCmp > pq;
        fs[0] = 0;
        pq.push( 0 );
        while( !pq.empty() ) {
            int now = pq.top();
            do{
                pq.pop();
            }while( !pq.empty() && pq.top()==now );
            int imm, icc;
            imm = now%base;
            icc = now/base+1;
            if( icc==icity ) {
                printf( "%d", fs[now] );
                return;
            }
            Node *pn = data[icc];
            //printf( "recent is %d\n", icc );
            while( pn ) {
                int it = pn->to;
                int ip = imm+pn->price;
                int il = fs[now]+pn->length;
                //printf( "\tnext t:%d p:%d l:%d\n", it, ip, il );
                //printf( "\tnew price %d    \n", ip+least[it] );
                if( ip+least[it]<=imoney ) {
                    int pos = ip+(it-1)*base;
                    //printf( "\t to %d  pos:%d\n", it, pos );
                    if( fs[pos]>il ) {
                        fs[pos]=il;
                        pq.push(pos);
                    }
                }
                pn=pn->next;
            }
        }
    }
};
Graph myg;

int main() {
    int i;
    scanf( "%d%d%d", &imoney, &icity, &iroad );
    DataMap dm;
    int is, it, il, ip;
    for( i=0; i<iroad; ++i ) {
        scanf( "%d%d%d%d", &is, &it, &il, &ip );
        dm.insert( is, it, ip );
        myg.insert( is, it, il, ip );
    }
    dm.dijstra();
    if( least[1]==UNLIMIT||imoney<least[1] ) {
        puts("-1");
        return 0;
    }
    myg.init_status();
    myg.dijstra();
    return 0;
}