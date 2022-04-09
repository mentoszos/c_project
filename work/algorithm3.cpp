//顺序表
int swap(PSeqList palist){
    int l=0;
    int r = palist->n -1;
    while(l<r){
        DataType temp = palist->element[l];
        palist->element[l] = palist->element[r];
        palist->element[r] = temp;
        l++;
        r--;
    }
    if(l>=r) return 1;//置逆成功
}

//单链表(不带头结点)
int swap(LinkList llist){
    LinkList fp = llist;
    while(fp->link!=NULL){//fp停在原最后结点
        fp = fp->link;
    }
    while(llist->link!=NULL){
        LinkList sp = llist;
        while(sp->link->link!=NULL){//将sp停留在link为NULL的结点的前一个结点
            sp = sp->link;
        }
        sp->link->link = sp;
        sp->link = NULL;
    }
    llist = fp;
    return 1;//置逆成功

}


//算法第五题

int delX(PSeqList palist,int n,DataType x){
    for(int i=0;i<n;i++)
}