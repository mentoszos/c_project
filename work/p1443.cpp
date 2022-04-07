#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int map1[500][500];
//bool vis[500][500];
int cnt=0;
int step[8][2]={{-2,-1},{2,-1},{-2,1},{2,1},{-1,-2},{-1,2},{1,2},{1,-2}};
void go_from(int x,int y){
    if(x<1||x>n||y<1||y>m){
        return;
    }
    for(int i=0;i<8;i++){
        x +=step[i][0];
        y +=step[i][1];
        if(!(x<1||x>n||y<1||y>m)&&(map1[x][y]==-1)){//如果能走
            cnt++;
            //vis[x][y]=true;

            map1[x][y] = cnt;
            go_from(x,y);
            cnt--;
            //vis[x][y]=false;
            
        }
        x -=step[i][0];
        y -=step[i][1];
    }
}
int main(){
    scanf("%d %d %d %d",&n,&m,&x,&y);
   for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            map1[i][j]=-1;
        }}
    //vis[x][y]=true;
    map1[x][y]=0;
    go_from(x,y);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",map1[i][j]);
        }
        printf("\n");
    }
   
}