#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, *BiTree;
void CreateBiTree(BiTree* T){
	ElemType ch;
	scanf_s("%c", &ch);
	getchar();
	if(ch == '#')
		*T = NULL;
	else {
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}
void operation2(ElemType ch,int level){
	printf("%c在第", ch);
	printf("%d层",level);
}
void PreOrderTraverse(BiTree T,int level) {
	if (T == NULL)
		return;
	operation2(T->data, level);
	PreOrderTraverse(T->lchild, level + 1);
	PreOrderTraverse(T->rchild, level + 1);
}
void InOrderTraverse(BiTree T, int level) {
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild, level + 1);
	operation2(T->data, level);
	InOrderTraverse(T->rchild, level + 1);
}
void PostOrderTraverse(BiTree T, int level) {
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild, level + 1);
	PostOrderTraverse(T->rchild, level + 1);
	operation2(T->data, level);
}
int main() {
	int level = 1;
	int c = 0;
	BiTree T = NULL;
	printf("先序方式创建二叉树:");
	CreateBiTree(&T);
	printf("递归前序遍历输出为：\n");
	PreOrderTraverse(T, level);
	printf("\n");
	printf("递归中序遍历输出为：");
	InOrderTraverse(T, level);
	printf("\n");
	printf("递归后序遍历输出为：");
	PostOrderTraverse(T, level);
	printf("\n");
	return 0;
}
