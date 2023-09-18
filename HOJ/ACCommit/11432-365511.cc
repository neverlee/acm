#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int ncase;cin >>ncase;
    unsigned long num;
    for(int text=0;text<ncase;text++)
    {
        cin >>num;
        cout <<(unsigned long)sqrt((double)num) <<endl;
    }
    return 0;
}