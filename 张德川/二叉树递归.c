#include<stdio.h>  
#include<malloc.h>  

typedef struct binode {
    char data;
    struct binode* lchild;
    struct binode* rchild;
}BiNode, * BiTree;
/****************************
 *输入创建二叉树： abd##ef###c##
 *其实输入按照先序顺序，#表示叶子节点
 *****************************/
void create(BiTree t) {
    char ch = (char)getchar();
    if (ch == '#') {
        t->data = '#';
        t->lchild = NULL;
        t->rchild = NULL;
    }
    else {
        t->data = ch;
        t->lchild = (BiTree)malloc(sizeof(BiNode));
        create(t->lchild);
        t->rchild = (BiTree)malloc(sizeof(BiNode));
        create(t->rchild);
    }
}
//先序遍历  
void preTraverse(BiTree t) {
    BiTree p = t;
    BiTree stack[20]; //使用栈来替代递归方法  
    int top = 0;
    while (top >= 0) {
        while (p->data != '#') {
            printf("%c ", p->data);
            stack[top++] = p;
            p = p->lchild;
        }
        if (top > 0)
            p = stack[--top]->rchild;
        else
            top = -1;

    }
}
//中序遍历，和先序差不多  
void midTraverse(BiTree t) {
    BiTree p = t;
    BiTree stack[20];
    int top = 0;
    while (top >= 0) {
        while (p->data != '#') {
            stack[top++] = p;
            p = p->lchild;
        }
        if (top > 0) {
            p = stack[--top];
            printf("%c ", p->data);
            p = p->rchild;
        }
        else
            top = -1;
    }
}
//后序遍历，稍微复杂一点  
void afeTraverse(BiTree t) {
    BiTree p = t, q = t;
    BiTree stack[20];
    int top = 0;
    while (top >= 0) {
        while (p->data != '#') {
            stack[top++] = p;
            p = p->lchild;
        }
        if (q->rchild == p) {
            printf("%c ", q->data);
            q->data = '#'; //遍历完的节点直接做叶子标记  
            --top;
        }
        if (top > 0) {
            p = stack[top - 1];
            q = p;
            p = p->rchild;

        }
    }
}
//测试  
int main() {
    BiTree root = (BiTree)malloc(sizeof(BiNode));
    create(root);
    afeTraverse(root);
    printf("\n");
    return 1;
}
