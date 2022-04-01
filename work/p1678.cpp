#include<bits/stdc++.h>
using namespace std;
int m,n,a[100005],b[100005];
long long ans=0;
void find_dis(int mark){
    int *p = lower_bound(a,a+m,mark);
    if(p-a>=m) p = p-1;
    else if(p-a-1>=0 && mark-(*(p-1))<*p-mark) p = p-1;
    ans += abs(*p-mark);
}

int main(){
    scanf("%d %d",&m,&n);
    for(int i =0;i<m;i++){
        scanf("%d",&a[i]);
    }
    for(int i =0;i<n;i++){
        scanf("%d",&b[i]);
    }
    sort(a,a+m);
    for(int i =0;i<n;i++){
        find_dis(b[i]);
    }
    printf("%lld",ans);
}