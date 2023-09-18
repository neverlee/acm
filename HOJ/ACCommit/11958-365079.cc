#include <iostream>
using namespace std;
const int SIZE=4000;
int result[SIZE];
int main()
{
    int ncase;cin >>ncase;int num,a,b;
    for(int text=0;text<ncase;text++)
    {
        for(int i=0;i<SIZE;i++)result[i]=0;
        cin >>num;
        for(int i=0;i<num;i++)
        {
            cin >>a >>b;
            for(int j=a;j<=a+b-1;j++)
                result[j]++;
        }
        int max=0;
        for(int i=0;i<SIZE;i++)
            if(result[i]>max)max=result[i];
        cout <<max <<endl;
    }
    return 0;
}