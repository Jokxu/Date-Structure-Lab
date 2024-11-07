//�㷨5.5 ��������������
#include<iostream>
#include<algorithm>
using namespace std;

//�������Ķ�������洢��ʾ
typedef struct BiTNode
{
	char data;
	BiTNode *lt, *rt;	
}BiTNode,*BiTree;

//���㷨5.3������������
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
	cout<<"�����뽨��������������У�\n";
	CreateBiTree(tree);
	cout<<"�������Ϊ��"<<Depth(tree)<<endl;
}
