#include <cstdio>

void Space(int n)
{
    int n3=1;
    for(int i=0;i<n;i++)n3*=3;
    for(int i=0;i<n3;i++)putchar(\' \');
}

void Dg(int n)
{
    if(!n){putchar(\'-\');return;}
    Dg(n-1);Space(n-1);Dg(n-1);
}

int main()
{
    int num;
    while(scanf("%ld",&num)!=EOF)
    {Dg(num);putchar(\'\n\');}
    return 0;
}
