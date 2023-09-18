#include<cstdio>
int num, ary[27],red[27],i,j,k;
int main(){
    while(scanf("%ld",&num),num){
        for(i=1;i<=num;++i)scanf("%ld",ary+i);
        for(i=num;i>0;--i)ary[i]-=ary[i-1];

        for(i=1,k=0;i<=num;++i)
            for(j=0;j<ary[i];++j)
                red[k++]=i;
        for(i=0;i<k-1;++i)printf("%ld ",red[i]);
        printf("%ld\n",red[k-1]);
    }
}
