#include<cstdio> 

int main()
{
    int a,b;
    scanf("%ld%ld",&a,&b);
    FILE *fp=fopen("ACMOut.txt","w");
    fprintf(fp,"%ld",a+b);
    fclose(fp);
    fp=fopen("ACMOut.txt","r");
    fscanf(fp,"%ld",&a);
    printf("%ld",a);
    return 0;
}