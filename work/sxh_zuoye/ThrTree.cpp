#include<bits/stdc++.h>
using namespace std;
struct ThrTreeNode;
typedef ThrTreeNode* PThrTreeNode;
struct ThrTreeNode{
    int elem;
    PThrTreeNode llink;
    PThrTreeNode rlink;
    int ltag;
    int rtag;
};
typedef struct ThrTreeNode* ThrTree;
struct SeqStack
{
    int MAXNUM;
    int t; //指向栈顶
    PThrTreeNode *info;
};
typedef SeqStack *St;

St createSt()
{
    St st = (St)malloc(sizeof(SeqStack));
    if (st != NULL)
    {
        st->MAXNUM = 200; //默认最大长度200
        st->t = -1;
        st->info = (PThrTreeNode *)malloc(sizeof(PThrTreeNode) * 200);
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

int push_seq(St st, PThrTreeNode element)
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

PThrTreeNode top_seq(St st)
{
    if (st->t == -1)
    {
        printf("空栈\n");
        PThrTreeNode p;
        return p;
    }
    else
    {
        return st->info[st->t];
    }
}
//对称序线索化二叉树
void thread1(ThrTree t){
    St st = createSt();//默认200
    ThrTree p,pr;
    if(t==NULL) return;
    do{
        while(p!=NULL){//遇到结点则压栈,然后进入其左子树
            push_seq(st,p);
            p=p->llink;
        }
        p=top_seq(st);
        pop_seq(st);
        if(pr!=NULL){
            if(pr->rlink==NULL){//修改前驱左指针
                pr->rlink=p;
                pr->rtag = 1;
            }
            if(pr->llink==NULL){//修改该结点右指针
                pr->llink = p;
                pr->ltag = 1;
            }
        }
        pr = p;
        p=p->rlink;//进入右子树
    }while(!isEmpty(st)||p!=NULL);
}

//周游
void nInOrder(ThrTree t){
    ThrTree p  = t;
    if(t==NULL) return;
    while(p->llink!=NULL&&p->ltag==0) p = p->llink;
    while(p!=NULL){
        printf("%d ",p->elem);//访问p
        if(p->rlink!=NULL&&p->rtag==0){
            p=p->rlink;
            while(p->llink!=NULL && p->ltag==0) p=p->llink;//顺右子树的左子树往下走
        }
        else p = p->rlink;//顺线索往下
    }
}
int searchKey(ThrTree* t,int keyword,PThrTreeNode* posision){
    PThrTreeNode p,q;
    p = *t;
    q=p;
    while(p!=NULL){
        q=p;
        if(p->elem == keyword){
            *posision=p;
            return 1;
        }
        else if(p->elem>keyword) p = p->llink;
        else p = p->rlink;
    }
    *posision = q;
    return 0;
}
int insert(ThrTree* t,int keyword){
    PThrTreeNode p,posision;
    if(searchKey(t,keyword,&posision)==1){ //已存在该keyword的结点
        printf("已存在该节点");
        getchar();
        return 0;}
    p = (PThrTreeNode)malloc(sizeof(struct ThrTreeNode));
    if(p==NULL){
        printf("创建p结点出错");
        getchar();
        return 0;
    }
    p->elem = keyword;
    p->llink=NULL;
    p->rlink = NULL;
    p->ltag=0;
    p->rtag=0;
    if(posision==NULL) *t=p;
    else if(keyword<posision->elem) posision->llink = p;
    else posision->rlink = p;
    return 1;
}

int main(){
    printf("输入结点个数:\n");
    ThrTree t;
    int n;
    int keyword;
    scanf("%d",&n);
    printf("输入结点(数字):\n");
    scanf("%d",&keyword);
    t->elem = keyword;
    t->llink=NULL;
    t->rlink=NULL;
    t->ltag=0;
    t->rtag=0;
    //建树
    for(int i=1;i<n;i++){
        scanf("%d",&keyword);
        insert(&t,keyword);
    }
    thread1(t);//线索化
    nInOrder(t);//周游


}