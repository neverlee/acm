#include<cstdio>
#include<cstring>
char str[100];
int rf[24]={0,0,100,500,0,0,0,0,1,0,0,50,1000,0,0,0,0,0,0,0,0,5,0,10};
int rtoi(){
    int n=0,i;
    for(i=0;str[i+1];++i){
        if(rf[str[i]-\'A\']<rf[str[i+1]-\'A\'])n-=rf[str[i]-\'A\'];
        else n+=rf[str[i]-\'A\'];
    }
    return n+rf[str[i]-\'A\'];
}

void Output(int num){
    int i,k;
    for(i=0,k=num/1000;i<k;++i)putchar(\'M\');
    num%=1000;
    k=num/100;
    if(k==9)printf("CM");
    else if(k==4)printf("CD");
    else {
        if(k>=5){putchar(\'D\');k-=5;}
        for(int j=0;j<k;++j)putchar(\'C\');
    }
    num%=100;
    k=num/10;
    if(k==9)printf("XC");
    else if(k==4)printf("XL");
    else {
        if(k>=5){putchar(\'L\');k-=5;}
        for(int j=0;j<k;++j)putchar(\'X\');
    }
    k=num%10;
    if(k==9)printf("IX");
    else if(k==4)printf("IV");
    else {
        if(k>=5){putchar(\'V\');k-=5;}
        for(int j=0;j<k;++j)putchar(\'I\');
    }
}
int main(){
    int num, total;
    for(int iTest=1;scanf("%ld",&num),num;++iTest){
        total=0;
        while(num--){
            scanf("%s",str);
            total+=rtoi();
        }
        printf("Case ");
        Output(iTest);
        printf(": ");
        Output(total);
        putchar(\'\n\');
    }
}
