//无表头结点
void del(LinkList rp){//删除rp->link
    LinkList node = rp->link;
    rp->link = rp->link->link;
    free(node);
    
}
int deleteSame(LinkList llist){
    LinkList lp = llist;
    while(lp->link == NULL){
        LinkList rp = lp;
        while(rp->link!=NULL){
            if(rp->link->info == lp->info)
                deleteNode(rp);//传入rp,删除rp->link
            rp=rp->link;
        }
        lp = lp->link;
    }
    return 1; //删除成功
}