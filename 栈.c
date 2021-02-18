#include<stdio.h>  

#include<stdlib.h>
struct node {
	int a;
	struct node* next;
};
struct stack
{
	struct node* stacktop;//栈顶标 记

	int size;//栈中元素个数
};
//创建节点
struct node* createnode(int date) {
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->a = date;
	newnode->next = NULL;
	return newnode;
}
//创建栈就是创建一个struct stack的变量
struct stack* createstack() {
	//创建过程就是初始化过程
	struct stack* mystack = (struct stack*)malloc(sizeof(struct stack));
	mystack->stacktop = NULL;
	mystack->size = 0;
	return mystack;
}
void push(struct stack* mystack, int date) {
	//插入节点创建出来
	struct node* newnode = createnode(date);
	//入栈操作就是链表的表头插入
	newnode->next = mystack->stacktop;
	mystack->stacktop = newnode;
	mystack->size++;
}
//获取栈顶元素
int top(struct stack* mystack)
{
	//防御编程
	if (mystack->size == 0)
	{
		printf("无法获取\n");
		return mystack->size;
	}
	return mystack->stacktop->a;
}
//出栈
void pop(struct stack* mystack)
{
	if (mystack->size == 0)
	{
		printf("无法出栈\n");
		return mystack->size;
	}
	else {
		struct node* nextnode = mystack->stacktop->next;
		free(mystack->stacktop);
		mystack->stacktop = nextnode;
		mystack->size--;
	}
}
//万金油函数
int empty(struct stack* mystack)
{
	if (mystack->size == 0)
		return 0;
	return 1;
}
int main(void)
{
	struct stack* mystack = createstack();
	push(mystack, 1);
	push(mystack, 2);
	push(mystack, 3);
	printf("元素入栈顺序为: 1 2 3 \n");
	printf("元素出栈顺序为:");
	while (empty(mystack))
	{
		printf("%  d", top(mystack));
		pop(mystack);
	}

	system("pause");
}
