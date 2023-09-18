#include<cstdio>
char name[][10]={ "Bird", "Pomelo" };
int n, p; char str[10];
int main() {
    while( scanf( "%d %s", &n, str )==2 && n ) {
        p = str[0]==\'B\';
        if( n<3 ) p=!p;
        puts( name[p] );
    }
}