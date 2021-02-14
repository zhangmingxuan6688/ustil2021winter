#include<stdio.h>
#include<stdlib.h>
struct BiTNode {
	char data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
};
typedef struct BiTNode* BiTree;
void CreatBiTree(BiTree* T)
{
	char ch;
	ch = getchar();
	if (ch == '*')
		*T = NULL;
	else {
		if (!(*T = (BiTree)malloc(sizeof(struct BiTNode)))) {
			printf("内存分配失败！"); return;
		}
		else {
			(*T)->data = ch;
			CreatBiTree(&((*T)->lchild));
			CreatBiTree(&((*T)->rchild));
		}
	}
}
void PreOrderTraverse(BiTree T) {
	if (T) {
		printf("%c", T->data);
		if (T->lchild)
			PreOrderTraverse(T->lchild);
		if (T->rchild)
			PreOrderTraverse(T->rchild);
	}
}
void InOrderTraverse(BiTree T) {
	if (T) {
		if (T->lchild)
			InOrderTraverse(T->lchild);
		printf("%c", T->data);
		if (T->rchild)
			PreOrderTraverse(T->rchild);
	}
}
void PostOrderTraverse(BiTree T) {
	if (T) {
		if (T->lchild)
			PreOrderTraverse(T->lchild);
		if (T->rchild)
			PreOrderTraverse(T->rchild);
		printf("%c", T->data);
	}
}
int main()
{
	BiTree T = NULL;
	printf("请输入二叉树：/n");
	CreatBiTree(&T);
	printf("/n");
	printf("先序遍历二叉树为：/n");
	PreOrderTraverse(T);
	printf("/n");
	printf("中序遍历二叉树为：/n");
	InOrderTraverse(T);
	printf("/n");
	printf("后序遍历二叉树为：/n");
	PostOrderTraverse(T);
	printf("/n");
	system("pause");
	return 0;
}
