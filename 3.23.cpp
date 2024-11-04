#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#define MAXQSIZE 100//队列可能达到的最大长度
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;

typedef struct {
	char name[20]; //姓名
	char sex; //性别，'F'表示女性，'M'表示男性
} Person;

//- - - - - 队列的顺序存储结构- - - - - 
typedef struct {
	Person *base; //队列中数据元素类型为Person
	int front; //头指针
	int rear; //尾指针
} SqQueue;

SqQueue Mdancers, Fdancers; //分别存放男士和女士入队者队列

int InitQueue(SqQueue &Q) {//构造一个空队列Q
	Q.base = new Person[MAXQSIZE];
	Q.front = Q.rear = 0;
	return 1;
}

int EnQueue(SqQueue &Q, Person e) {//插入元素e为Q的新的队尾元素
	int t = Q.rear;
	memcpy(Q.base[t].name, e.name, sizeof(Q.base[t].name));
	Q.base[t].sex = e.sex;
	Q.rear += 1;
	return 1;
}

int QueueEmpty(SqQueue &Q) {
	if (Q.front == Q.rear) //队空
		return OK;
	else
		return ERROR;
}

int DeQueue(SqQueue &Q, Person &e)//删除Q的队头元素，用e返回其值
{
	int t = Q.front;
	memcpy(e.name, Q.base[t].name, sizeof(e.name));
	e.sex = Q.base[t].sex;
	Q.front ++ ;
	return 1;
}

Person GetHead(SqQueue Q) {//返回Q的队头元素，不修改队头指针
	int t = Q.front;
	return Q.base[t];
}

Person dancer[MAXQSIZE];
//算法3.23　舞伴问题
void DancePartner(Person dancer[], int num) {//结构数组dancer中存放跳舞的男女，num是跳舞的人数。
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
		cout << "错误！未找到文件！\n\n" << endl;
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
