#include<bits/stdc++.h>
using namespace std;
int n,a[20][20],ans = 0;
//bool vis[10000][10000];
bool xie_l[200],xie_r[30],lie[20];
vector<int> ans1;


void dfs_queen(int x){
    if(x>n){
        ans++;
      if(ans<=3){
          for(auto i :ans1)
            printf("%d ",i);
            printf("\n");
      }
      return;
      
    }
    for(int i=1;i<=n;i++){
        if(!xie_l[x-i+100] && !xie_r[x+i] && !lie[i]){
            xie_l[x-i+100] = true;
            xie_r[x+i] = true;
            lie[i] = true;
            ans1.push_back(i);
            dfs_queen(x+1);
            ans1.pop_back();
            xie_l[x-i+100] = false;
            xie_r[x+i] = false;
            lie[i] = false;

        }
    }
}
int main(){
    memset(a,-1,sizeof(a));
    scanf("%d",&n);
    dfs_queen(1);
    printf("%d",ans);
}