#include<bits/stdc++.h>
using namespace std;
int n,maxx=0;
struct node
{
    int left;
    int right;
    
} nodes[1000005];
void dfs(int node, int deep){
    if(node ==0) return;
    
    if(maxx<deep) maxx = deep;
    dfs(nodes[node].left,deep+1);
    dfs(nodes[node].right,deep+1);

}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int leftt,rightt;
        scanf("%d %d",&leftt,&rightt);
        nodes[i].left = leftt;
        nodes[i].right = rightt;
    }
    dfs(1,1);
    printf("%d",maxx);
}

