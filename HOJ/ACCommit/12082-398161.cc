#include <stdio.h>

int main()
{
    int t,n,data,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int sum = 0, b =0;
        int left = -1,c_i,c_j;

        for(i = 0; i < n; ++i)
        {
            scanf("%d",&data);
    
            if (b >= 0)
            {
                if(left == -1)
                    left = i;
                b += data;
            }
            else
            {
                if(data >= 0)
                    left = i;
                else
                    left = -1;
                b = data;
            }
            if (b > sum)
            {
                c_i = left+1;
                c_j = i+1;
                sum = b;
            }
        }
        printf("%d %d\n",c_i,c_j);
    }
    return 0;
}