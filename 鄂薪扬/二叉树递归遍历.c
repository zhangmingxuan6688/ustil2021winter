#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	char data;
	struct node *left;
	struct node *right;
}Node, *Tree;
Tree create_tree(){
	Node *root = NULL;
	char ch;
	scanf("%c", &ch); 
	if (ch != '#'){
		root = (Node*)malloc(sizeof(Node));
		root->data = ch;
		root->left = create_tree(); 
		root->right = create_tree();
	}
	else{
		root = NULL;
	}
	return root;
}
//前序
void qianxu(Tree root){
	if (root != NULL){
		printf(" %c - ", root->data);
		qianxu(root->left);
		qianxu(root->right);
	}
//中序
void zhongxu(Tree root){
	if (root != NULL){
		zhongxu(root->left);
		printf(" %c - ", root->data);
		zhongxu(root->right);
	}
}
//后序
void houxu(Tree root){
	if (root != NULL){
		houxu(root->left);
		houxu(root->right);
		printf(" %c - ", root->data);
	}
}
void main(){
Tree root = create_tree();
qianxu(root);
printf("\n");
houxu(root);
printf("\n");
zhongxu(root);
}
