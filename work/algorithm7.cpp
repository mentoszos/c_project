P115
    算法题 5.
Queue StacktoQueue(Stack st){
     PseqQueue qu= createEmptyQueue_seq(st->MAXNUM);
     while (!st.isEmpty()){
         enQueue_seq(qu,top_seq(st));
         pop_seq(st);
     }
     free(st);
}


9. quelen == m时队列满;
void enQueue_seq(DataType x)
{
    if (quelen == m)
    {
        printf("Full Queue");
    }
    else
    {
        rear = (rear + 1) % m;
        sequ[rear] = x;
        quelen++;
    }
}

DataType deQueue_seq()
{
    if (quelen == 0)
    {
        printf("Empty Queue");
    }
    else
    {
        int index = (m + rear - quelen) % m;
        quelen--;
        return sequ[index];
    }
}
