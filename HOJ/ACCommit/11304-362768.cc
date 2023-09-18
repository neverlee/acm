#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str1[120],str2[120];
    short num,len;
    while(cin >>str1 >>str2)
    {
        if(str1[0]==\'X\')return 0;
        num=0;;len=strlen(str1);
        for(int i=0;i<len;i++)
            if(str1[i]!=str2[i])num++;
        cout <<"Hamming distance is " <<num <<"." <<endl;
    }
}