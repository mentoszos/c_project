#include<bits/stdc++.h>
using namespace std;

//已知先序和中序建立二叉树
struct BinTree{
    BinTree* llink;
    BinTree* rlink;
};
//l1,r1,l2,r2,分别是先序中序的起点和中点
BinTree* createBT(char* pre, char* mid,int l1, int r1,int l2,int r2){
    if(l1>r1) return NULL; //遍历出界
    BinTree* root = (BinTree*)malloc(sizeof(BinTree)); 
    int i = l2;
    while(mid[i]!=pre[l1]) i++;//在中序中找到根的位置
    root->llink = createBT(pre,mid,l1+1,l1+i-l2,l2,i-1);//左子树遍历
    root->rlink = createBT(pre,mid,l1+i-l2+1,r1,i+1,r2);//右子树遍历
    return root;//返回根节点
}