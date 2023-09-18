#include <iostream>
using namespace std;

int main()
{
    char str[100];
    while(cin >>str)
    {
        char *p=&str[0];
        for(;;p++)
        {    if(*p==\':\'){p+=3;break;}}
        char *p2=p+1;
        for(;;p2++)
        {    if(*p2==\'.\'){*p2=\'\0\';break;}}
        cout <<"server: "<<p <<endl;
    }
    return 0;
}