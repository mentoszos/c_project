#include<bits/stdc++.h>
using namespace std;
struct Index{
    int prex;
    int prey;
    int x;
    int y;
};
struct SeqQueue{
    int MAXNUM;
    int f,r;
    Index *index;
};
typedef SeqQueue* Que;

int mapp[100][100];//用于记录迷宫
Index imapp[100][100];//用于记录迷宫各个格子的前一个格子坐标

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
Index frontQueue(Que que){//取x
    if(isEmpty(que)){
        printf("空队列，无法取队头\n");
        Index index;
        return index;
    }
    else return que->index[que->f];
}
//输出答案
void printF(int beginx,int beginy,int endx,int endy,int n){
    if(imapp[endx][endy].prex==-1||imapp[endx][endy].prey ==-1){
        printf("找不到答案F");
        getchar();
    }
    //存答案坐标
    int x[100];
    int y[100];
    int i=1;
    x[0]=endx;
    y[0]=endy;
    int currentx,currenty;
    currentx = endx;
    currenty = endy;
    while(currentx!=beginx&&currenty!=beginy){
        x[i] = imapp[currentx][currenty].prex;
        y[i] = imapp[currentx][currenty].prey;
        currentx=x[i];
        currenty=y[i];
        i++;
    }
    printf("\n");
    printf("\n");
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            printf("%2d ",mapp[i][j]);
        }
        printf("\n");
    }
    //输出答案坐标
    for(;i>=0;i--){
        printf("(%d %d) ",x[i],y[i]);
    }
    getchar();getchar();
   

}
int main(){
    //初始化地图
    for(int i=0;i<100;i++){
        for(int j =0;j<100;j++){
            mapp[i][j] = -1;
            imapp[i][j].prex=-1;
            imapp[i][j].prey = -1;
            imapp[i][j].x = 0;
            imapp[i][j].y = 0;
        }
    }
    Que que = createQue();
    int step[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};//下上右左
    int n;//迷宫大小
    int flag=0;//用于判断是否为终点
    int beginx,beginy;//起点坐标
    int endx,endy;//终点坐标
    
    printf("输入迷宫大小:\n");
    scanf("%d",&n);
    printf("输入迷宫(1表示起点和终点，0表示可走，-1表示不可走,坐标从(0,0)开始:\n");
    //迷宫输入
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            scanf("%d",&mapp[i][j]);
            if(mapp[i][j]==1 && flag ==0){//当前点为起点
                beginx = i;
                beginy = j;
                flag =1;
            }
            else if(mapp[i][j]==1&&flag ==1){//当前点为终点
                endx = i;
                endy = j;
                mapp[i][j]=0;//终点修改为可走
            }
        }
    }
    //状态初始化
    Index current;//当前状态
    current.x = beginx;
    current.y = beginy;
    current.prex = -1;
    current.prey = -1;
    enQueue(que,current);
    while(!isEmpty(que)){
        current = frontQueue(que);
        deQueue(que);
        int nextx;//下一步的x坐标
        int nexty;//下一步的y坐标
        for(int i=0;i<4;i++){
            nextx = current.x+step[i][0];
            nexty = current.y+step[i][1];
            if(nextx>=0&&nextx<n&&nexty>=0&&nexty<n&& mapp[nextx][nexty]==0){//当下一步坐标不越界，且下一步坐标可走时
                mapp[nextx][nexty]=1;//已访问标记

                //记录该点的上一个点的坐标
                imapp[nextx][nexty].prex = current.x;
                imapp[nextx][nexty].prey = current.y;
                if(nextx == endx && nexty==endy){//如果下一步为终点
                    printF(beginx,beginy,endx,endy,n);//输出答案
                    getchar();
                    getchar();
                    return 0;
                }
                Index index;
                index.x = nextx;
                index.y = nexty;
                enQueue(que,index);//新状态进队
            }
        }
    }
    //当找不到出路时
    printf("找不到答案");
    getchar();
    return 0;
}