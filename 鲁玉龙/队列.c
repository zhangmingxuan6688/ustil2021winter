#include<stdio.h>
#include<stdlib.h>
struct node {
	int a;
	struct node* next;
};
struct queque {
	struct node* front;
	struct node* tail;
	int size;
};
//创建节点
struct node* createnode(int a)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->next = NULL;
	newnode->a = a;
	return newnode;
}
//创建队
struct queque* createqueque() {
	struct queque* myqueque = (struct queque*)malloc(sizeof(struct queque));
	myqueque->front = NULL;
	myqueque->tail = NULL;
	myqueque->size = 0;
	return myqueque;
}
//入队
void push(struct queque* myqueque, int date)
{//尾插入
	struct node* newnode = createnode(date);
	if (myqueque->size == 0)
	{
		myqueque->front = myqueque->tail = newnode;
	}
	else
	{
		myqueque->tail->next = newnode;
		myqueque->tail= newnode;
	}
	myqueque->size++;
}
//不同类型结构体指针相等后果
void pop(struct queque* myqueque) {

	if (myqueque->size == 0) {
		printf("队为空");
		system("pause");
	}
	else {
		struct node* nextnode = myqueque->front->next;
		free(myqueque->front);
		myqueque->front = nextnode;
		myqueque->size--;

	}
}
//获取队头元素
int front(struct queque* myqueque)
{
	if (myqueque->size == 0) {
		printf("队为空无法获取");
		system("pause");
		return myqueque->size;
	}
	return myqueque->front->a;
}
//判断队是不是空的
int  empty(struct queque* myqueque) {
   if (myqueque->size == 0)
    return 0;
	return 1;
}
int main(void)
{   struct queque* myqueque = createqueque();
	push(myqueque, 1);
	push(myqueque, 2);
	push(myqueque, 3);
		printf("入队顺序为  1 2 3\n");
		printf("出队顺序为；")	;
	while (empty(myqueque)) {
		printf("%d ", front(myqueque));

			pop(myqueque);
		
		
		} 
	}
