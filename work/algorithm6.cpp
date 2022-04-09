//单向循环转双向
//无头结点
int toDouble(LinkList llist){
    if(llist == NULL) return 0;

    LinkList p = llist;
    while(p->next != llist){
        p->next->pre = p;
    }
    return 1;//转换成功
}