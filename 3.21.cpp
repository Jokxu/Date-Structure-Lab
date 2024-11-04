/***��ջʵ������ƥ��***/

#include<iostream>
#include<cstring>
#include<string>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef char SElemType;
typedef int Status;
typedef struct SNode {
	int data;
	struct SNode *next;
} SNode, *LinkStack;

Status InitStack(LinkStack &S) {
	S =  NULL;
	return OK;
}
bool StackEmpty(LinkStack S) {
	if (!S)
		return true;
	return false;
}
Status Push(LinkStack &S, SElemType e) {
	LinkStack top = new SNode;
	top->data = e;
	top->next = S;
	S = top;
	return 1;
}
Status Pop(LinkStack &S, SElemType &e) {
	LinkStack top = S;
	S = top->next;
	delete top;
	return 1;
}
Status GetTop(LinkStack &S) {
	return 1;
}

//�㷨3.21�����ŵ�ƥ��
Status Matching() {//������ʽ�����������Ƿ���ȷƥ�䣬���ƥ�䣬�򷵻�true�����򷵻�false
	//���ʽ�ԡ�#������
	LinkStack S;
	InitStack(S);
	string s;
	cin >> s;
	for(char c : s)
	{
		if(c == '(')
		{
			Push(S, c);
		}
		else
		{
			if(StackEmpty(S))
			{
				return 0;
			}
			char e;
			Pop(S, e);
		}
	}
	if(StackEmpty(S))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main() {
	LinkStack S;
	cout << "�������ƥ��ı��ʽ���ԡ�#��������" << endl;
	int flag = (int) Matching();
	if (flag)
		cout << "����ƥ��ɹ���" << endl;
	else
		cout << "����ƥ��ʧ�ܣ�" << endl;
	return 0;
}
