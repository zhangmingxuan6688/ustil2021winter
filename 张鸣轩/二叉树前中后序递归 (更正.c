#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

typedef char qwetype;

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = y;
	coord.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void meihua() {
	system("title 二叉树前中后序递归");
	system("color 71");
	system("mode con cols=60 lines=40");
}

typedef struct qwenode {
	qwetype data;
	struct qwenode* lchild, * rchild;
}qwenode,*qwetree;

int createqwetree(qwetree* t) {
	qwetype ch;
	scanf("%c", &ch);
	if (ch == '#')
		*t = NULL;
	else {
		*t = (qwetree)malloc(sizeof(qwetree));
		(*t)->data = ch;
		createqwetree(&(*t)->lchild);
		createqwetree(&(*t)->rchild);
	}
	return 0;
}

void operation(qwetype ch, int level) {
	printf("%c 在第 ", ch);
	printf("%d 层\n", level);
}

void xian(qwetree t, int level) {
	if (t == NULL)
		return;
	operation(t->data, level);
	xian(t->lchild, level + 1);
	xian(t->lchild, level + 1);
}

void zhong(qwetree t, int level) {
	if (t == NULL)
		return;
	zhong(t->lchild, level + 1);
	operation(t->data, level);
	zhong(t->rchild, level + 1);
}

void hou(qwetree t, int level) {
	if (t == NULL)
		return;
	hou(t->lchild, level + 1);
	hou(t->rchild, level + 1);
	operation(t->data, level);
	
}

int main() {
	meihua();
	gotoxy(3,10);
	int level = 1;
	qwetree t=NULL;
	printf("先序方式创建二叉树：");
	createqwetree(&t);
	printf("\n先序遍历：\n");
	xian(t,level);
	printf("\n中序遍历：\n");
	zhong(t,level);
	printf("\n后序遍历：\n");
	hou(t,level);
	return 0;
}
