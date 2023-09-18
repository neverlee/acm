#include <iostream>
#include <string.h>
#include <fstream>
using namespace::std;
int main()
{
    char a[100010],b[500][500];
    int flag=1;
    while (gets(a)) 
    {
        for(int i=0;i<500;i++)
            for(int j=0;j<500;j++)
                b[i][j]=0;
        unsigned long i,j,k,lab,count=1,len=strlen(a);
        for (k=0; k<len;) 
        {
            if (count%2==0) 
            {
                for (i=1,j=count; j>=1&&k<len; i++,j--)
                    b[i][j]=a[k++];
                count++;
            }
            else 
            {
                for (i=count,j=1; i>=1&&k<len; i--,j++)
                    b[i][j]=a[k++];
                count++;
            }
        }
        cout << "Matrix " << flag++ << ":\n";
        k=0;
        for (i=1; i<=count; i++) 
        {
            lab=1;
            for (j=1; j<=count&&b[i][j]!=\'\0\'; j++)
            {
                if (j>1)
                    cout << \' \';
                cout << b[i][j];
                if (k>=len)
                    break;
                k++;
                lab=0;
            }
            if (lab==0)
                cout << \'\n\';
        }
    }
    return 0;
}