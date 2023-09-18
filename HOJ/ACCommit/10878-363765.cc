#include <iostream>
using namespace std;
int main()
{
    int n=0;
    char str[2000];
    while(cin.getline(str,1900))
        n++;
    cout <<n <<endl;
    return 0;
}