#include<cstdio>
int xlen, ylen, amount, works;
int rbx[110], rby[110], rbd[110];
int dx[]={ 0, 1, 0,-1};
int dy[]={ 1, 0,-1, 0};
char rect[110][110];
void Check() {
    int n, foot, imin;
    char sy, flag=1;
    for( int i=0; i<works; ++i ) {
        scanf( "%d %c %d", &n, &sy, &foot );
        if( flag ) {
        --n;
        if( sy==\'L\' ) rbd[n]=((rbd[n]-foot)%4+4)%4;
        else if( sy==\'R\' ) rbd[n]=(rbd[n]+foot)%4;
        else {
            int ax=rbx[n]+dx[rbd[n]], ay=rby[n]+dy[rbd[n]], mk;
            for( mk=0; mk<foot&&rect[ax][ay]==0; ++mk ){
                ax+=dx[rbd[n]];
                ay+=dy[rbd[n]];
            }
            if( mk<foot ) {
                printf( "Robot %d crashes into ", n+1 );
                if( rect[ax][ay]==-1 )
                    printf( "the wall\n" );
                else printf( "robot %d\n", rect[ax][ay]);
                flag=0;
            }else {
                rect[rbx[n]][rby[n]]=0;
                rbx[n]=ax-dx[rbd[n]];
                rby[n]=ay-dy[rbd[n]];
                rect[rbx[n]][rby[n]]=n+1;
            }
        }
        }
    }
    if( flag ) puts( "OK" );
}
int main(){
    int iTest; scanf( "%d", &iTest );
    while( iTest-- ) {
        scanf( "%d%d%d%d", &xlen, &ylen, &amount, &works );
        char cd;
        for( int i=1; i<=xlen; ++i )
            for( int j=1; j<=ylen; ++j )
                rect[i][j]=0;
        for( int i=0; i<=xlen+1; ++i )
            rect[i][0]=rect[i][ylen+1]=-1;
        for( int i=1; i<=ylen; ++i )
            rect[0][i]=rect[xlen+1][i]=-1;
        for( int i=0; i<amount; ++i ) {
            scanf( "%d %d %c", rbx+i, rby+i, &cd );
            rect[rbx[i]][rby[i]]=i+1;
            switch( cd ) {
            case \'N\': rbd[i]=0;break;
            case \'E\': rbd[i]=1;break;
            case \'S\': rbd[i]=2;break;
            case \'W\': rbd[i]=3;break;
            }
        }
        Check();
    }
}
