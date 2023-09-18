#include<cstdio>
#include<cstring>
int aiHave[81], iPeople, iTeam, iPos;

int GetNext(){
    for(;iPos<81;){
        if(aiHave[iPos]){
            --aiHave[iPos];
            return iPos;
        }else ++iPos;
    }
}
char Check(){
    int min, max;
    double avg=0;
    for(int i=0;i<iPeople;i+=iTeam){
        avg=min=GetNext();
        for(int j=2;j<iTeam;++j)avg+=GetNext();
        avg+=(max=GetNext());
        avg/=iTeam;
        if(avg-min>2||max-avg>2)return 0;
    }
    return 1;
}
int main(){
    char str[100];
    for(int iTest=1;scanf("%ld%ld",&iPeople,&iTeam),iPeople;++iTest){
        memset(aiHave, 0, sizeof(aiHave));
        for(int i=0;i<iPeople;++i){
            scanf("%s",str);
            ++aiHave[strlen(str)];
        }
        iPos=1;
        if(iTest!=1)putchar(\'\n\');
        printf("Case %ld: ", iTest);
        if(iTeam==1||Check())printf("yes\n");
        else printf("no\n");
    }
    return 0;
}


