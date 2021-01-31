#include"stdio.h"
#include"stdlib.h"
#define STACK_SIZE 100
#define STACKINCREMENT 10
typedef struct{
int *base;
int *top;
int stacksize;
}Stack;
//初始化
int InitStack(Stack &S){
S.base=(int *)malloc(STACK_SIZE * sizeof(int));
if(!S.base)
return 0;
S.top=S.base;
S.stacksize=STACK_SIZE;
return 1;
}
//销毁
void DesStack(Stack &S){
S.top=S.base;
free(S.base);
S.base = NULL;
S.top = NULL;
S.stacksize = 0;
printf("1");
}
//置空
void ClearStack(Stack &S){
S.top=S.base;
}
//判空
bool StackEmpty(Stack &S){
if(S.base==S.top)
return true;
else
return false;
}
//长度
int StackLen(Stack &S){
return S.top - S.base;
}
//获取
int GetTop(Stack &S){
return *(S.top-1);
}
//进栈
int Push(Stack &S,int e){
if(S.top-S.base>=S.stacksize){
S.base = (int *)realloc(S.base,(S.stacksize + STACKINCREMENT)*sizeof(int));
if(!S.base) return 0;
S.top = S.base + S.stacksize;
S.stacksize += STACKINCREMENT;
}
*S.top++=e;
return 1;
}
//删除栈顶
int Pop(Stack &S){
return *--S.top;
}
//输出
void StackTraverse(Stack &S){
int *p=NULL;
p=S.top;
while(p!=S.base){
p--;
printf("%d",*p);
}
}
void main(){
Stack S;
printf("初始化：");
printf("%d\n",InitStack(S));
printf("入栈");
Push(S,1);
Push(S,2);
Push(S,3);
Push(S,4);
Push(S,5);
printf("输出");
StackTraverse(S);
printf("长度");
printf("%d",StackLen(S));
printf("获取栈顶");
printf("%d",GetTop(S));
printf("删除并获取栈顶");
printf("%d",Pop(S));
printf("长度");
printf("%d",StackLen(S));
printf("判空");
StackEmpty(S);
printf("置空");
ClearStack(S);
printf("判空");
StackEmpty(S);
DesStack(S);

}
