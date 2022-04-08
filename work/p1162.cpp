#include<bits/stdc++.h>
using namespace std;
int n,mp[31][31];
bool vis[31][31];
int step[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
queue<pair<int,int>> que;

void find_zero(){
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for(int i=0;i<4;i++){
            int nx = x+step[i][0];
            int ny = y+step[i][1];
            if(nx<0||nx>30||ny<0||ny>30) continue;
            if(!vis[nx][ny]) continue;
            if(mp[nx][ny]==1) continue;
            que.push({nx,ny});
            mp[nx][ny] = -1;
            vis[nx][ny] = false;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&mp[i][j]);
        }
    }
    memset(vis,true,sizeof(vis));
    vis[0][0] = false;
    mp[0][0] = -1;
    que.push({0,0});
    find_zero();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mp[i][j]==0)
                printf("2 ");
            else if(mp[i][j]==1)
                printf("1 ");
                else
                    printf("0 ");
        }
        printf("\n");
    }
    return 0; 


}