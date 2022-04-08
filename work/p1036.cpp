#include<bits/stdc++.h>
using namespace std;
int n,k,begin,ans = 0;
int arr[30];
long long sum;
bool isprime(long long sum){
    if(sum ==2) return true;
    for(int i=2;i<sum;i++){
        if(sum%i ==0) return false;
    }
    return true;
}
void dfs(int deep, int begin){
    if(deep == k){
        if(isprime(sum))
        ans++;
    return;
    }
    if(begin>=n) return;

    for(int i=begin;i<n;i++){//不会越界，能进循环必能往下走
        sum+=arr[i];
        deep++;
        dfs(deep,i+1);
        deep--;
        sum-=arr[i];
    }
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        sum = arr[i];
        dfs(1,i+1);
    }
    printf("%d",ans);
    return 0;
}