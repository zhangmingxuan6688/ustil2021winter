/*
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct Queue {
	int size;
	struct node* front;  //指向队头
	struct node* rear;   //指向队尾
};

//初始化
struct Queue* initqueue() {
	struct Queue* queue = (struct Quere*)malloc(sizeof(struct Queue));
	queue->size = 0;
	queue->front = (struct node*)malloc(sizeof(struct node));
	queue->front->data = -1;
	queue->front->next = NULL;
	queue->rear = queue->front;


	return queue;
}

//入栈
void enqueue(struct Queue*q,int data){
	
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	q->rear->next = newnode;
	q->rear = newnode;
	q->size++;
}

//出栈
void dequeue(struct Queue*q) {
	if (empty(q)) {
		
		return;
	}
	else if(q->size==1){
		struct node* newnode = q->front->next;
		q->front->next = newnode->next;
		free(newnode);
		q->rear = q -> front;
		q->size--;
	}
	else {
		struct node* newnode = q->front->next;
		q->front->next = newnode->next;
		free(newnode);
		q->size--;
	}
	
	
}

int empty(struct Queue* q) {
	 return q->size == 0 ? 1 :0;
}

int main() {

	struct Queue* q = initqueue();
	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	printf("1");
	return 0;
}
*/

#include<stdio.h>
#include<stdlib.h>


struct node {
	int data;
	struct node* next;
};


struct node* createnode(int data) {
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}


struct queue {
	struct node* frontnode;
	struct node* tailnode;
	int size;
};


//创建队列
struct queue* createqueue() {
	struct queue* myqueue = (struct queue*)malloc(sizeof(struct queue));
	myqueue->frontnode = myqueue->tailnode = NULL;
	myqueue->size = 0;
	return myqueue;
}


//入队
void push(struct queue* myqueue, int data) {
	struct node* newnode = createnode(data);
	if (myqueue->size == 0) {
		myqueue->frontnode = myqueue->tailnode = newnode;
	}
	else{
		myqueue->tailnode->next = newnode;
		myqueue->tailnode = newnode;

	}
	myqueue->size++;
}
	

//出队
void pop(struct queue* myqueue) {
	if (myqueue->size == 0) {
		printf("队为空，无法出队！\n");
		system("pause");
		return;
	}
	else {
		struct node* nextnode = myqueue->frontnode->next;
		free(myqueue->frontnode);
		myqueue->frontnode = nextnode;
		myqueue->size--;
	}
}


//获取队头元素
int front(struct queue* myqueue) {
	if (myqueue->size == 0) {
		printf("队为空，无法获取队头元素！\n");
		system("pause");
		return myqueue->size;
	}
	return myqueue->frontnode->data;
}


//判断队是否为空
int empty(struct queue* myqueue) {
	if (myqueue->size == 0) {
		return 0;
	}
	else {
		return 1;
	}
}


int main() {
	struct queue* myqueue = createqueue();
	push(myqueue, 1);
	push(myqueue, 2);
	push(myqueue, 3);
	while (empty(myqueue)) {
		printf("%d     ", front(myqueue));
		pop(myqueue);
	}
	printf("\n");


	system("pause");
	return 0;
}
