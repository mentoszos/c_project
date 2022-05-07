#include<bits/stdc++.h>
using namespace std;
struct Index{
    int x;
    int y;
    int res;//记录当前进栈次数，初始为0，第五次时弹栈
};
struct SeqStack
{
    int MAXNUM;
    int t; //指向栈顶
    Index* index;
};
typedef SeqStack *St;

//用于存答案
int ansx[200];
int ansy[200];
int mapp[100][100];

St createSt()
{
    St st = (St)malloc(sizeof(SeqStack));
    if (st != NULL)
    {
        st->MAXNUM = 200; //默认最大长度200
        st->t = -1;
        st->index = (Index *)malloc(sizeof(Index) * 200);
    }
    else
        printf("创建失败");
    return st;
}

int isEmpty(St st)
{
    if (st->t == -1)
        return 1; //空
    else
        return 0; //非空
}

int push_seq(St st, Index index)
{
    if (st->t == st->MAXNUM - 1)
    {
        printf("overflow\n");
        return 0;
    }
    else
    {
        st->t = st->t + 1;
        st->index[st->t] = index;
        return 1;
    }
}

int pop_seq(St st)
{
    if (st->t == -1)
    {
        printf("空栈\n");
        return 0;
    }
    else
    {
        st->t = st->t - 1;
        return 1;
    }
}

Index top_seq(St st)
{
    if (st->t == -1)
    {
        printf("空栈\n");
        Index index;
        return index;
    }
    else
    {
        return st->index[st->t];
    }
}

int main(){
   St st=createSt();
   Index i;
   i.res=5;
   push_seq(st,i);
   printf("%d\n",st->t);
   pop_seq(st);
   printf("%d\n",st->t);
   getchar();
   getchar();
}