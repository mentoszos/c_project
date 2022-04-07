#include<bits/stdc++.h>
using namespace std;
int mapp[500][500];
int step[8][2]={{-2,-1},{2,-1},{-2,1},{2,1},{-1,-2},{-1,2},{1,2},{1,-2}};
int n,m,x,y;
queue<pair<int,int>> que;
void bfs(){
    while(!que.empty()){
        x=que.front().first;
        y =que.front().second;
        que.pop();
        for(int i=0;i<8;i++){
            int nx=x+step[i][0];
            int ny=y+step[i][1];
            if(nx<1||nx>n||ny<1||ny>m||mapp[nx][ny]!=-1) continue;
            mapp[nx][ny] = mapp[x][y]+1;
            que.push({nx,ny});

        }
    }
}
int main(){
    scanf("%d %d %d %d",&n,&m,&x,&y);
    memset(mapp,-1,sizeof(mapp));
    que.push({x,y});
    mapp[x][y]=0;
    bfs();
    for(int i =1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%-5d",mapp[i][j]);
        }
        printf("\n");
    }
    return 0;
}