#include<bits/stdc++.h>
using namespace std;
int n;
pair<int,int> cons[135];
 pair<int,int> tree[300];
 void buildtree(int node,int begin,int end){
     if(begin == end){
         tree[node].first = cons[begin].first;
         tree[node].second = cons[begin].second;
       //tree[node] = cons[begin];
         return;
     }
     int leftnode = 2*node;
     int rightnode = leftnode + 1;
     int mid = (begin+end)/2;
     buildtree(leftnode,begin,mid);
     buildtree(rightnode,mid+1,end);
     if(tree[leftnode].first>tree[rightnode].first) 
        tree[node] = tree[leftnode];
    else tree[node] = tree[rightnode];
 }
 int main(){
     scanf("%d",&n);
     for(int i=1;i<=pow(2,n);i++){// input
         int temp;
         scanf("%d",&temp);
         cons[i].first = temp;
         cons[i].second = i;
     }
     buildtree(1,1,pow(2,n));
    /* for(int i =1;i<=8;i++){
        printf("%d ",cons[i].first);
    }
    printf("\n");
    for(int i =1;i<=15;i++){
        printf("{%d %d} ",tree[i].first,tree[i].second);
    }*/
    if(tree[2].first>tree[3].first) printf("%d",tree[3].second);
    else printf("%d",tree[2].second);


     
 }