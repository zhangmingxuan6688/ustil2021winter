#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define Stack_increment 20
#define Stack_Size 100  

//定义节点模板Node
typedef struct  Tree
{
    char data;
    struct Tree* lchild;
    struct Tree* rchild;
}Node;
//返回类型为结构体指针，这里 注意指针的值就是地址0xBALABALA
Node* createBinaryTree()
{
    Node* root;
    char ch;
    scanf("%c", &ch);

    if (ch == '#')
    {
        root = NULL;
    }
    else
    {
        root = (Node*)malloc(sizeof(Node));
        root->data = ch;
        root->lchild = createBinaryTree();
        root->rchild = createBinaryTree();
    }

    return root;//返回根节点
}

typedef struct
{
    int top;
    Node* arr[Stack_Size];//节点指针数组 100个地址槽
}Stacktree;
//栈的初始化
void InitStack(Stacktree* S)
{
    S->top = 0;
}
//入栈
void Push(Stacktree* S, Node* x)
{
    int top1 = S->top;
    if (x->data == '#')
    {
        return;
    }
    else
    {
        S->arr[top1++] = x;
        S->top++;
    }
}
//弹栈
int Pop(Stacktree* S)
{
    int top = S->top;
    if (S->top == 0)
    {
        return 0;
    }
    else
    {
        --(S->top);
        return 1;
    }
}

Node* GetTop(Stacktree* S)
{
    int top1 = S->top;
    Node* p;
    p = S->arr[top1--];
    return p;
}

Node* GetTop1(Stacktree* S)
{
    int top1 = S->top;
    Node* p;
    top1--;
    p = S->arr[top1];
    return p;
}

int IsEmpty(Stacktree* S)
{
    return(S->top == 0 ? 1 : 0);
}

void preorderRecursive(Node* p)
{
    if (p != NULL)
    {
        printf("%c ", p->data);
        preorderRecursive(p->lchild);
        preorderRecursive(p->rchild);
    }
}

void inorderRecursive(Node* p)
{
    if (p != NULL)
    {
        inorderRecursive(p->lchild);
        printf("%c ", p->data);
        inorderRecursive(p->rchild);
    }
}

void postorderRecursive(Node* p)
{
    if (p != NULL)
    {
        postorderRecursive(p->lchild);
        postorderRecursive(p->rchild);
        printf("%c ", p->data);
    }
}

void preordernotRecursive(Node* p)
{
    if (p)
    {
        Stacktree stree;
        InitStack(&stree);
        Node* root = p;
        while (root != NULL || !IsEmpty(&stree))
        {
            while (root != NULL)
            {
                printf("%c  ", root->data);
                Push(&stree, root);
                root = root->lchild;
            }

            if (!IsEmpty(&stree))
            {
                Pop(&stree);
                root = GetTop(&stree);
                root = root->rchild;
            }
        }
    }
}

void inordernotRecursive(Node* p)
{
    if (p)
    {
        Stacktree stree;
        InitStack(&stree);
        Node* root = p;
        while (root != NULL || !IsEmpty(&stree))
        {
            while (root != NULL)
            {
                Push(&stree, root);
                root = root->lchild;
            }

            if (!IsEmpty(&stree))
            {
                Pop(&stree);
                root = GetTop(&stree);
                printf("%c  ", root->data);
                root = root->rchild;
            }
        }
    }
}

void postordernotRecursive(Node* p)
{
    Stacktree stree;
    InitStack(&stree);

    Node* root;
    Node* pre = NULL;

    Push(&stree, p);

    while (!IsEmpty(&stree))
    {
        root = GetTop1(&stree);

        if ((root->lchild == NULL && root->rchild == NULL) || (pre != NULL && (pre == root->lchild || pre == root->rchild)))
        {
            printf("%c ", root->data);
            Pop(&stree);
            pre = root;
        }

        else
        {
            if (root->rchild != NULL)
            {
                Push(&stree, root->rchild);
            }

            if (root->lchild != NULL)
            {
                Push(&stree, root->lchild);
            }
        }

    }
}

void main()
{

    printf("请输入二叉树，'#'为空\n");
    Node* root = createBinaryTree();

    printf("\n递归先序遍历:\n");
    preorderRecursive(root);

    printf("\n递归中序遍历:\n");
    inorderRecursive(root);

    printf("\n递归后序遍历:\n");
    postorderRecursive(root);

    printf("\n非递归先序遍历\n");
    preordernotRecursive(root);

    printf("\n非递归中序遍历\n");
    inordernotRecursive(root);

    printf("\n非递归后序遍历\n");
    postordernotRecursive(root);

    getchar();
    getchar();
}
