int insertPost_seq(PSeqList palist, int p, DataType x)
{
    if (p < 0 || p > palist->n - 1)
    { //不存在的下标
        printf("not exist\n");
        return 0;
    }
    if (palist->n >= palist->MAXNUM)
    { //插入则越界
        printf("over flow\n");
        return 0;
    }
    for (int i = palist->n - 1; i > p; i--)
    {
        palist->element[i + 1] = palist->element[i];
    }
    palist->element[p + 1] = x;
    palist->n = palist->n + 1;
    return 1; //插入成功
}