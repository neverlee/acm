#include<cstdio>
#include<queue>
using namespace std;
typedef unsigned char uchar;
//******************Array
uchar array[9];
void SetArray(int num){
    for(int i=0;i<9;++i){
        array[i]=num%9;
        num/=9;
    }
}
int GetArray(){
    int num=0;
    for(int i=8;i>=0;--i)num=num*9+array[i];
    return num;
}
int FindZero(){for(int i=0;i<9;++i)if(array[i]==0)return i;}
/////////////////////Hash
const int HashSize=1199999;
int key[HashSize];
short value[HashSize];
int FindOrAddKey(int num){
    int pos = num%HashSize;
    while(key[pos]!=0&&key[pos]!=num){
        ++pos;if(pos==HashSize)pos=0;
    }
    key[pos]=num;
    return pos;
}
/////////////////////////////////BFS
int start,end;
void Input(){
    for(int i=0;i<9;++i)scanf("%ld",array+i);
    start=GetArray();
    for(int i=0;i<9;++i)scanf("%ld",array+i);
    end=GetArray();
}
const uchar rChange[9][5]={
    {2,1,3},
    {3,0,2,4},
    {2,1,5},
    {3,0,4,6},
    {4,1,3,5,7},
    {3,2,4,8},
    {2,3,7},
    {3,4,6,8},
    {2,5,7}
};
short BFS(){
    queue<int> qfor, qrev;
    start=FindOrAddKey(start);
    value[start]=1;
    qfor.push(start);
    end=FindOrAddKey(end);
    value[end]=-1;
    qrev.push(end);
    int zero, inew;
    while(!qfor.empty()||!qrev.empty()){
    if(!qfor.empty()){
        SetArray(key[qfor.front()]);
        zero=FindZero();
        for(int i=1;i<=rChange[zero][0];++i){
            swap(array[zero], array[rChange[zero][i]]);
            inew=GetArray();
            inew=FindOrAddKey(inew);
            if(value[inew]<0){
                return value[qfor.front()]-value[inew];
            }else if(value[inew]==0){
                value[inew]=value[qfor.front()]+1;
                qfor.push(inew);
            }
            swap(array[zero], array[rChange[zero][i]]);
        }
        qfor.pop();
    }
    if(!qrev.empty()){
        SetArray(key[qrev.front()]);
        zero=FindZero();
        for(int i=1;i<=rChange[zero][0];++i){
            swap(array[zero], array[rChange[zero][i]]);
            inew=GetArray();
            inew=FindOrAddKey(inew);
            if(value[inew]>0){
                return value[inew]-value[qrev.front()];
            }else if(value[inew]==0){
                value[inew]=value[qrev.front()]-1;
                qrev.push(inew);
            }
            swap(array[zero], array[rChange[zero][i]]);
        }
        qrev.pop();
    }
    }
    return 0;
}
int main(){
    Input();
    if(start==end){
        printf("0");
        return 0;
    }
    printf("%d",BFS()-1);
    return 0;
}
