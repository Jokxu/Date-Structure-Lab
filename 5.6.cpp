//算法5.6 统计二叉树中结点的个数
#include<iostream>
using namespace std;

//二叉树的二叉链表存储表示
typedef struct BiTNode
{
	char data;
	BiNode *lt, *rt;
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

int NodeCount(BiTree T)
{
	if(!T)
	{
		return 0;
	}
	else
	{
		return NodeCount(T->lt) + NodeCount(T->rt) + 1;
	}
} 

int main()
{
	BiTree tree;
	cout<<"请输入建立二叉链表的序列：\n";
	CreateBiTree(tree);
	cout<<"结点个数为："<<NodeCount(tree)<<endl;

}
