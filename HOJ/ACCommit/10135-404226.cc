#include<cstdio>
#include<cstring>
char str1[100], str2[100];
int file, bit;
int erm, nrm;
bool CheckBit() {
    int len = strlen( str1 )-1;
    for( int i=0; i<bit; ++i ) {
        if( str1[i]!=str2[i] || str1[len-i]!=str2[len-i] )
            return 0;
    }
    return 1;
}

int main() {
    while( EOF != scanf( "%d %d", &file, &bit ) ) {
        erm=nrm=0;
        while( file-- ) {
            scanf( "%s%s", str1, str2 );
            erm += (strcmp( str1, str2 ) == 0 );
            nrm += CheckBit();
        }
        printf( "%d %d\n", nrm, erm );
    }
}