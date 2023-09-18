#include<stdio.h>
int itest_case, igrect[15][15], irect_size, itest, i, j, imother;
char CanAdd(){
    imother=igrect[0][0];
    for(i=0;i<irect_size;++i)
        for(j=0;j<irect_size;++j){
            igrect[i][j]-=imother;
            if(igrect[i][j]!=igrect[i][0]+igrect[0][j])return 0;
        }
    return 1;
}
int main(){
    scanf("%ld",&itest_case);
    for(itest=1;itest<=itest_case;++itest){
        scanf("%ld",&irect_size);
        for(i=0;i<irect_size;++i)
            for(j=0;j<irect_size;++j)
                scanf("%ld",&igrect[i][j]);
        if(CanAdd())printf("%ld. YES\n",itest);
        else printf("%ld. NO\n",itest);
    }
    return 0;
}