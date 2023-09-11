//11034-Customer support.cpp
#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
int total, num, question, correct, explain;
map<int,int> record;
int main(){
    scanf("%ld",&num);
    total=0;
    while(num--){
        scanf("%ld%ld%ld",&question,&correct,&explain);
        if(record.find(question)==record.end()){
            record[question]=correct;
        }else if(correct){
            total+=record[question]*10;
            record[question]+=1;
        }
        if(correct&&explain)total+=40;
        else if(correct)total+=20;
        else total+=10;
    }
    printf("%ld",total);
	return 0;
}
