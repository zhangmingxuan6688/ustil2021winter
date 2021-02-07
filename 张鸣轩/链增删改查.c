#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

typedef struct node {
	char name[20];
	char number[10];
	struct node* next;
}Node;

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = y;
	coord.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}                         


void meihua() {
	system("title 电话簿");
	system("color 71");
	system("mode con cols=100 lines=80");
}

Node* List() {
	int i;
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	Node* p = head;
	for (i = 0; i < 3; i++) {
		Node* s = (Node*)malloc(sizeof(Node));
		printf("请建立新的联系人姓名 : "); gets(s->name);
		printf("请建立新的联系人电话号码 : "); gets(s->number);
		p->next = s;
		p = p->next;
		s->next = NULL;
	}
	return head;
}

void bianli(Node* head) {
	Node* p = head;
	int i = 0;
	while (p->next) {
		p = p->next;
		printf("********************\n");
		printf("第 %d 个联系人的信息  \n", i++);
		printf("姓名 : "); puts(p->name);
		printf("电话号 : "); puts(p->number);
	}
}

void AddNode(Node* head) {
	Node* p = head;
	while (p->next)
		p = p->next;
	Node* s = (Node*)malloc(sizeof(Node));
	p->next = s;
	printf("请输入新的联系人的信息: \n");
	printf("姓名 : "); gets(s->name);
	printf("电话号 : "); gets(s->number);
	s->next = NULL;
}

void DeleteNode(Node* head) {
	Node* p = head;
	while (p->next->next)
		p = p->next;
	free(p->next);
	p->next = NULL;
}

int SearchIndex(char name[], Node* head, int* index) {
	Node* p = head;
	while (p->next) {
		p = p->next;
		(*index)++;
		if (strcmp(p->name, name) == 0)
			return 1;
	}
	return 0;
}

void search1(char name[], Node* head, int* index) {
	printf("请输入您要查找的联系人的姓名：");
	gets(name);
	if (SearchIndex(name, head, &index) == 0)
		printf("查无此人\n");
	else {
		printf("确有此人\n");
		}
}

void ChangeNode(Node* head) {
	char name[20];
	int index = 0;
	Node* p = head;
    printf("请输入您要修改的联系人姓名 : ");
	gets(name);
    if (SearchIndex(name, head, &index) == 0)
		printf("查无此人\n");
	else {
		while (index > 0) {
			index--;
			p = p->next;
		}
        printf("请输入修改后联系人的信息: \n");
		printf("姓名 : "); gets(p->name);
		printf("电话号 : "); gets(p->number);
	}
}

void pause() {
	system("pause");
	system("cls");
}

void Selection(int n, Node* head) {
	char name[20];
	int index = 0;
	switch (n)
	{
	case 1:
		system("cls");
		AddNode(head);
		break;
	case 2:
		system("cls");
		DeleteNode(head);
		break;
	case 3:
		system("cls");
		ChangeNode(head);
		break;
	case 4:
		system("cls");
		search1(name,head,&index);
		break;
	case 5:
		system("cls");
		bianli(head);
		break;
	case 6:
		break;
	default:
		printf("请正确输入操作指令\n");
		break;
	}
}

void U() {
	printf("请输入按键执行链表的操作 : \n");
	printf("输入 1 进行 增加 操作 : \n");
	printf("输入 2 进行 删除 操作 : \n");
	printf("输入 3 进行 修改 操作 : \n");
	printf("输入 4 进行 查找 操作 : \n");
	printf("输入 5 进行 遍历 操作 : \n");
	printf("输入 6 关闭程序 : \n");
	printf("  链表管理系统 >  ");
}

void L() {
	int n;
	
	Node* head = List();
	
	U();
	while (~scanf_s("%d", &n)) {
		getchar();
		if (n==6)
			break;
		Selection(n, head);
		pause();
		U();
	}
}

int main() {
	meihua();
	gotoxy(1, 5);
	L();
	return 0;
}


