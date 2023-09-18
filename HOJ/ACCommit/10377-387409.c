#include<stdio.h>
#include<math.h>
int iTestCase, time[5], angle[5], pt[5];
void Sort(){
    int i,j,t;
    for(i=0;i<4;++i)
        for(j=i+1;j<5;++j){
            if(angle[pt[i]]<angle[pt[j]]||
                (angle[pt[i]]==angle[pt[j]]&&time[pt[i]]<time[pt[j]])){
                t=pt[i];pt[i]=pt[j];pt[j]=t;
            }
        }
}
int main(){
    int i,h,m;
    scanf("%ld",&iTestCase);
    while(iTestCase--){
        for(i=0;i<5;++i){
            pt[i]=i;
            scanf("%ld:%ld",&h,&m);
            time[i]=h*100+m;
            h%=12;
            angle[i]=abs(m*11-h*60);
            angle[i]=angle[i]>360?720-angle[i]:angle[i];
        }
        Sort();
        printf("%02ld:%02ld\n", time[pt[2]]/100, time[pt[2]]%100);
    }
    return 0;
}