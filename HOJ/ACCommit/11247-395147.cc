#include<cstdio>
#include<ctype.h>
#include<cstring>
char str[1000], rect[5000];
int row, col;
void DealStr(){
    int i;
    for(i=0;str[i];++i)
        if(str[i]==32)str[i]=0;
        else str[i]-=64;
}
char GetK(int k){
    return (str[k/5] & (1<<(4-k%5)))?\'1\':\'0\';
}
void FillRect(){
    int r=0,c=0,er=row-1,ec=col-1,k=0,i;
    for(;r<=er&&c<=ec;++r,++c,--er,--ec){
        for(i=c;i<=ec;++i)rect[r*col+i]=GetK(k++);
        for(i=r+1;i<=er;++i)rect[i*col+ec]=GetK(k++);
        if(er-r>0)for(i=ec-1;i>=c;--i)rect[er*col+i]=GetK(k++);
        if(ec-c>0)for(i=er-1;i>r;--i)rect[i*col+c]=GetK(k++);
    }
    rect[row*col]=0;
}
int main(){
    int iTest;scanf("%ld",&iTest);
    for(int iCase=1;iCase<=iTest;++iCase){
        memset(str,0,sizeof(str));
        scanf("%ld%ld%*c%[ A-Z]",&row,&col,str);
        DealStr();
        FillRect();
        printf("%ld %s\n",iCase, rect);
    }
    return 0;
}