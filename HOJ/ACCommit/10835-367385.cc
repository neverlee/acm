#include <iostream>
using namespace std;
int a[3];
const int d=168;
int main()
{
    cin >>a[0] >>a[1] >>a[2];
    for(int i=0;i<3;i++)
        if(a[i]<=d){cout <<"CRASH " <<a[i];return 0;}
    cout <<"NO CRASH";return 0;
    return 0;
}