#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace::std;
#define Mod 1000
int n,j,lab=0,m[1000]={0};
char a[10]={'\0'};

int cal(){
    int s[10]={0},k=0,arg1,arg2,num=0,oper;
    while(++num){
        oper=m[k]/100;
        arg1=m[k]%100/10;
        arg2=m[k]%10;
        k=(k+1)%Mod;
        if(oper==1)
            return num;
        else if(oper==2) 
            s[arg1]=arg2;
        else if(oper==3) 
            s[arg1]=(s[arg1]+arg2)%Mod;
        else if(oper==4) 
            s[arg1]=(s[arg1]*arg2)%Mod;
        else if(oper==5) 
            s[arg1]=s[arg2];
        else if(oper==6) 
            s[arg1]=(s[arg1]+s[arg2])%Mod;
        else if(oper==7) 
            s[arg1]=(s[arg1]*s[arg2])%Mod;
        else if(oper==8) 
            s[arg1]=m[s[arg2]];
        else if(oper==9) 
            m[s[arg2]]=s[arg1];
        else if(oper==0)
            if(s[arg2]) 
                k=s[arg1];
    }
    return 0;
}
int main(){
    scanf("%d\n",&n);
    while(lab<n){
        j=0;
        while(gets(a)!=NULL){
            if(!isdigit(a[0])) 
                break;
            sscanf(a,"%d",&m[j++]);
        }
        if(lab)printf("\n");
        printf("%d\n",cal());
        lab++;
    }
    return 0;
}