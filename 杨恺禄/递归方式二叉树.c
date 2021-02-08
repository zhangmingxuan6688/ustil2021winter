#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
//二叉树的二叉链表结构，也就是二叉树的存储结构，一个数据域，两个指针域，（分别指向左右孩儿）
typedef struct {
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,* BiTree;      //二叉链表，二叉树的指针
//二叉树的建立.
//按前序遍历的方式建立二叉树.
//当然也可以以中序或后序的方式建立二叉树.
void CreateBiTree(BiTree* T) {
	ElemType ch;
	scanf("%c", &ch);
	if (ch == '#') {
		*T = NULL;
	}
	else {
		*T = (BiTree*)malloc(sizeof(BiTNode));
		if(!*T)
		exit(0);
		(*T)->data = ch;
		//生成节点
		CreateBiTree(&(*T)->lchild);//构造左子树
		CreateBiTree(&(*T)->rchild);//构造右子树
	}
}
void operation2(ElemType ch, int level) {
	printf("%c在第", ch);
	printf("%d层\n", level);
}
//递归前序遍历二叉树
void PreOrderTraverse(BiTree T, int level) {
	if (T == NULL) {
		return;
	}
	//此处表示对遍历的树节点进行的操作，根据你自己的要求进行操作，这里只是输出了节点的数据
	    //operation1(T->data)
	operation2(T->data, level);//输出了层数
	PreOrderTraverse(T->lchild, level + 1);
	PreOrderTraverse(T->rchild, level + 1);
}
//递归中序遍历二叉树
void InOrderTraverse(BiTree T, int level) {
	if (T == NULL) {
		return;
	}
	InOrderTraverse(T->lchild, level + 1);
	//operation1(T->data);
	operation2(T->data, level);//输出了层数
	InOrderTraverse(T->rchild, level + 1);
}
//递归后序遍历二叉树
void PostPrserTraverse(BiTree T, int level) {  //先递归，后输出
	if (T == NULL)
		return;
	PostPrserTraverse(T->lchild, level + 1);
	PostPrserTraverse(T->rchild, level + 1);
	//operation(T->data);
	operation2(T->data, level);//输出了层数
}
int main() {
	int level = 1;//表示层数
	BiTree T = NULL;
	printf("先序方式创建二叉树：");//类似输入AB#D##C##
	CreateBiTree(&T);//建立二叉树
	printf("递归前序遍历输出为：\n");
	PreOrderTraverse(T, level);//进行前序遍历，其中operation1()和operation2()函数表示对遍历的节点数据进行的处理
	printf("\n");
	printf("递归中序遍历输出为：\n");
	PreOrderTraverse(T, level);
	printf("\n");
	printf("递归后序遍历输出为：\n");
	PreOrderTraverse(T, level);
	printf("\n");
}
