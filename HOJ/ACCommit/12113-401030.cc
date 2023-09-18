#include<cstdio>
char str[100];
int main(){
    int a,b,t;
    scanf( "%d%*c", &t );
    while( t-- ){
        gets(str);
        if( sscanf( str, "%d+%d", &a, &b) == 2 )
            printf( "%d\n", a+b );
        else puts( "skipped" );
    }
}
