#include <iostream>
using namespace std;
int map[3][3],num;

int judge()
{
    for (int i=0; i<3; i++) {
        if (map[i][0]==map[i][1]&&map[i][1]==map[i][2])
            return map[i][0];
        if (map[0][i]==map[1][i]&&map[1][i]==map[2][i])
            return map[0][i];
        }
    if ((map[0][0]==map[1][1]&&map[1][1]==map[2][2])||
        (map[0][2]==map[1][1]&&map[1][1]==map[2][0]))
        return map[1][1];
    return 0;
}

int dfs(int num)
{
    int i,j,k=0,m,lab=0;
    m=judge();
    if (m||num==9)
        return m;
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)
            if (map[i][j]==0) {
                map[i][j]=2-num%2;
                k=dfs(num+1);
                map[i][j]=0;
                if (k==2-num%2)
                    return 2-num%2;
                else if (k==0)
                    lab=1;
            }
    if (lab)
        return 0;
    else return 1+num%2;
}

int main()
{
    int i,j,ans;
    char c;
    for (i=0,num=0; i<3; i++)
        for (j=0; j<3; j++) {
            cin >> c;
            if (c==\'X\') {
                map[i][j]=2;
                num++;
            }
            else if (c==\'O\') {
                map[i][j]=1;
                num++;
            }
            else map[i][j]=0;
        }
    ans=dfs(num);
    if (ans==2)
        cout << "X WILL WIN\n";
    else if (ans==1)
        cout << "O WILL WIN\n";
    else cout << "TIL\n";
    return 0;
}
