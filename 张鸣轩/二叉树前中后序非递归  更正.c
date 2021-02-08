#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#define N 20

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = y;
	coord.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void meihua() {
	system("title 二叉树前中后序非递归");
	system("color 71");
	system("mode con cols=100 lines=40");
}

typedef struct tree {
	char ch;
	struct tree* lchild;
	struct tree* rchild;
}qwetree;

qwetree* createtree() {
	qwetree* t;
	char s;
	scanf("%c", &s);
	if (s == '#')
		return 0;
	else {
		t = (qwetree*)malloc(sizeof(qwetree));
		t->ch = s;
		t->lchild = createtree();
		t->rchild = createtree();
		return t;
	}
}

void qian(qwetree* t) {
	qwetree** s;
	qwetree* p;
	int top = -1;
	s = (qwetree**)malloc((N + 1) * sizeof(qwetree*));
	s[++top] = t;
	while (top != -1) {
		p = s[top--];
		printf("%c", p->ch);
		if (p->rchild)
			s[++top] = p->rchild;
		if (p->lchild)
			s[++top] = p->lchild;
	}
	free(s);
}

void zhong(qwetree* t) {
	qwetree** s;
	qwetree* p, * q;
	int top = -1;
	s = (qwetree**)malloc((N + 1)*sizeof(qwetree*));
	if (t) {
		while (t) {
			s[++top] = t;
			t = t->lchild;
		}
		while (top != -1) {
			p = s[top--];
			printf("%c", p->ch);
			while (p->rchild) {
				s[++top] = p->rchild;
				q = p->rchild;
				while (q->lchild) {
					s[++top] = q->lchild;
					q = q->lchild;
				}
				break;
			}
		}
	}
}

void hou(qwetree* t) {
	qwetree** s;
	qwetree* p;
	int top = -1;
	s = (qwetree**)malloc((N + 1) * sizeof(qwetree*));
	do {
		while (t) {
			s[++top] = t;
			t = t->lchild;
		}
		p = 0;
		while (top != -1) {
			t = s[top];
			if (t->rchild == p) {
				printf("%c", t->ch);
				top--;
				p = t;
			}
			else {
				t = t->rchild;
				break;
			}
		}
	} while (top != -1);
}

int main() {
	meihua();
	gotoxy(1,15);
	printf("请按顺序输入二叉树：");
	qwetree* bt = createtree();
	printf("\n前序遍历非递归：\n");
	qian(bt);
	printf("\n\n");
	printf("中序遍历非递归：\n");
	zhong(bt);
	printf("\n\n");
	printf("后序遍历非递归：\n");
	hou(bt);
	printf("\n\n");
	return 0;
}
