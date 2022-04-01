// sum 会超出int范围 ，只开sum的ll即可

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005];
long long l =1, r = 1e9;
long long mid;
long long calm(long long h){
    long long sum = 0;
    for(long long i=0;i<n;i++){
        if(a[i]-h>0) sum = sum+(a[i]-h);
    }
    return sum;
}
void find_h(){
    while(l<=r){
        mid = (l+r)/2;
        if(calm(mid)>m) l = mid+1;
        else if(calm(mid)<m) r = mid-1;
        else{
            printf("%lld",mid);
            break;
        }
    }
    if(l>r){long long m1 =calm(mid-1),m2 = calm(mid),m3 = calm(mid+1);
    if(m3>=m){
        printf("%lld",mid+1);
    }
    else if(m2>=m) printf("%lld",mid);
    else if(m1>=m) printf("%lld",mid-1);
    }
}

int main(){
    scanf("%lld %lld",&n,&m);
    for(long long i =0;i<n;++i){
        scanf("%lld", &a[i]);
    }
    find_h();
}