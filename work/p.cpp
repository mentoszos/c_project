#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005];
int l =1, r = 1e9;
int mid;
int calm(int h){
    int sum = 0;
    for(int i=0;i<n;i++){
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
            printf("%d",mid);
            break;
        }
    }
    if(l>r){int m1 =calm(mid-1),m2 = calm(mid),m3 = calm(mid+1);
    if(m3>=m){
        printf("%d",mid+1);
    }
    else if(m2>=m) printf("%d",mid);
    else if(m1>=m) printf("%d",mid-1);
    }

}
