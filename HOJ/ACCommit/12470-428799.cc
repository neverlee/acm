#include <cstdio>
#include <cstring>

char bnum[][40] = {
    ".* *. *. ** ** *. ** ** *. .* .*",
    "** .. *. .. .* .* *. ** ** *. **",
    ".. .. .. .. .. .. .. .. .. .. .."
};

char inum[110], ibum[3][400];
char str[110];
int len;
bool rct;

void BtoS() {
    for( int i=0; i<len; ++i ) {
        int r;
        for( r=0; r<10; ++r ) {
            bool f=1;
            for( int k=0; k<3; ++k )
            if( ibum[k][3*i]!=bnum[k][3*r]
                    || ibum[k][3*i+1]!=bnum[k][3*r+1] )
                f = 0;
            if( f==1 ) break;
        }
        inum[i] = \'0\'+r;
    }
    inum[len] = 0;
    puts( inum );
}

void StoB() {
    for( int i=0; i<len; ++i ) {
        int n = inum[i]-\'0\';
        for( int j=0; j<3; ++j )
            for( int k=0; k<3; ++k ) {
                ibum[j][3*i+k] = bnum[j][3*n+k];
            }
    }
    for( int i=0; i<3; ++i ) {
        ibum[i][3*len-1] = 0;
        puts( ibum[i] );
    }
}

int main() {
    while( gets(str), strcmp(str, "0") ) {
        sscanf( str, "%d", &len );
        gets( str );
        rct = str[0]==\'B\';
        if( rct ) {
            for( int i=0; i<3; ++i )
                gets( ibum[i] );
            BtoS();
        }else {
            gets( inum );
            StoB();
        }
    }
}

