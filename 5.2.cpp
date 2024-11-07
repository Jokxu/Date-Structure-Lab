//�㷨5.2 ��������ķǵݹ��㷨
#include<iostream>
using namespace std;

//�������Ķ�������洢��ʾ
typedef struct BiNode
{				
	char data;
	BiNode *lt, *rt;
}BiNode,*BiTree;

//��ջ�Ķ���
typedef struct StackNode
{
	BiNode data;
	StackNode *next;
}StackNode,*LinkStack;

//���㷨5.3 ���������˳������������
void CreateBiTree(BiTree &T)
{	
	//�������������������н���ֵ��һ���ַ������������������ʾ�Ķ�����T
	char x;
	cin >> x;
	if(x == '#')
	{
		T = NULL;
	}
	else
	{
		T = new BiNode;
		T->data = x;
		CreateBiTree(T->lt);
		CreateBiTree(T->rt);
	}
}									//CreateBiTree

void InitStack(LinkStack &S)
{
	//����һ����ջS��ջ��ָ���ÿ�
	S=NULL;
}

bool StackEmpty(LinkStack S)
{
	if(!S)
		return true;
	return false;
}

void Push(LinkStack &S,BiTree e)
{
	//��ջ������Ԫ��*e
	StackNode *p=new StackNode;
	p->data=*e;
	p->next=S;
	S=p;
}

void Pop(LinkStack &S,BiTree e)
{
	if(S!=NULL)//ԭ����д����if(S==NULL)return ERROR;
	{	
		*e=S->data;
		StackNode *p=S;
		S=S->next;
		delete p;
	}
} 
  
void InOrderTraverse1(BiTree T)
{ 
	// �������������T�ķǵݹ��㷨
	LinkStack S;
	InitStack(S);
	BiTree p = T;
	BiTree q = new BiNode;
	while(p || !StackEmpty(S))
	{
		if(p)
		{
			Push(S, p);
			p = p->lt;
		}
		else
		{
			Pop(S, q);
			cout << q->data << ' ';
			p = q->rt;
		}
	}
}									// InOrderTraverse

int main()
{
	BiTree tree;
	cout<<"�����뽨��������������У�\n";
	CreateBiTree(tree);
	cout<<"��������Ľ��Ϊ��\n";
	InOrderTraverse1(tree);
	cout<<endl;
}
