#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
//创建链表
struct Node* Init() {
	struct Node* headNode = (struct Node *)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}
//创建节点
struct Node* createNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
};
//插入
void insert(struct Node* headNode,int data) {
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
void delete(struct Node* headNode) {
	struct Node* NextNode = headNode->next;
	headNode->next = NextNode->next;
	free(NextNode);
}
struct Node* searchResult(struct Node* headNode, int data)
{
	struct Node* pMove = headNode->next;
	while (pMove != NULL && pMove->data != data)
	{
		pMove = pMove->next;
	}
	return pMove;
}

//打印
void printList(struct Node* headNode) {
	struct Node* pMove = headNode->next;
	while (pMove) {
		printf("%d\t",pMove->data);
		pMove = pMove->next;
	}
	puts("");
}

struct stack {
	int stackSize;
	struct Node* stackTop;	//栈顶指针
};

struct stack* creatStack() {
	struct stack* mystack = (struct stack*)malloc(sizeof(struct stack));
	mystack->stackSize = 0;
	mystack->stackTop = Init();
	return mystack;
}

void push(struct stack* stack, int data) {
	insert(stack->stackTop, data);
	stack->stackSize++;
}
void updata(struct stack* stack, int data) {
	stack->stackSize--;
	insert(stack->stackTop, data);
}
int Top(struct stack* stack) {
	if (stack->stackSize == 0)
		return -1;
	else
		return stack->stackTop->next->data;
}
//出栈
void pop(struct stack* stack) {
	if (stack->stackSize == 0)
		printf("栈为空，无法出栈");
	else {
		delete(stack->stackTop);
		stack->stackSize--;
	}
}
//展示
void Display(struct stack* Stack) {
	printf("栈中元素:");
	while (!empty(Stack)) {
		printf("%d\t", Top(Stack));
		pop(Stack);
	}
	printf("\n");
}
int empty(struct stack* stack) {
	if (stack->stackSize == 0)
		return 1;
	else
		return 0;
}
void main() {
	struct stack* stack = Init();
	//增
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	while (!empty(stack)) {
		printf("%d\t", Top(stack));
		pop(stack);
	}
	printf("\n");
	printf("栈顶为:%d\n", Top(stack));
	//改
	updata(stack, 10);
	//删
	pop(stack);
	printf("\n");
	system("pause");
}
