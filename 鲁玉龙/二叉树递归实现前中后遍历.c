#include <stdio.h>
#include <stdlib.h>	
//1.结构体描述
typedef struct Node
{
	char data;				//数据
	struct Node* LChild;	//左子树指针
	struct Node* RChild;	//右子树指针
}TREE, * LPTREE;
//2.呆比创建法
//如何把数据变成一个节点
LPTREE createNode(char data)
{
	LPTREE newNode = (LPTREE)malloc(sizeof(TREE));
	newNode->data = data;
	newNode->LChild = NULL;
	newNode->RChild = NULL;
	return newNode;
}
void insertNode(LPTREE parent, LPTREE LChild, LPTREE RChild)
{
	parent->LChild = LChild;
	parent->RChild = RChild;
}

//3.递归创建法
void createTree(LPTREE* T)
{
	char userKey = '\0';
	scanf_s("%c", &userKey, 1);
	if (userKey == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (LPTREE)malloc(sizeof(TREE));
		(*T)->data = userKey;
		createTree(&(*T)->LChild);
		createTree(&(*T)->RChild);
	}
}
//递归遍历
//前序递归
void preOrder(LPTREE root)
{
	//根左右
	if (root != NULL)
	{
		printf("%c\t", root->data);
		preOrder(root->LChild);
		preOrder(root->RChild);
	}
}
//递归中序遍历
void midOrder(LPTREE root)
{
	if (root != NULL)
	{
		midOrder(root->LChild);
		printf("%c\t", root->data);
		midOrder(root->RChild);
	}
}
//后序递归遍历
void lastOrder(LPTREE root)
{
	if (root != NULL)
	{
		lastOrder(root->LChild);
		lastOrder(root->RChild);
		printf("%c\t", root->data);
	}
}
void  modify(int a)
{
	a = 1001;
}
int g_num = 10;
void modifyPoint(int* p)
{
	p = &g_num;
}

int main()
{
	LPTREE A = createNode('A');
	LPTREE B = createNode('B');
	LPTREE C = createNode('C');
	LPTREE D = createNode('D');
	LPTREE E = createNode('E');
	LPTREE F = createNode('F');
	LPTREE G = createNode('G');
	insertNode(A, B, C);
	insertNode(B, D, NULL);
	insertNode(D, NULL, G);
	insertNode(C, E, F);
	printf("输入数据为A B C D E F G\n");
	printf("                        递归前序遍历结果为\n");
	preOrder(A);
    printf("\n");
	printf("                        递归中序遍历结果为\n");
	midOrder(A);
	printf("\n");
	printf("                        递归后序遍历结果为\n");
	lastOrder(A);
	printf("\n");
	system("pause");		//防止闪屏
	return 0;
}
