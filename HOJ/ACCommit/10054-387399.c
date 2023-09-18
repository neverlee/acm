#include<stdio.h>
short iStackIn[1200], iTopIn, iStackDe[1200], iTopDe, iTmp, i;
int main(){
    iStackIn[0]=-1;iStackDe[0]=32700;
    for(iTopIn=iTopDe=0;EOF!=scanf("%d",&iTmp);){
        if(iTmp>iStackIn[iTopIn])iStackIn[++iTopIn]=iTmp;
        else{
            for(i=iTopIn;iStackIn[i]>=iTmp;--i);
            iStackIn[i+1]=iTmp;
        }
        if(iTmp<=iStackDe[iTopDe])iStackDe[++iTopDe]=iTmp;
        else{
            for(i=iTopDe;iStackDe[i]<iTmp;--i);
            iStackDe[i+1]=iTmp;
        }
    }
    printf("%ld %ld",iTopDe, iTopIn);
    return 0;
}