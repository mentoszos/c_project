#include<bits/stdc++.h>
using namespace std;
struct Index{
    int x;
    int y;
    int res;//记录当前进栈次数，初始为0，第五次时弹栈
};
struct SeqStack
{
    int MAXNUM;
    int t; //指向栈顶
    Index* index;
};
typedef SeqStack *St;

//用于存答案
int ansx[200];
int ansy[200];
int mapp[100][100];

St createSt()
{
    St st = (St)malloc(sizeof(SeqStack));
    if (st != NULL)
    {
        st->MAXNUM = 500; //默认最大长度200
        st->t = -1;
        st->index = (Index *)malloc(sizeof(Index) * 500);
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

int push_seq(St st, Index index)
{
    if (st->t == st->MAXNUM - 1)
    {
        printf("overflow\n");
        return 0;
    }
    else
    {
        st->t = st->t + 1;
        st->index[st->t] = index;
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

Index top_seq(St st)
{
    if (st->t == -1)
    {
        printf("空栈\n");
        Index index;
        return index;
    }
    else
    {
        return st->index[st->t];
    }
}
//输出答案
void printF(int i,int n){
    printf("\n");
    for(int j=0;j<i;j++){
        printf("(%d,%d) ",ansx[j],ansy[j]);
        mapp[ansx[j]][ansy[j]] = 1;
    }
    printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%2d ",mapp[i][j]);
        }
        printf("\n");
    }
    getchar();
    getchar();
}

int main(){
    int n;//迷宫大小
    int flag=0;//是否为终点
    int beginx,beginy,endx,endy;//起点终点坐标
    int i=0;//ans的下标
    int step[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};//下上右左
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
                mapp[i][j]=0;//将终点修改为可走
            }
        }
    }
    //状态初始化
    St st = createSt();
    Index current;
    current.x=beginx;
    current.y = beginy;
    current.res = 0;
    ansx[i]=current.x;
    ansy[i] =current.y;
    ++i;
    push_seq(st,current);
    int flag1 = 0;//表示当前step的上个step是否能走
    while(!isEmpty(st)){
        if(ansx[i-1]==endx&&ansy[i-1]==endy){//找到答案时
            printF(i,n);//输出ans
            return 0;
        }        int cnt = st->index[st->t].res;
        int nextx,nexty;
        if(cnt==4){//当前元素出现在栈顶第五次时弹栈
            pop_seq(st);
        }
        else if(cnt == 0){//走step[0]
            nextx = st->index[st->t].x+step[cnt][0];
            nexty = st->index[st->t].y+step[cnt][1];
            if(nextx>=0&&nextx<n&&nexty>=0&&nexty<n && mapp[nextx][nexty]==0){//当下一步坐标不越界，且下一步坐标可走时
                flag1 = 1;
                mapp[nextx][nexty] = 1;//访问标记
                ansx[i] = nextx;//ans增加
                ansy[i] = nexty;
                ++i;
                Index index1;
                index1.x = nextx;
                index1.y = nexty;
                index1.res = 0;
                st->index[st->t].res++;//栈顶次数加1
                push_seq(st,index1);//当前状态压栈
            }
            else{//走不通
                flag1 =0;
                st->index[st->t].res++;//栈顶次数加1
            }
        }
        else if(cnt == 1||cnt == 2||cnt == 3){//走step[cnt]
            nextx = st->index[st->t].x+step[cnt][0];
            nexty = st->index[st->t].y+step[cnt][1];
            if(flag1==1){//取消当前状态的上一步的标记
                int prex = ansx[i];
                int prey = ansy[i];
                i--;
                mapp[prex][prey] = 0;  
            }
            if(nextx>=0&&nextx<n&&nexty>=0&&nexty<n&& mapp[nextx][nexty]==0){//当下一步坐标不越界，且下一步坐标可走时
                flag1 = 1;
                mapp[nextx][nexty] = 1;//访问标记
                ansx[i] = nextx;//ans增加
                ansy[i] = nexty;
                ++i;
                Index index1;
                index1.x = nextx;
                index1.y = nexty;
                index1.res = 0;
                st->index[st->t].res++;//栈顶次数加1
                push_seq(st,index1);//当前状态压栈
            }
            else{//走不通
                flag1 =0;
                st->index[st->t].res++;//栈顶次数加1
            }
        }
        
    }
    //无答案时
    printf("无答案");
    getchar();
    getchar();
    
}