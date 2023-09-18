#include<cstdio>
char From( char c ) {
    c-=\'a\';
    return c<5?c:5;
}
int main() {
    char str[100];
    int num[6]={0};
    char op, v1, v2;
    int n1, n2;
    while( gets(str) ) {
        str[0] = From( str[0] );
        if( 3 == sscanf( str+2, "%d%c%d", &n1, &op, &n2 ) )
            ;
        else if( 3 == sscanf( str+2, "%d%c%c", &n1 ,&op, &v2 ) )
            n2 = num[ From( v2 ) ];
        else if( ( 3 == sscanf( str+2, "%c%c%d", &v1, &op, &n2 ) )
                    && (op==\'+\'||op==\'*\') )
            n1 = num[ From( v1 ) ];
        else if( 3 == sscanf( str+2, "%c%c%c", &v1, &op, &v2 ) ) {
            n1 = num[ From( v1 ) ];
            n2 = num[ From( v2 ) ];
        }else continue;
        if( op==\'+\' )
            printf( "%d\n", num[ str[0] ] = n1 + n2 );
        else printf( "%d\n", num[ str[0] ] = n1 * n2 );
        num[5]=0;
    }
    for( int i=0; i<5; ++i )
        printf( "%c=%d\n", \'a\'+i, num[i] );
    puts( "n=0" );
}
