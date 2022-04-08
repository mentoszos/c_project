#include<bits/stdc++.h>
using namespace std;
int ans =0;
int n,m,t,sx,sy,fx,fy;
bool mp[7][7];
int steps[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

void dfs(int sx,int sy){
    if(sx == fx && sy == fy) {
        ans++;
        return;}
    for(int i =0;i<4;i++){
        sx += steps[i][0];
        sy += steps[i][1];
        if((sx>0&&sx<=n&&sy>0&&sy<=m) && mp[sx][sy]){
            mp[sx][sy]=false;
            dfs(sx,sy);
            mp[sx][sy] = true;
        }
        sx -= steps[i][0];
        sy -= steps[i][1];
        
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&t);
    scanf("%d %d %d %d",&sx,&sy,&fx,&fy);
    memset(mp,true,sizeof(mp));
    //初始化地图
    for(int i=0;i<t;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        mp[x][y] = false;
    }
    mp[sx][sy] = false;
    
    dfs(sx,sy);
    printf("%d",ans);
    return 0;

}