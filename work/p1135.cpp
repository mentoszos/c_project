#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int arr[205];
queue<int> que;
int floors[205];

int bfs(){
    while(!que.empty()){
        int floor = que.front();
        que.pop();
        for(int i=0;i<2;++i){
            int nfloor;
            if(i==0){
                nfloor = floor+floors[floor];
            }
            else{ nfloor = floor-floors[floor];}
            if(nfloor<1||nfloor>n||arr[nfloor]!=-1) continue;//越界
            arr[nfloor] =arr[floor]+1;
            if(nfloor ==b) return arr[nfloor];
            que.push(nfloor);
        }
    }
    if(que.empty()) return -1;
}
int main(){
    //输入
    scanf("%d %d %d",&n,&a,&b);
    for(int i=1;i<=n;i++){
        scanf("%d",&floors[i]);
    }
    if(a==b){
        printf("0");
        return 0;
    }
    memset(arr,-1,sizeof(arr));
    arr[a]=0;
    que.push(a);
    printf("%d",bfs());

}