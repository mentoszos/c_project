#include <bits/stdc++.h>
using namespace std;

//只有一个节点的树高度为0
//递归
struct BinTree
{
    BinTree *llink;
    BinTree *rlink;
};
int calH(BinTree *t)
{
    if (t == NULL)
        return -1; //若二叉树为空
    int l = calH(t->llink);
    int r = calH(t->rlink);
    if (l > r)
        return l + 1;
    else
        return r + 1;
}
//非递归
int calH(BinTree *t)
{
    BinTree *node = t;
    if (node == NULL)
        return -1;
    Queue que = createEmptyQueue(200); //开个队列
    int last, height = -1;             // last指向每一层中最后一个元素的下一个位置
    enQueue(que, node);
    last = que->r;
    while (!isEmpty(que))
    {
        node = frontQueue(que); //取头元素
        deQueue(que);           //出队
        if (node->llink != NULL)
            enQueue(que->llink); //左子结点入队
        if (node->rlink != NULL)
            enQueue(que->rlink); //右子结点入队
        if (que->f == last)
        { //当遍历完一层，高度+1，更新last
            height++;
            last = que->r;
        }
    }
    return height;
}