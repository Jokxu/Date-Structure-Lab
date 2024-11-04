#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#define MAXQSIZE 100//���п��ܴﵽ����󳤶�
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;

typedef struct {
	char name[20]; //����
	char sex; //�Ա�'F'��ʾŮ�ԣ�'M'��ʾ����
} Person;

//- - - - - ���е�˳��洢�ṹ- - - - - 
typedef struct {
	Person *base; //����������Ԫ������ΪPerson
	int front; //ͷָ��
	int rear; //βָ��
} SqQueue;

SqQueue Mdancers, Fdancers; //�ֱ�����ʿ��Ůʿ����߶���

int InitQueue(SqQueue &Q) {//����һ���ն���Q
	Q.base = new Person[MAXQSIZE];
	Q.front = Q.rear = 0;
	return 1;
}

int EnQueue(SqQueue &Q, Person e) {//����Ԫ��eΪQ���µĶ�βԪ��
	int t = Q.rear;
	memcpy(Q.base[t].name, e.name, sizeof(Q.base[t].name));
	Q.base[t].sex = e.sex;
	Q.rear += 1;
	return 1;
}

int QueueEmpty(SqQueue &Q) {
	if (Q.front == Q.rear) //�ӿ�
		return OK;
	else
		return ERROR;
}

int DeQueue(SqQueue &Q, Person &e)//ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
{
	int t = Q.front;
	memcpy(e.name, Q.base[t].name, sizeof(e.name));
	e.sex = Q.base[t].sex;
	Q.front ++ ;
	return 1;
}

Person GetHead(SqQueue Q) {//����Q�Ķ�ͷԪ�أ����޸Ķ�ͷָ��
	int t = Q.front;
	return Q.base[t];
}

Person dancer[MAXQSIZE];
//�㷨3.23���������
void DancePartner(Person dancer[], int num) {//�ṹ����dancer�д���������Ů��num�������������
	for(int i = 0; i < num; i ++)
	{
		Person t = dancer[i];
		if(dancer[i].sex == 'F')
		{
			EnQueue(Fdancers, dancer[i]);
		}
		else
		{
			EnQueue(Mdancers, dancer[i]);
		}
	}

	while(!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers))
	{
		Person F, M; 
		DeQueue(Fdancers, F);
		DeQueue(Mdancers, M);
		cout << F.name << "   " << M.name << endl;
	}
}

int main() {
	int i = 0;
	fstream file;
	file.open("DancePartner.txt");
	if (!file) {
		cout << "����δ�ҵ��ļ���\n\n" << endl;
		exit( ERROR);
	}
	while (!file.eof()) {
		file >> dancer[i].name >> dancer[i].sex;
		i++;
	}
	
	InitQueue(Mdancers);
	InitQueue(Fdancers);
	DancePartner(dancer, i + 1);
	
	return 0;
}
