#include <iostream>
using namespace std;

int main()
{
    int ncase;
    cin >>ncase;
    long num;
    short n[20],wei;
    for(int text=0;text<ncase;text++)
    {
        cin >>num;
        if(!num)cout <<0 <<endl;
        wei=0;
        while(num>0){n[wei]=num%10;num/=10;wei++;}
        n[wei]=0;
        for(int i=0;i<wei-1;i++)
        {
            if(n[i]>4)
            {
                n[i+1]++;
                if(n[i+1]>9){n[i+1]%=10;n[i+2]++;}
            }
            n[i]=0;
        }
        if(n[wei])wei++;
        for(int i=wei-1;i>=0;i--)
            cout <<n[i];
        cout <<endl;
    }
    return 0;
}