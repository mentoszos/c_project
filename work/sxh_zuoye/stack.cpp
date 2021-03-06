#include <bits/stdc++.h>
using namespace std;
struct SeqStack
{
    int MAXNUM;
    int t; //指向栈顶
    char *info;
};
typedef SeqStack *St;

St createSt()
{
    St st = (St)malloc(sizeof(SeqStack));
    if (st != NULL)
    {
        st->MAXNUM = 200; //默认最大长度200
        st->t = -1;
        st->info = (char *)malloc(sizeof(char) * 200);
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

int push_seq(St st, char element)
{
    if (st->t == st->MAXNUM - 1)
    {
        printf("overflow\n");
        return 0;
    }
    else
    {
        st->t = st->t + 1;
        st->info[st->t] = element;
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

char top_seq(St st)
{
    if (st->t == -1)
    {
        printf("空栈\n");
        return '\0';
    }
    else
    {
        return st->info[st->t];
    }
}

int main()
{
    char chs[200];
    St st = createSt();
    printf("输入表达式(默认英文括号):\n");
    scanf("%s", chs);
    int i;
    for (i = 0; i < 200; i++)
    { //寻找第一个左括号
        if (chs[i] == '(' || chs[i] == '[' || chs[i] == '{')
        {
            push_seq(st, chs[i]);
            break;
        }
        else if (chs[i] == '(' || chs[i] == '[' || chs[i] == '}')
        {
            printf("不匹配\n");
            getchar();
            getchar();
            return 0;
        }
        if (chs[i] == '\0')
        {
            printf("表达式内无括号\n");
            getchar();
            getchar();
            return 0;
        }
    }
    for (i = i + 1; i < 200; i++)
    {
        if (chs[i] == '(' || chs[i] == '[' || chs[i] == '{')
            push_seq(st, chs[i]);
        else if (chs[i] == ')')
        {
            if (isEmpty(st))
            { //栈为空
                printf("括号不匹配\n");
                getchar();
                getchar();
                return 0;
            }
            else if (top_seq(st) != '(')
            { //左括号不匹配
                printf("括号不匹配\n");
                getchar();
                getchar();
                return 0;
            }
            else
                pop_seq(st);
        }
        else if (chs[i] == ']')
        {
            if (isEmpty(st))
            { //栈为空
                printf("括号不匹配\n");
                getchar();
                getchar();
                return 0;
            }
            else if (top_seq(st) != '[')
            { //左括号不匹配
                printf("括号不匹配\n");
                getchar();
                getchar();
                return 0;
            }
            else
                pop_seq(st);
        }
        else if (chs[i] == '}')
        {
            if (isEmpty(st))
            { //栈为空
                printf("括号不匹配\n");
                getchar();
                getchar();
                return 0;
            }
            else if (top_seq(st) != '{')
            { //左括号不匹配
                printf("括号不匹配\n");
                getchar();
                getchar();
                return 0;
            }
            else
                pop_seq(st);
        }
        else if (chs[i] == '\0')//到达表达式末尾 
        {
            if (isEmpty(st))//栈中无括号
            {
                printf("匹配成功\n");
                getchar();
                getchar();
                return 0;
            }
            else//栈中有括号
            {
                printf("括号不匹配\n");
                getchar();
                getchar();
                return 0;
            }
        }
    }
}
