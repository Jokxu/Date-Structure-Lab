//�㷨5.6 ͳ�ƶ������н��ĸ���
#include<iostream>
using namespace std;

//�������Ķ�������洢��ʾ
typedef struct BiTNode
{
	char data;
	BiNode *lt, *rt;
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
	cout<<"�����뽨��������������У�\n";
	CreateBiTree(tree);
	cout<<"������Ϊ��"<<NodeCount(tree)<<endl;

}
