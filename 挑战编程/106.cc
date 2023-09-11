#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int mem[1000], i;
int Command(){
	int type, ds, nsa, total=0, rsg[10]={0}, pos=0;
	while(++total){
		type=mem[pos]/100;
		ds=mem[pos]%100/10;
		nsa=mem[pos]%10;
		pos=(pos+1)%1000;
		switch(type){
		case 0:if(rsg[nsa])pos=rsg[ds];break;
		case 1:return total;//退出
		case 2:rsg[ds]=nsa;break;
		case 3:rsg[ds]=(rsg[ds]+nsa)%1000;break;
		case 4:rsg[ds]=(rsg[ds]*nsa)%1000;break;
		case 5:rsg[ds]=rsg[nsa];break;
		case 6:rsg[ds]=(rsg[ds]+rsg[nsa])%1000;break;
		case 7:rsg[ds]=(rsg[ds]*rsg[nsa])%1000;break;
		case 8:rsg[ds]=mem[rsg[nsa]];break;
		case 9:mem[rsg[nsa]]=rsg[ds];break;
		}
	}
}
void main(){
	int count, len;
	char str[10]={0};
	scanf("%ld\n",&count);
	while(count--){
		len=0;
		for(;gets(str);++len){
			if(!isdigit(str[0]))break;
			sscanf(str,"%ld",mem+len);
		}
		printf("%ld\n", Command());
		if(count)printf("\n");
	}
}