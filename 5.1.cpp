//算法5.1 中序遍历的递归算法
#include<iostream>
using namespace std;
typedef struct BiTNode
{	//二叉链表定义
	char data;
	BiTNode *lt, *rt;
}BiTNode,*BiTree;

//用算法5.3 先序遍历的顺序建立二叉链表
void CreateBiTree(BiTree &T)
{	
	char x;
	cin >> x;
	if(x == '#')
	{
		T = NULL;
	}
	else
	{
		T = new BiTNode;
		T->data = x;
		CreateBiTree(T->lt);
		CreateBiTree(T->rt);
	}
}									//CreateBiTree

void InOrderTraverse(BiTree T)
{  
	//中序遍历二叉树T的递归算法
	if(!T)
	{
		return ;
	}
	else
	{
		InOrderTraverse(T->lt);
		cout << T->data << ' ';
		InOrderTraverse(T->rt);
	}
}

int main()
{
	BiTree tree;
	cout<<"请输入建立二叉链表的序列：\n";
	CreateBiTree(tree);
	cout<<"中序遍历的结果为：\n";
	InOrderTraverse(tree);
	cout<<endl;
}
