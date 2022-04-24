#include<bits/stdc++.h>
using namespace std;
int n;
queue<pair<int,int>> que;
int main(){
    scanf("%d",&n);
    for(int i=0;i<pow(2,n);i++){//输入
        int temp;
        scanf("%d",&temp);
        que.push({temp,i+1});
    }

    while(que.size()>2){
        pair<int,int> a,b,c;
        a= que.front(); que.pop();
        b = que.front();que.pop();
        if(a.first>b.first) c = a;
        else c=b;
        que.push(c);
    }
    if(que.front().first<que.back().first) printf("%d",que.front().second);
    else printf("%d",que.back().second);
}
    
    
