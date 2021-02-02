#include <stdio.h>
#include <stdlib.h>
#define NULL 0
typedef struct node
{ 
	int data;
	int time;
	struct node* lchild;
	struct node* rchild;  
}Bitree;
typedef struct stack
{
	Bitree* ELEMENT[200];
	int top;
}sut;

Bitree* root;
sut sm;

void setnull()//初始化栈
{
	sm.top = 0;
}

void push(Bitree* temp)//入栈
{
	sm.ELEMENT[sm.top++] = temp;
}

Bitree* pop()//取栈顶并出栈顶
{
	return sm.ELEMENT[--sm.top];
}

int empty()//判断是否为空栈
{
	return sm.top == 0;
}

Bitree* creat()   
{
	Bitree* t;
	int a;


scanf("%d", &a);
	if (a== 00) t = NULL; 
	else {
		t = (Bitree*)malloc(sizeof(Bitree));
		t->data = a;                  
		t->lchild = creat();
		t->rchild = creat();
	}
	return t;
}
void qian(Bitree* t)//前
{
	Bitree* temp = t;
	while (temp != NULL || sm.top != 0)
	{
		while (temp != NULL)
		{
			printf("   %d", temp->data);
			push(temp);
			temp = temp->lchild;
		}
		if (sm.top != 0)
		{
			temp = pop();
			temp = temp->rchild;
		}
	}
	printf("\n");
}

void zhong(Bitree* t)//中序遍历非递归
{
	Bitree* temp = t;
	while (temp != NULL || sm.top != 0)
	{
		while (temp != NULL)
		{
			push(temp);
			temp = temp->lchild;
		}
		if (sm.top != 0)
		{
			temp = pop();
			printf("   %d", temp->data);
			temp = temp->rchild;
		}
	}
	printf("\n");
}


void hou(Bitree* root)//后续
{
	Bitree* temp = root;
	while (temp != NULL || sm.top != 0)
	{
		while (temp != NULL)
		{
			temp->time = 1;       
			push(temp);
			temp = temp->lchild;
		}
		if (sm.top != 0)
		{
			temp = pop();
			if (temp->time == 1)   
			{

				temp->time++;
				push(temp);
				temp = temp->rchild;
			}
			else
				if (temp->time == 2)
				{
					printf("   %d", temp->data);
					temp = NULL;
				}
		}
	}
	printf("\n");
}
int main()
{
	Bitree* gen;
	setnull();
	printf("请按顺序输入数00代表子节点为空\n");//1 2 3 0 0 4 0 0 5 6 0 0 7 0 0
	gen = creat();//创建二叉树
	printf("非递归前序遍历:\n");
	qian(gen);
	printf("非递归中序遍历:\n");
	zhong(gen);
	printf("非递归后序遍历:\n");
	hou(gen);
	return 0;
}
