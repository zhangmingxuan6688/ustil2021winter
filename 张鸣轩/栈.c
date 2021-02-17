/*#include<stdio.h>
#include<stdlib.h>

//构造一个空栈s     InitStack(&s)
void init(sqstack s) {
	s.base = (int*)malloc(size * sizeof(int));
	s.top = s.base;
	s.stacksize = size;
}

//插入元素e为新的栈顶元素    push(&s,e)
void push(sqstack s, int e) {
	if (s.top - s.base > s.stacksize) {
		s.base = (int*)realloc(s.base, (s.stacksize + incresize) * sizeof(int));
		s.top = s.base + s.stacksize;
		s.stacksize += incresize;

	}
	*s.top++ = e;
}

//删除s的栈顶元素，并用e返回其值   pop(&s,&e)
void pop(sqstack s, int e) {
	if (s.top != s.base) {
		e = *(--s.top);
	}

}
*/

/*#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};



int main() {

	//结构体变量连接结构变量
	//方法一
	struct node node1 = { 1,NULL };
	struct node node2 = { 2,NULL };
	struct node node3 = { 3,NULL };
	node1.next = &node2;
	node2.next = &node3;

	//方法二
	struct node* pnode1 = &node1;
	struct node* pnode2 = &node2;
	struct node* pnode3 = &node3;
	pnode1->next = pnode2;
	pnode2->next = pnode3;
    //指针怎么变成变量的使用方式

	
	int a = 1;
	int* p = &a;
	printf("%d\n", *p);  //*p等效于a

	int* pmalloc = (int*)malloc(sizeof(int));
	*pmalloc = 100;
	printf("%d\n", *pmalloc);


	system("pause");
	return 0;
}
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};


//创建结点
struct node* createnode(int data) {
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;

}


//创建栈，就是创建一个 struct stack的变量
struct stack {
	struct node* stacktop;  // 栈顶标记
	int size;               //栈中元素个数   充当万金油
};

struct stack* createstack() {
	
	//创建过程就是初始化过程
	struct stack* mystack = (struct stack*)malloc(sizeof(struct stack));
	mystack->stacktop = NULL;
	mystack->size = 0;
	return mystack;
}

void push(struct stack* mystack, int data) {

	//插入的这个结点创建出来
	struct node* newnode = createnode(data);

	//入栈操作就是链表表头插入
	newnode->next = mystack->stacktop;
	mystack->stacktop = newnode;
	mystack->size++;
}


//获取栈顶元素
int top(struct stack* mystack) {

	//防御编程
	if (mystack->size == 0) {
		printf("栈为空，无法获取栈顶元素！\n");
		system("pause");
		return mystack->size;
	}
	
	return mystack->stacktop->data;


}


//出栈
void pop(struct stack* mystack) {
	if (mystack->size == 0) {
		printf("栈为空，无法出栈!\n");
		system("pause");
	}
	else {
		struct node* nextnode = mystack->stacktop->next;
		free(mystack->stacktop);
		mystack->stacktop = nextnode;
		mystack->size--;
	}
}

//万金油函数
int empty(struct stack* mystack) {
	if (mystack->size == 0)
		return 0;
	return 1;
}


int main() {
	struct stack* mystack = createstack();
	push(mystack, 1);
	push(mystack, 2);
	push(mystack, 3);
	while (empty(mystack)) {
		printf("%d    ", top(mystack));
		pop(mystack);
	}
	printf("\n");
	system("pause");
	return 0;
}
