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
void printF(Index endd){
    if(endd.prex==-1&&endd.prey ==-1){
        printf("无法通过迷宫");
        getchar();
        return ;
    }
    int ans[400];
    int i=0;
    while(endd.prex!=-1&&endd.prey!=-1){//将答案输入ans
        ans[i] = endd.prey;
        i++;
        ans[i] = endd.prex;
        i++;
        endd = mapp[endd.prex][endd.prey];
    }
    i--;
    while(i>=0){//输出答案
        printf("%d ",ans[i]);
        i--;
    }
    getchar();
    getchar();
}

int main(){
    
    int step[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};//上下左右
    //起点和终点
    int beginx;
    int beginy;
    int endx;
    int endy;
    int n;
    printf("输入迷宫宽度:\n");
    scanf("%d",&n);
    printf("输入迷宫:(0表示可走，-1表示障碍，1表示已走)\n");
    for(int i=0;i<n;i++){//迷宫输入
        for(int j=0;j<n;j++){
            scanf("%d",&mapp[i][j].flag);
        }
    }
    printf("输入迷宫起点和终点((0,0)开始)\n");
    scanf("%d %d %d %d",&beginx,&beginy,&endx,&endy);
    //坐标检验
    if(beginx<0||beginx>=n||beginy<0||beginy>=n||endx<0||endx>=n||endy<0||endy>=n){
        printf("坐标超出范围\n");
        getchar();
        getchar();
        return 0;
    }
    //初始化起点和终点
    Index beginn,endd,current;
    beginn.prex=-1;
    beginn.prey =-1;
    beginn.x = beginx;
    beginn.y = beginy;
    endd.prex = -1;
    endd.prey = -1;
    endd.x = endx;
    endd.y = endy;
    Que que = createQue();
    enQueue(que,beginn);//起点入队
    mapp[beginn.x][beginn.y].flag = 1;//起点已访问
    while(!isEmpty(que)){
        current = frontQueueX(que);//取队头
        deQueue(que);
        for(int i=0;i<4;i++){
            if(mapp[current.x+step[i][0]][current.y+step[i][1]].flag!=-1&&mapp[current.x+step[i][0]][current.y+step[i][1]].flag!=1&&current.x+step[i][0]>=0&&current.y+step[i][1]>=0&&current.x+step[i][0]<n&&current.y+step[i][1]<n){//current的下一步可访问
                mapp[current.x+step[i][0]][current.y+step[i][1]].prex = current.x;
                mapp[current.x+step[i][0]][current.y+step[i][1]].prey = current.y;
                mapp[current.x+step[i][0]][current.y+step[i][1]].x = current.x+step[i][0];
                mapp[current.x+step[i][0]][current.y+step[i][1]].y = current.y+step[i][1];

                if(mapp[current.x+step[i][0]][current.y+step[i][1]].x==endx&&mapp[current.x+step[i][0]][current.y+step[i][1]].y==endy)//若下一步为终点则跳出循环
                    {
                        printF(endd);
                        return 0;
                    }

                enQueue(que,mapp[current.x+step[i][0]][current.y+step[i][1]]);//入队
                mapp[mapp[current.x+step[i][0]][current.y+step[i][1]].x][mapp[current.x+step[i][0]][current.y+step[i][1]].y].flag=1;
            }
        }
    }
    

}