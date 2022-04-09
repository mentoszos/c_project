#include<bits/stdc++.h>
using namespace std;
int maxNum,maxx,sum=0,l,r;
int n,m;
int a[100005];
bool check(int num){//和最大值为num时段数是否小于m
    int cnt = 1;//段数
    int sum = 0;
    for(int i=0;i<n;i++){
        if(sum+a[i]<=num)
           { sum += a[i];
           
           }
            
        else{
            cnt++;
            sum = a[i];
        }
    }
    if(cnt>m) return true;
    else return false;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    maxNum = a[max_element(a,a+n)-a];
    l=maxNum;
    r=sum;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(mid))//mid取小了
            l = mid+1;
        else r = mid-1;
    }
    printf("%d",l);
    return 0;

}