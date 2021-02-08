#include<stdio.h>
#include<stdlib.h>
#define N 20
//二叉树节点的结构体表示形式
typedef struct tree {
	char ch;
	struct tree* lchild;
	struct tree* rchild;
}BitTree;
//创建二叉树，利用递归的方法
//按前序次序输入。如A # # (#表示空数）
BitTree* CreateTree() {
	BitTree* bt;
	char str;
	scanf_s("%c", &str);
	if (str == '#') {
		return 0;
	}
	else {
		bt = (BitTree*)malloc(sizeof(BitTree));//BitTree* bt = (BitTree*)malloc(sizeof(BitTree));
		bt->ch = str;
		bt->lchild = CreateTree();
		bt->rchild = CreateTree();
		return bt;
	}
}
//前序遍历的非递归实现
void PreOrder(BitTree* bt) {
	BitTree** s;
	BitTree* p;
	int top = -1;
	s = (BitTree**)malloc((N + 1) * sizeof(BitTree*));//创建栈；
	s[++top] = bt;//初始化栈；
	while (top != -1) {
		p = s[top--];//s[0] = a s[1] = b s[0] = c ;
		printf("%c", p->ch);
		if (p->rchild) 
			s[++top] = p->rchild;//s[0]右；
		if (p->lchild)
			s[++top] = p->lchild;//s[1]左；
	}
	free(s);
}
//中序遍历，非递归实现
void InOrder(BitTree* bt) {
	BitTree** s;
	BitTree* p, * q;
	int top = -1;
	s = (BitTree**)malloc((N + 1) * sizeof(BitTree*));//创建栈；
	if (bt) {
		while (bt) {//一直遍历左子树知道该节点的左孩子为空为止；
			s[++top] = bt;//将所有左孩子存入栈中；
			bt = bt->lchild;//指向下一个左子树；
		}
		while(top!=-1){//栈空时结束循环
			p = s[top--];//刚开始讲最p指向左下角的左孩子，并且移向该节点的父节点
			printf("%c", p->ch);//输出左下角的节点；
			while (p->rchild) {//遍历移动后节点有没有右节点；
				s[++top] = p->rchild;//将这个节点的右子树入栈
				q = p->rchild;//这个右子树节点赋给q；
				while (q->lchild) {//判断节点q有没有左子树；
					s[++top] = q->lchild;//有左子树，将与这个节点相连的所有左子树都赋给s
					q = q->lchild;
				}
				break;//结束当前循环，回到第二个while循环继续刚才的步骤
			}
		}
	}
}
void PostOrder(BitTree* bt) {
	BitTree** s;
	BitTree* p;
	int top = -1;
	s = (BitTree**)malloc((N + 1) * sizeof(BitTree*));
	do {
		while (bt) {
			s[++top] = bt;
			bt = bt->lchild;
		}
		p = 0;
		while (top != -1) {
			bt = s[top];
			if (bt->rchild == p) {//p:表示为null，或者右子节点被访问过了
				printf("%c", bt->ch);//输出结点数据域
				top--;//输出以后，top--；
				p = bt;//p记录下来刚刚访问的节点
			}
			else {
				bt = bt->rchild;//访问右子树节点
				break;
			}
		}	
	}
	while (top != -1);
}

int main() {
	printf("请以顺序输入二叉树（#表示该节点的子节点为空）：\n");
	BitTree* btr = CreateTree();
	printf("前序遍历非递归实现：\n");
	PreOrder(btr);
	printf("\n");
	printf("中序遍历非递归实现：\n");
	InOrder(btr);
	printf("\n");
	printf("后序遍历非递归实现：\n");
	PostOrder(btr);
	printf("\n");
	return 0;
}
