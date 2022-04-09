DataType findMin(PSeqList palist, int n)
{
    DataType minn = palist->element[0];
    for (i = 1; i < n; i++)
    { //遍历表中元素
        if (minn > palist->element[i])
            minn = palist->element[i];
    }
    return minn;
}