#include<iostream>
using namespace std;
class QNode {
public:
    int data;
    QNode* qnext;
};
class Linkqueue {
public:
    void InitQueue(Linkqueue& Q);//&引用 不是取地址；
    
    void EnQueue(Linkqueue& Q);
    void DeQueue(Linkqueue& Q);
    void showqueue(Linkqueue& Q);
    void findQueue(Linkqueue& Q, int value);
    void change(Linkqueue& Q, int value1,int value2);
    void destroyQueue(Linkqueue& Q);

private:
    QNode* front;
    QNode* rear;
    
};
//队列的初始化
void Linkqueue::InitQueue(Linkqueue& Q) {
    QNode* p = new QNode;
    p->qnext = NULL;
    Q.front = p;
    Q.rear = p;
}

//队列节点的插入
void Linkqueue::EnQueue(Linkqueue& Q) {
    QNode* pnew = new QNode;
    pnew->qnext = NULL;
    cout << "请输入该节点的数值 = ";
    cin >> pnew->data;
    Q.rear->qnext = pnew;
    Q.rear = pnew;
}
//队列节点的删除
void Linkqueue::DeQueue(Linkqueue& Q)
{
    QNode* p;
    p = Q.front->qnext;
    Q.front->qnext = Q.front->qnext->qnext;
    if (Q.rear == p)
        Q.rear = Q.front;
    delete p;
}
//队列修改
void Linkqueue::change(Linkqueue& Q, int value1,int value2) {
    QNode* p;
    p = Q.front->qnext;
    for (int i = 1; i < value1; i++) {
        p = p->qnext;
    }
    cout << p->data;
    p->data = value2;
}
//显示队列
void Linkqueue::showqueue(Linkqueue& Q) {
    QNode* p;
    p = Q.front->qnext;
    if (p == NULL)
    {
        cout << "队列为空" << endl;
    }
    cout << endl;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->qnext;
    }
    cout << endl;
}
//队列查询
void Linkqueue::findQueue(Linkqueue& Q, int value) {
    QNode* ptarget;
    ptarget = Q.front;
    int n = 0;
    cout << "数据值为" << value << "的位置=";
    while (ptarget != Q.rear) {
        if (ptarget->data == value) {
            cout << n + 1 << " ";
        }
        n = n + 1;
        ptarget = ptarget->qnext;
    }
    cout << endl;
}

//销毁队列
void Linkqueue::destroyQueue(Linkqueue& Q) {
    while (Q.front)
    {
        Q.rear = Q.front->qnext;
        delete Q.front;
        Q.front = Q.rear;
    }
}
int main() {
    Linkqueue queue;
    Linkqueue* Q;
    int n;
    int value1,value2;
    Q = new Linkqueue;
    queue.InitQueue(*Q);  
    cout << "请输入需要的队列节点数 = ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        queue.EnQueue(*Q);
    }
    cout << "队列节点为：";
    queue.showqueue(*Q);
    cout << "删除队首节点后为：";
    queue.DeQueue(*Q);
    queue.showqueue(*Q);
    queue.findQueue(*Q, 1);
    cout << "请输入要修改的节点数据序号,和要修改成的数据";
    cin >> value1 >> value2;
    queue.change(*Q,value1,value2);
    queue.showqueue(*Q);
    queue.destroyQueue(*Q);
    return 0;
}
