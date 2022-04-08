#include<bits/stdc++.h>
using namespace std;
int time_map[450][450];
int steps[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int m,x,y;
//bool vis[450][450];
//bool safevis[450][450];
int vis[450][450];
bool vis1[405][405];
queue<pair<int,int>> que;
struct stone
{
    int x;
    int y;
    int time;
}stones[50005];


/*void set_unsafe(int x,int y){
    vis[x][y]=false;
    if(x+1>=0&&x+1<=300)
        vis[x+1][y]=false;
    if(x-1>=0&&x-1<=300)
        vis[x-1][y]=false;
    if(y+1>=0&&y+1<=300)
        vis[x][y+1]=false;
    if(y-1>=0&&y-1<=300)
        vis[x][y-1]=false;
}*/

/*void set_unsafe1(int x,int y){
    safevis[x][y]=false;
    if(x+1>=0&&x+1<=300)
        safevis[x+1][y]=false;
    if(x-1>=0&&x-1<=300)
        safevis[x-1][y]=false;
    if(y+1>=0&&y+1<=300)
        safevis[x][y+1]=false;
    if(y-1>=0&&y-1<=300)
        safevis[x][y-1]=false;
}*/
void updateVis(){
    //memset(vis,true,sizeof(vis));在主函数初始化
   /* for(int i=0;i<m;i++){
        if(stones[i].time==time) //<= to ==
            set_unsafe(stones[i].x,stones[i].y);
    }*/
    for(int i=0;i<m;i++){
        int x = stones[i].x;
        int y = stones[i].y;
        vis[x][y] = min(vis[x][y],stones[i].time);
        if(x+1>=0&&x+1<=300)
            vis[x+1][y] = min(vis[x+1][y],stones[i].time);
        if(x-1>=0&&x-1<=300)
            vis[x-1][y] = min(vis[x-1][y],stones[i].time);
        if(y+1>=0&&y+1<=300)
            vis[x][y+1] = min(vis[x][y+1],stones[i].time);
        if(y-1>=0&&y-1<=300)
        vis[x][y-1] = min(vis[x][y-1],stones[i].time);
    }
}
/*void set_safe(){
    memset(safevis,true,sizeof(safevis));
    for(int i=0;i<m;i++){
        set_unsafe1(stones[i].x,stones[i].y);
    }
}*/
bool beenSafe(int x,int y){
   //return safevis[x][y];
   return (vis[x][y]==2000);
}

int bfs(){
    while(!que.empty()){
        x=que.front().first;
        y=que.front().second;
        que.pop();
       // updateVis(time_map[x][y]+1);//更新下一时刻地图
        for(int i=0;i<4;i++){
            int nx = x+steps[i][0];
            int ny = y+steps[i][1];
           // updateVis(time_map[x][y]+1);
            if(nx<0||ny<0) continue;//越界
            //if(!vis[nx][ny]) continue;//无法走
            if(vis[nx][ny]<=time_map[x][y]+1) continue;
            if(!vis1[nx][ny]) continue;//无法走
            if(beenSafe(nx,ny)){//走到安全位置,返回时间
                return time_map[nx][ny] = time_map[x][y]+1;
            }
            que.push({nx,ny});
            time_map[nx][ny] = time_map[x][y]+1;
            vis1[nx][ny] =false;
        }
    }
    while (que.empty())
    {
        return -1;
    }
    
}

int main(){
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&stones[i].x,&stones[i].y,&stones[i].time);
    }
    for(int i =0;i<450;i++){
        for(int j=0;j<450;j++){
            vis[i][j]=2000;
        }
    }
   memset(vis1,true,sizeof(vis1));
    //set_safe();
    updateVis();
    que.push({0,0});
    time_map[0][0]=0;
    printf("%d",bfs());
    return 0;

}