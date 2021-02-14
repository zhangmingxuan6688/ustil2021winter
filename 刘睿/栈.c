#include<stdio.h>
#include<stdlib.h>
typedef struct LNode {
    int data;
    struct LNode* next;
}LNode, * LinkStack;//把struct LNode * 定义成了新类型 LinkStack///把struct Node 定义成了新类型 LNode


void InitLinkStack(LinkStack& S_top) {//创建链栈顶结点 

    S_top = (LNode*)malloc(sizeof(LNode));
    S_top = NULL;
    printf("栈创建成功\n");
}

void Push(LinkStack& S_top, int e) {//从栈顶压入元素 
    LinkStack q = (LNode*)malloc(sizeof(LNode));
    q->data = e;
    q->next = S_top;
    S_top = q;
}

void Pop(LinkStack& S_top) {//从栈顶删除元素 并打印删除的值 
    LinkStack q;
    q = S_top;
    S_top = S_top->next;
    printf("\n使用删除操作，删除的元素为：%d\n", q->data);
}
void Change(LinkStack S_top, int e) {//修改栈顶的值 
    LinkStack q = (LNode*)malloc(sizeof(LNode));
    q = S_top;
    q->data = e;
    printf("\n修改后的栈顶元素为: %d\n", e);
}
void Search(LinkStack S_top, int i) {//显示栈中第i个元素的值 
    LNode* p = S_top;
    int j = 1;
    while (j < i) {
        p = p->next;
        j++;
    }
    printf("\n第%d个元素为：%d \n", i, p->data);
}
void Show(LinkStack S_top) {//展示栈的元素序列 第一个元素为栈顶 
    LNode* p = S_top;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}
int main() {
    LinkStack S_top;
    InitLinkStack(S_top);//创建栈顶结点 
    Show(S_top);
    for (int i = 1; i <= 10; i++) {//利用for循环push出一个1到10的栈 
        Push(S_top, i);
    }
    Show(S_top);
    Pop(S_top);
    Show(S_top);
    Pop(S_top);
    Show(S_top);
    Change(S_top, 5);
    Show(S_top);
    Search(S_top, 1);
}

