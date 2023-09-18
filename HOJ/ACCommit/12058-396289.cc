#include<cstdio>
int sh,sm,eh,em;
int main(){
    int iTest;scanf("%ld",&iTest);
    while(iTest--){
        scanf("%ld%ld%ld%ld",&sh,&sm,&eh,&em);
        eh+=sh;em+=sm;eh+=em/60;em%=60;
        printf("------+---------\n time | elapsed\n------+---------\n");
        if(sm>0)printf("%2ld:XX | XX - %ld\n", sh, sm);
        else printf("%2ld:XX | XX\n", sh);
        sm=60-sm;
        for(int i=sh+1;i<=eh;++i){
            int k=i%12;if(k==0)k=12;
            printf("%2ld:XX | XX + %ld\n", k, sm);
            sm+=60;
        }
    }
}