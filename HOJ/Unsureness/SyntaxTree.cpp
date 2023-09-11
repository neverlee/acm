#include<cstdio>
#include<io.h>
#include<list>
#include<ctype.h>
using namespace std;
class Source{
protected:
	char *code;
	char *position;
public:
	int length;
	int line;
	Source(){
		code=position=NULL;
		length=0;line=1;
	}
	void Reset(){position=code;line=1;}
	bool Read(char *file){
		//ԭ����fread���ļ������ֶ��ļ���������Ҫ�����⡣size�õ��Ĵ�С����ʵ�ʲ����
		FILE *fp=fopen(file, "r");
		if(fp==NULL)return false;//���ļ�ʧ��
		int size = filelength(fileno(fp));
		code=new char[size+1];
		position=code;
		while(fgets(position, size, fp)){
			while(*position)++position;
		}
		length=position-code;
		position=code;
		fclose(fp);
		//puts(code);printf("%ld\n",length);
		return true;//��ȡ�ɹ�
	}
	char operator[](int i){return *(position+i);}
	void Go(int i){position+=i;}
	bool StartWith(char *str){
		for(int i=0;str[i];++i)
			if(str[i]!=position[i])return false;
		return true;
	}
	bool IsEmpty(int i=0){
		return *(position+i)==' '||(*(position+i)==10)||(*(position+i)=='\t');
	}
	char GoEmpty(){
		char *p=position;
		while(IsEmpty()){
			if(*position=='\n')++line;
			++position;
		}
		if(*position==0)return -1;
		if(position!=p)return 1;
		else return 0;
	}
	~Source(){if(code)delete[]code;}
};
//*****************************************
const char ERROR = -1;
const char SUCCESS = 1;
class Code;//����
class Program;//����
class States;//��䴮
class IfState;//IF���
class WhileState;//while���
class AssignState;//��ֵ���
class Express;//���ʽ
class Item;//��
class Factor;//����
typedef union{
	char *id;
	int num;
	Express *exp;
}Element;

class Code{
public:
	virtual char Build(Source &src)=0;//��������
	//virtual void Display(ostream out);//�������
};
class IfState:public Code{
	virtual char Build(Source &src);
};
class WhileState:public Code{
	virtual char Build(Source &src);
};
class AssignState:public Code{
public:
	char *id;
	Express *exp;
	virtual char Build(Source &src);
};
class States:public Code{
protected:
	list<Code*> states;
public:
	int IsID(Source &src){//�õ�ID���ȣ�������Ϊ0
		if(isalpha(src[0])){
			int i=1;
			while(isalpha(src[i])||isdigit(src[i]))++i;
			return i;
		}
		return 0;
	}
    virtual char Build(Source &src){
		if(src.GoEmpty()==-1)return ERROR;
		int len;
		while(1){
			if(src.StartWith("if")&&src.IsEmpty(2)){//�����if���
				continue;
			}else if(src.StartWith("do")&&src.IsEmpty(2)){//�����do.while
				continue;
			}else if(src.StartWith("end")
					&&(src.IsEmpty(3)||src[3]=='#')){//����ǽ���
				return SUCCESS;
			}else if(len=IsID(src)){//����Ǳ�����
				src.Go(len);src.GoEmpty();
				if(src.StartWith(":=")){
					
				}
			}else return ERROR;
		}
	};
};

class Pragram:Code{
public:
	States states;
	virtual char Build(Source &src){
		if(src.StartWith("begin")&&src.IsEmpty(5)){
			src.Go(5);
		}else return ERROR;
		//������䴮
		char red=states.Build(src);
		if(red!=SUCCESS)return ERROR;
		//�����
		if(src.StartWith("end")){
			src.Go(3);
			//�����û#���ļ�����
			if(src.GoEmpty()!=-1
					&&src.StartWith("#")
					&&(src.Go(1),src.GoEmpty()==-1) )
				return SUCCESS;
			else return ERROR;
		}
		return ERROR;
	}
};

int main(){
    Source src;
    src.Read("E:\\ACMIn.txt");
    Pragram aprg;
    printf("%ld\n", aprg.Build(src));
	return 0;
}
