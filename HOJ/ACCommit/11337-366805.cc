#include <cstdio>
int main()
{
    int num[2][4];
    while(1)
    {
        for(int i=0;i<2;i++)
            for(int j=0;j<4;j++)
                scanf("%ld",&num[i][j]);
        if(num[0][0]==-1)return 0;
        if(!num[0][0]&&!num[0][1]&&!num[0][2]&&!num[0][3])
        {printf("0 0 0 0\n");continue;}
        int k=1;
        while(num[1][0]*k<num[0][0]
            ||num[1][1]*k<num[0][1]
            ||num[1][2]*k<num[0][2]
            ||num[1][3]*k<num[0][3])++k;
        for(int i=0;i<4;i++)
            num[0][i]=num[1][i]*k-num[0][i];
        printf("%ld %ld %ld %ld\n",num[0][0],num[0][1],num[0][2],num[0][3]);
    }
}