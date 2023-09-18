#include<cstdio>
int gs[9],k;
int iabs(int m){return m<0?-m:m;}
void output(int k){
    if(k<8){
        if(iabs(gs[k])!=1)printf("%ld",iabs(gs[k]));
        if(k==7){
            printf("x");
            return;
        }
        printf("x^%ld",8-k);
    }else{
        printf("%ld",iabs(gs[k]));
    }
}
int main(){
    while(scanf("%ld",&gs[0])!=EOF){
        for(int i=1;i<9;i++)scanf("%ld",&gs[i]);
        for(k=0;k<9&&gs[k]==0;k++);
        if(k>8){
            printf("0\n");
            continue;
        }
        if(gs[k]<0)printf("-");
        output(k);
        for(int i=k+1;i<9;i++){
            if(gs[i]<0)printf(" - ");
            if(gs[i]>0)printf(" + ");
            if(gs[i]!=0)output(i);
        }
        printf("\n");
    }
    return 0;
}