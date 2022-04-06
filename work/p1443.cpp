#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int map1[500][500];
bool vis[500][500];
int cnt=0;
int step[][2]={{-2,-1},{2,-1},{-2,1},{2,1},{-1,-2},{-1,2},{1,2},{1,-2}};
void go_from(int x,int y){
    if(x<1||x>n||y<1||y>m){
        return;
    }
    for(int i=0;i<8;i++){
        x +=map1[i][0];
        y +=map1[i][1];
        if(!vis[x][y]){//如果能走
            cnt++;
            vis[x][y]=false;
            map1[x][y] = cnt;
            go_from(x,y);
            cnt--;
            vis[x][y]=true;
            
        }
        x -=map1[i][0];
        y -=map1[i][1];
    }
}
int main(){
    for(int i=0;i<500;i++){
        memset(map1,-1,sizeof(int)*500);
    }
    scanf("%d %d %d %d",&n,&m,&x,&y);
    go_from(x,y);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",map1[i][j]);
        }
        printf("\n");
    }

}