#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str[300];
    short len;
    int result;
    while(cin.getline(str,300))
    {
        if(str[0]==\'#\')return 0;
        len=strlen(str);
        result=0;
        for(int i=0;i<len;i++)
        {
            if(str[i]>=\'A\')
                result+=(i+1)*(str[i]-64);
        }
        cout <<result <<endl;
    }
}