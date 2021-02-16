#include <stdio.h>
#include <stdlib.h>
typedef struct QNode {
	int data;
	struct QNode *next;
}QNode, *LinkQueue;
LinkQueue rear, front;//尾指针和头结点
int t=0;//统计队列长度
//入队列
int EnQueue(int e){
	t++;
	LinkQueue p;
	p = (LinkQueue)malloc(sizeof(QNode));
	p->data = e;
	rear->next = p;
	rear = p;
	rear->next = front;
}
int Create(int n)//创建
{
	LinkQueue p;
	int e;
	front = (LinkQueue)malloc(sizeof(QNode));
	rear = front;
	front->next = rear;
	rear->next = front;
	rear->data = front->data = NULL;
	printf("输入队列元素： ");
	while (n--)
	{
		scanf_s("%d", &e);
		EnQueue(e);
	}

}
int Show()//显示
{
	LinkQueue p;
	printf("当前队列元素为： ");
	p = front->next;
	if (front == rear)//队列为空时
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
//出队列
int DeQueue()
{	int e;
	t--;
	LinkQueue p;
	p = front->next;
	e = p->data;
	if (front == rear)//队列为空时
	{
		printf("队列为空\n");
		return 0;
	}
	front->next = front->next->next;
	if (front->next == front){
		rear = front;
	}
	free(p);
	printf("出队列元素为： %d\n", e);
}
//改
int change(int r){
	int i = 0,s;
	LinkQueue p;
	p = front->next;
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
	int select, e;
	while (1)
	{
		printf("1.创建队列\n2.入队列\n3.出队列\n4.修改队列\n5.退出\n");
		printf("选择操作： ");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("输入队列的长度： ");
			scanf("%d", &e);
			Create(e);
			Show();
			system("pause");
			break;
		case 2:
			printf("输入入队列元素： ");
			scanf("%d", &e);
			EnQueue(e);
			Show();
			system("pause");
			break;
		case 3:
			DeQueue();
			Show();
			system("pause");
			break;
		case 4:
			printf("输入要修改的数据：");
			scanf("%d", &e);
			change(e);
			Show();
			system("pause");
			break;
		case 5:
			return 0;
		default:
			printf("输入错误\n");
			break;
		}
		system("cls");
	}
	return 0;
}
