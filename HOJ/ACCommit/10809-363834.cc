#include <iostream>
using namespace std;

int sudoku[10][10];

void Input()
{
    for(int i=1;i<=9;i++)
        for(int j=1;j<=9;j++)
            cin >>sudoku[i][j];
}

bool check[10];
void Clear()
{for(int i=1;i<=9;i++)check[i]=0;}

bool IsRight()
{
    for(int i=1;i<=9;i++)
    {
        Clear();
        for(int j=1;j<=9;j++)
            check[sudoku[i][j]]=1;
        for(int j=1;j<=9;j++)
            if(!check[j])return 0;
        Clear();
        for(int j=1;j<=9;j++)
            check[sudoku[j][i]]=1;
        for(int j=1;j<=9;j++)
            if(!check[j])return 0;
    }
    for(int i=1;i<=9;i+=3)
        for(int j=1;j<=9;j+=3)
        {
            Clear();
            for(int m=0;m<3;m++)
                for(int n=0;n<3;n++)
                    check[sudoku[i+m][j+n]]=1;
            for(int j=1;j<=9;j++)
                if(!check[j])return 0;
        }
    return 1;
}

int main()
{
    int ncase;cin >>ncase;
    for(int text=1;text<=ncase;text++)
    {
        Input();
        cout <<"Case " <<text <<":" <<endl;
        if(IsRight())
            cout <<"Yes!" <<endl;
        else cout <<"No!" <<endl;
    }
    return 0;
}