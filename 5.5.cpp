//算法5.5 计算二叉树的深度
#include<iostream>
#include<algorithm>
using namespace std;

//二叉树的二叉链表存储表示
typedef struct BiTNode
{
	char data;
	BiTNode *lt, *rt;	
}BiTNode,*BiTree;

//用算法5.3建立二叉链表
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
		T = new BiTNode;
		T->data = x;
		CreateBiTree(T->lt);
		CreateBiTree(T->rt);
	}
}									//CreateBiTree

int Depth(BiTree T)
{
	if(!T)
	{
		return 0;
	}
	else
	{
		int m = Depth(T->lt);
		int n = Depth(T->rt);
		return max(m, n) + 1;
	}
}

int main()
{
	BiTree tree;
	cout<<"请输入建立二叉链表的序列：\n";
	CreateBiTree(tree);
	cout<<"数的深度为："<<Depth(tree)<<endl;
}
