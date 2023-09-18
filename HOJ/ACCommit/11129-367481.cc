#include <iostream>
using namespace std;
int a,b,c;
int main()
{
    while(cin >>a >>b >>c)
        if((a-b)%3&&(b-c)%3&&(a-c)%3)
            cout <<"NO" <<endl;
        else cout <<"YES" <<endl;
    return 0;
}
