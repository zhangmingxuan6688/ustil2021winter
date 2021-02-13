#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int NodeNum = 0; 
typedef struct Node
{
    int data;
    struct Node* next;
}NODE,*PNODE;
PNODE CreatList()
{　　　　　printf("输入数据,以0结束输入\n");
    PNODE head = (PNODE)malloc(sizeof(NODE));
    PNODE tail = head;
    int num = 0;
    int Flag = 1;
    scanf("%d", &num);
    //输入数据，以0结束
    while (num)
    {
        PNODE pnew = (PNODE)malloc(sizeof(NODE));
        pnew->data = num;
        tail->next = pnew;
        tail = pnew;
        NodeNum++;
        scanf("%d", &num);
    }

    tail->next = NULL;
    return head;
}
//遍历链表
void tarverse(PNODE head)
{
    PNODE phead = head->next;
    while (phead != NULL)
    {
        printf("%d ", phead->data);
        phead = phead->next;
    }
    printf("一共有%d个结点\n", NodeNum);
}
//判断是否为空链表
bool isEmpty(PNODE head)
{
    if (head->next = NULL)
    {
        printf("链表为空\n");
        return true;
    }
    else
        return false;
}
//删除结点
void DelNode(PNODE head)
{
    int location = 0;
    printf("删除第几个结点？");
    scanf("%d", &location);
    PNODE p1 = head;
    PNODE p2 = p1->next;
    for (int i = 0; i < location-1; i++)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    p1->next = p2->next;
    free(p2);
    p2 = NULL;
    NodeNum--;
}
//增加结点
int AddNode(PNODE head)
{
    PNODE p1 = head;
    PNODE p2 = p1->next;
    int location = 0;
    int newdata = 0;
    printf("添加在第几个位置？");
    scanf("%d", &location);
    printf("输入新结点数据:");
    scanf("%d", &newdata);
    PNODE pnew = (PNODE)malloc(sizeof(NODE));
    pnew->data = newdata;
    for (int i = 0; i < location - 1; i++)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
        p1->next = pnew;
        pnew->next = p2;
        NodeNum++;
        return 0;
}
//修改结点
int AlterNode(PNODE head)
{
    PNODE p = head;
    int location = 0;
    int newdata = 0;
    printf("修改第几个结点？");
    scanf("%d", &location);
    printf("输入新结点数据:");
    scanf("%d", &newdata);
    PNODE pnew = (PNODE)malloc(sizeof(NODE));
    pnew->data = newdata;
    for (int i = 0; i < location; i++)
    {
        p = p->next;
    }
    p->data = newdata;
    return 0;
}
int main()
{
    PNODE p= (PNODE)malloc(sizeof(NODE));
    p = CreatList();
    tarverse(p);
    DelNode(p);
    tarverse(p);
    AddNode(p);
    tarverse(p);

    system("pause");
    return 0;
}
