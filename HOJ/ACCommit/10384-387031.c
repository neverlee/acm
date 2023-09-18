#include<stdio.h>
int num, rect[101][101], row, col;
int i,j,tmp;
void Check(){
    row=col=-1;
    for(i=0;i<num;++i){
        tmp=0;
        for(j=0;j<num;++j)tmp^=rect[i][j];
        if(tmp!=0){
            if(row==-1)row=i;
            else{
                printf("Corrupt\n");
                return;
            }
        }
    }
    for(i=0;i<num;++i){
        tmp=0;
        for(j=0;j<num;++j)tmp^=rect[j][i];
        if(tmp!=0){
            if(col==-1)col=i;
            else{
                printf("Corrupt\n");
                return;
            }
        }
    }
    if(col==-1&&row==-1)printf("OK\n");
    else if(col!=-1&&row!=-1)printf("Change bit (%ld,%ld)\n",row+1,col+1);
    else printf("Corrupt\n");
}
int main(){
    while(scanf("%ld",&num),num){
        for(i=0;i<num;++i)for(j=0;j<num;++j)scanf("%ld",&rect[i][j]);
        Check();
    }
    return 0;
}