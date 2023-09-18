#include <iostream>
using namespace std;

int result[]={0,0,6,12,90,360,2040,10080,54810,290640,1588356,8676360,47977776,266378112,1488801600};

int main()
{
    int ncase,num;cin >>ncase;
    for(int text=0;text<ncase;text++)
    {
        cin >>num;
        printf("%ld\n",result[num]);
    }
    return 0;
}