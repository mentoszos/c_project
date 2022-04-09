#include<bits/stdc++.h>
using namespace std;
int minsb = 1000000;
int s,b;
int n;
pair<int,int> a[15];
void dfs(int begin){
    if(begin>=n) return;

    for(int i=begin;i<n;i++){
        s =s*a[i].first;
        b +=a[i].second;
        minsb = min(minsb,abs(s-b));
        dfs(i+1);
        b-=a[i].second;
        s = s/a[i].first;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a[i].first,&a[i].second);
    }
    for(int i=0;i<n;i++){
        s=a[i].first;
        b = a[i].second;
        minsb = min(minsb,abs(s-b));
        
        dfs(i+1);
    }
    printf("%d",minsb);
}