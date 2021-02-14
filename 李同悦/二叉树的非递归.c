#include <stdio.h>
#include <stdlib.h>
#define NULL 0
#define M 100 
typedef struct node
{
	int data;
	int cishu;
	struct node* lchild;
	struct node* rchild; 
}bitree;
typedef struct stack
{
	bitree* elements[M];
	int top;
}seqstack;
bitree* root;
seqstack s;
void setnull()
{
	s.top = 0;
}
void push(bitree* temp)
{
	s.elements[s.top++] = temp;
}

bitree* pop()
{
	return s.elements[--s.top];
}
int empty()//判断空栈
{
	return s.top == 0;
}
bitree* creat()
{
	bitree* t;
	int x;
	scanf("%d", &x);
	if (x == 0) t = NULL;
	else {
		t = (bitree*)malloc(sizeof(bitree));
		t->data = x;
		t->lchild = creat();
		t->rchild = creat();
	}
	return t;
}
void preorder(bitree* t)
{
	bitree* temp = t;
	while (temp != NULL || s.top != 0)
	{
		while (temp != NULL)
		{
			printf("%4d", temp->data);
			push(temp);
			temp = temp->lchild;
		}
		if (s.top != 0)
		{
			temp = pop();
			temp = temp->rchild;
		}
	}
	printf("\n");
}

void inorder(bitree* t)
{
	bitree* temp = t;
	while (temp != NULL || s.top != 0)
	{
		while (temp != NULL)
		{
			push(temp);
			temp = temp->lchild;
		}
		if (s.top != 0)
		{
			temp = pop();
			printf("%4d", temp->data);
			temp = temp->rchild;
		}
	}
	printf("\n");
}


void laorder(bitree* root)
{
	bitree* temp = root;
	while (temp != NULL || s.top != 0)
	{
		while (temp != NULL)
		{
			temp->cishu = 1;
			push(temp);
			temp = temp->lchild;
		}
		if (s.top != 0)
		{
			temp = pop();
			if (temp->cishu == 1)
			{
				temp->cishu++;
				push(temp);
				temp = temp->rchild;
			}
			else
				if (temp->cishu == 2)
				{
					printf("%4d", temp->data);
					temp = NULL;
				}
		}
	}
	printf("\n");
}
int main()
{
	bitree* root;
	setnull();
	root = creat();
	printf("前序遍历:\n");
	preorder(root);
	printf("中序遍历:\n");
	inorder(root);
	printf("后序遍历:\n");
	laorder(root);
	return 0;
}
