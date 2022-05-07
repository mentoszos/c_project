#include<bits/stdc++.h>
using namespace std;
struct Index{
    int x;
    int y;
    int prex;
    int prey;
    int flag;
};
struct SeqQueue{
    int MAXNUM;
    int f,r;
    Index* index;
};
typedef SeqQueue* Que;
Index mapp[200][200];

//创建空队列
Que createQue(){
    Que que = (Que)malloc(sizeof(SeqQueue));
    if(que!=NULL){
        que->MAXNUM = 200;//默认200;
        que->f = 0;
        que->r = 0;
        que->index = (Index*)malloc(sizeof(Index)*200);
    }
    else
        printf("创建队列失败\n");
    return que;
}
//判断是否空队列
int isEmpty(Que que){
    if(que->f == que->r) return 1;//空队列
    else return 0; // 非空
}

//入队
void enQueue(Que que,Index index){
    if((que->r+1)%que->MAXNUM == que->f){//队满
        printf("队满\n");
    }
    //入队
    que->index[que->r] = index;
    que->r = (que->r+1)%que->MAXNUM;
}

//出队
void deQueue(Que que){
    if(isEmpty(que)){
        printf("x空队列，无法出队\n");
        return;
    }
    que->f = (que->f+1) %que->MAXNUM;
}
//取队头
Index frontQueueX(Que que){//取x
    if(isEmpty(que)){
        printf("空队列，无法取队头\n");
        Index index;
        return index;
    }
    else return que->index[que->f];
}
int main(){
    Que que  = createQue();
    Index index;
    index.x =1;
    printf("x of index:%d\n",index.x);
    index.x = 2;
    enQueue(que,index);
    index.x = 100;
     Index index1 =frontQueueX(que);
    printf("x of index:%d\n",index.x);
    printf("队头的x1为%d",index1.x);
    getchar();

}