#include<stdio.h>
#include<math.h>
#include<string.h>
int iTaskWorker[400], iSize, iNeedTime=0, iMinTime=99999999;
char cgUsed[20]={0}, cgResult[20], cgTemp[20];
void Copy(){
    int i;
    for(i=0;i<iSize;++i)cgResult[i]=cgTemp[i];
}
void DgWork(int iTask){
    int i;
    if(iTask==iSize){
        if(iMinTime>iNeedTime){
            iMinTime=iNeedTime;
            Copy();
        }
        return;
    }
    for(i=0;i<iSize;++i){
        if(cgUsed[i]==0){
            cgTemp[iTask]=i;
            cgUsed[i]=1;
            iNeedTime+=iTaskWorker[iTask*iSize+i];
            DgWork(iTask+1);
            cgUsed[i]=0;
            iNeedTime-=iTaskWorker[iTask*iSize+i];;
        }
    }
}
int main(){
    int i;
    for(iSize=0;EOF!=scanf("%ld",iTaskWorker+iSize);++iSize);
    iSize=(int)sqrt((double)iSize);
    DgWork(0);
    printf("The shortest time is %ld hours\n", iMinTime);
    for(i=0;i<iSize;++i)
        printf("Task %ld is distributed to employee %ld\n",i,cgResult[i]);
    return 0;
}