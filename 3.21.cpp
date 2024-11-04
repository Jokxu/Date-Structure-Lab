/***链栈实现括号匹配***/

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

//算法3.21　括号的匹配
Status Matching() {//检验表达式中所含括号是否正确匹配，如果匹配，则返回true，否则返回false
	//表达式以“#”结束
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
	cout << "请输入待匹配的表达式，以“#”结束：" << endl;
	int flag = (int) Matching();
	if (flag)
		cout << "括号匹配成功！" << endl;
	else
		cout << "括号匹配失败！" << endl;
	return 0;
}
