//�㷨5.1 ��������ĵݹ��㷨
#include<iostream>
using namespace std;
typedef struct BiTNode
{	//����������
	char data;
	BiTNode *lt, *rt;
}BiTNode,*BiTree;

//���㷨5.3 ���������˳������������
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
	//�������������T�ĵݹ��㷨
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
	cout<<"�����뽨��������������У�\n";
	CreateBiTree(tree);
	cout<<"��������Ľ��Ϊ��\n";
	InOrderTraverse(tree);
	cout<<endl;
}
