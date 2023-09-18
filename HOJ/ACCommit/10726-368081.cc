#include<cstdio>
#include<cstring>
#include<cstdlib>

short num,sk;
short id,s1,s2;char name[40];
class Student
{
protected:
    short scor1,scor2;
    char name[40];
public:
    short rank,ID;
    short comscor;
    void Set(short id,char *n,short sd1,short sd2);
    void Display();
}student[1000],*psd[1000];
void Student::Set(short id,char *n,short sd1,short sd2)
{
    ID=id;scor1=sd1;scor2=sd2;
    strcpy(name,n);
    comscor=(sd1*sk+sd2*(100-sk));
}
void Student::Display()
{printf("%d\\%s\\%d\\%d\\%.3lf\\%d\n",ID,name,scor1,scor2,comscor/100.0,rank);}

int compare(const void *a,const void *b)
{return (*((Student**)b))->comscor-(*((Student**)a))->comscor;}
int cmp(const void*a,const void *b)
{return (*((Student**)a))->ID-(*((Student**)b))->ID;}

void Init()
{
    for(short i=0;i<num;i++)
    {
        scanf("%d %s %d %d",&id,name,&s1,&s2);
        student[i].Set(id,name,s1,s2);
        psd[i]=&student[i];
    }
    qsort(psd,num,sizeof(Student*),compare);
    for(short i=0;i<num;i++)
        psd[i]->rank=i+1;
    for(int i=1;i<num;i++)
        if(psd[i-1]->comscor==psd[i]->comscor)
            psd[i]->rank=psd[i-1]->rank;
    qsort(psd,num,sizeof(Student*),cmp);
    printf("ID\\NAME\\SCOR1\\SCOR2\\COMSCOR\\RANK\n");
    for(int i=0;i<num;i++)
        psd[i]->Display();
}

int main()
{
    scanf("%d%d",&num,&sk);
    Init();
    return 0;
}