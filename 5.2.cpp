//算法5.2 中序遍历的非递归算法
#include<iostream>
using namespace std;

//二叉树的二叉链表存储表示
typedef struct BiNode
{				
	char data;
	BiNode *lt, *rt;
}BiNode,*BiTree;

//链栈的定义
typedef struct StackNode
{
	BiNode data;
	StackNode *next;
}StackNode,*LinkStack;

//用算法5.3 先序遍历的顺序建立二叉链表
void CreateBiTree(BiTree &T)
{	
	//按先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树T
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
	//构造一个空栈S，栈顶指针置空
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
	//在栈顶插入元素*e
	StackNode *p=new StackNode;
	p->data=*e;
	p->next=S;
	S=p;
}

void Pop(LinkStack &S,BiTree e)
{
	if(S!=NULL)//原书上写的是if(S==NULL)return ERROR;
	{	
		*e=S->data;
		StackNode *p=S;
		S=S->next;
		delete p;
	}
} 
  
void InOrderTraverse1(BiTree T)
{ 
	// 中序遍历二叉树T的非递归算法
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
	cout<<"请输入建立二叉链表的序列：\n";
	CreateBiTree(tree);
	cout<<"中序遍历的结果为：\n";
	InOrderTraverse1(tree);
	cout<<endl;
}
