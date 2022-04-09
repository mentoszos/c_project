//无头结点
int getLen(Linklist llist){
    int n;
    Linklist p =llist;
    if(p==NULL) return 0;
    p=p->link;
    n=1;
    while(p!=llist){
        n++;
        p = p->link;
    }
    return n;
}