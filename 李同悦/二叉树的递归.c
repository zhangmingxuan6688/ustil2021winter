#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


//二叉树结点
typedef struct BINARYNODE {
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;

//递归遍历,前序遍历
void Recursion(BinaryNode* root) {
	//递归结束条件，没有根节点
	if (root == NULL) {
		return;
	}
	//先序遍历,先访问根
	printf("%c  ", root->ch);
	//再遍历左子树
	Recursion(root->lchild);
	//再遍历右子树
	Recursion(root->rchild);
}



//中序遍历
void Recursion2(BinaryNode* root) {
	//递归结束条件，没有根节点
	if (root == NULL) {
		return;
	}
	//先遍历左子树
	Recursion2(root->lchild);
	//再访问根
	printf("%c  ", root->ch);
	//最后遍历右子树
	Recursion2(root->rchild);
}


//后序遍历
void Recursion3(BinaryNode* root) {
	//递归结束条件，没有根节点
	if (root == NULL) {
		return;
	}
	//先遍历左子树
	Recursion3(root->lchild);
	//再遍历右子树
	Recursion3(root->rchild);
	//最后访问根
	printf("%c  ", root->ch);

}


//创建二叉树
void CreateBinaryTree() {
	//创建结点
	BinaryNode node1 = { 'A',NULL,NULL };
	BinaryNode node2 = { 'B',NULL,NULL };
	BinaryNode node3 = { 'C',NULL,NULL };
	BinaryNode node4 = { 'D',NULL,NULL };
	BinaryNode node5 = { 'E',NULL,NULL };
	BinaryNode node6 = { 'F',NULL,NULL };
	BinaryNode node7 = { 'G',NULL,NULL };
	BinaryNode node8 = { 'H',NULL,NULL };
	//建立结点关系
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;
	//递归遍历，先序遍历
	printf("先序遍历：");
	Recursion(&node1);
	printf("\n");
	//中序遍历
	printf("中序遍历：");
	Recursion2(&node1);
	printf("\n");
	//后序遍历
	printf("后序遍历：");
	Recursion3(&node1);
}

int main() {
	CreateBinaryTree();
	return 0;
}
