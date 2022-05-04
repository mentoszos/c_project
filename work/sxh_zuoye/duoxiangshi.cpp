#include<bits/stdc++.h>
using namespace std;

struct Node{
    double xishu;
    int zhishu;
    Node* nextt;
};
//创建一项
Node* createNode(double xishu,int zhishu){
    Node* node = (Node*)malloc(sizeof(struct Node));
    if(node!=NULL){
        node->xishu = xishu;
        node->zhishu = zhishu;
        node->nextt = NULL;
    }
    return node;
}//创建多项式
Node* createF(double* a,int* b,int len){
    Node* beginn = createNode(a[0],b[0]);
    Node* pre = beginn;
    Node* node;
    for(int i=1;i<len;i++){
        node = createNode(a[i],b[i]);
        pre->nextt = node;
        pre = node;
    }
    return beginn;
}
//将一个项合并到多项式s1中
Node* insertNode(Node* f,Node* node){
    Node* l = f;
    Node* r = f->nextt;
    if(node->zhishu>f->zhishu){//插在头之前
            node->nextt = f;
            f = node;
            return f;
        }
    

    while(r!=NULL){
        if(node->zhishu == l->zhishu){
            l->xishu = l->xishu+node->xishu;
            break;
        }
        else if(node->zhishu<l->zhishu && node->zhishu>r->zhishu){
            l->nextt = node;
            node->nextt = r;
            break;
        }
        l=r;
        r = r->nextt;
    }
    if(r==NULL){
        if(node->zhishu ==l->zhishu){
        l->xishu = l->xishu+node->xishu;
    }
        else{
        l->nextt = node;
        }
    }
    return f;
}
//多项式合并
Node* merge(Node* f1,Node* f2){
    Node* node = f2;
    while(node!=NULL){
        Node* node1 = createNode(node->xishu,node->zhishu);
        insertNode(f1,node1);
        node =node->nextt;
    }
    return f1;
}
void printOne(Node* node1,int flag){//flag表示是否为第一项
    Node* node = (Node*)malloc(sizeof(Node));
    if(node==NULL){
        printf("打印失败\n");
        return;
    }
    node->xishu = node1->xishu;
    node->zhishu = node1->zhishu;
    node->nextt =NULL;
    if(node->xishu==0) return;//系数为0
    if(flag==1){//第一项输入模式
        if(node->zhishu==0){//指数为0
            printf("%.1lf",node->xishu);
        }
        else{//指数不为0
            printf("%.1lfX^%d",node->xishu,node->zhishu); 
        }
    }
    else{//非第一项输入模式
        if(node->zhishu==0){//指数为0
            if(node->xishu<0){//系数小于0
                printf("%.1lfX",node->xishu);
            }
            else{//系数大于0
                printf("+%.1lf",node->xishu);
            }
        }
        else{//指数不为0
            if(node->xishu<0){//系数小于0
                printf("%.1lfX*%d",node->xishu,node->zhishu);
            }
            else{//系数大于0
                printf("+%.1lfX^%d",node->xishu,node->zhishu);
            }

        }

    }
}
void printF(Node* f){
    Node* node = f;
    //先输出第一项
    printOne(node,1);
    node = node->nextt;
    while(node!=NULL){
        printOne(node,0);
        node=node->nextt;
    }

}

int main(){
    int n1,n2;
    double a1[10],a2[10];
    int b1[10],b2[10];
    printf("两个多项式的项数分别为(3 2):\n");
    scanf("%d %d",&n1,&n2);
    printf("输入第一个多项式的系数和指数(从高次项到低次项)(6 3 4 2 2 1):\n");
    for(int i=0;i<n1;i++){
        scanf("%lf %d",&a1[i],&b1[i]);
    }
    printf("输入第二个多项式的系数和指数(从高次项到低次项)(4 2 2 1):\n");
    for(int i=0;i<n2;i++){
        scanf("%lf %d",&a2[i],&b2[i]);
    }
    //创建多项式
    Node* f1 = createF(a1,b1,n1);
    Node* f2 = createF(a2,b2,n2);
    printf("两项多项式分别为:\n");
    printF(f1);
    printf("\n");
    printF(f2);
    printf("\n");
    f1 = merge(f1,f2);//合并f1 and f2
    printf("合并后多项式为:\n");
    printF(f1);
     scanf("%d %d",&n1,&n2);
    return 0;
}