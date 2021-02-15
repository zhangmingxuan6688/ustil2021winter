#include <stdio.h>
#include <stdlib.h>

typedef struct QNode {
	int data;
	struct QNode *next;
}QNode, *LinkQueue;

LinkQueue rear, head;//尾指针和头结点
int t=0;//统计队列长度
int EnQueue(int e)//入队列 
{
	t++;
	LinkQueue p;
	p = (LinkQueue)malloc(sizeof(QNode));
	p->data = e;
	rear->next = p;
	rear = p;
	rear->next = head;
}

int Create(int n)//创建 
{
	LinkQueue p;
	int e;
	head = (LinkQueue)malloc(sizeof(QNode));
	rear = head;
	head->next = rear;
	rear->next = head;
	rear->data = head->data = NULL;
	printf("输入队列元素： ");
	while (n--)
	{
		scanf("%d", &e);
		EnQueue(e);
	}

}

int Show()//显示 
{
	LinkQueue p;
	printf("当前队列元素为： ");
	p = head->next;
	if (head == rear)//队列为空时
	{
		printf("队列为空\n");
		return 0;
	}
	for (; p != rear; p = p->next)
	{
		printf("%d ", p->data);
	}
	printf("%d\n", p->data);
}

int DeQueue()//出队列  
{
	int e;
	t--;
	LinkQueue p;
	p = head->next;
	e = p->data;
	if (head == rear)//队列为空时
	{
		printf("队列为空\n");
		return 0;
	}
	head->next = head->next->next;
	if (head->next == head)
	{
		rear = head;
	}
	free(p);
	printf("出队列元素为： %d\n", e);
}

int change(int r)//修改
{
	int i = 0,s;
	LinkQueue p;
	p = head->next;
	printf("输入改后的数");
	scanf("%d", &s);
	for (i = 0; i < t; i++)
	{
		if (p->next->data == r)
		{
			p->next->data = s;
		}
	}
}

int main()
{
	int select, e, n,r;
	printf("1.创建队列\t2.入队列\t3.出队列\t4.修改队列\t5.退出\n");
	while (1)
	{
		printf("选择操作： ");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("输入队列的长度： ");
			scanf("%d", &n);
			Create(n);
			Show();
			break;
		case 2:
			printf("输入入队列元素： ");
			scanf("%d", &e);
			EnQueue(e);
			Show();
			break;
		case 3:
			DeQueue();
			Show();
			break;
		case 4:
			printf("输入要修改的数据：");
			scanf("%d", &r);
			change(r);
			Show();
			break;
		case 5:
			return 0;
		default:
			printf("输入错误\n");
			break;
		}
	}
	return 0;
}
