#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005];
int maxv;
int cal_k(int l){
    int kq = 0;
    
    for(int i=0;i<n;i++){
        
        if(a[i]>=l){
            //int temp = a[i];
            kq += a[i]/l;
            //while(temp/l!=0){
           //     temp = temp / l;
           //     kq++;
           // }
        }
    }
    return kq;
}

void find_l(){
    int l = 1, r=maxv;
    while(l<=r){
        int mid = (l+r)/2;
        if(cal_k(mid)>=k) 
        l = mid+1;
        else r = mid-1;
    }
    printf("%d",r);

}
int main(){
    scanf("%d %d",&n, &k);
    for(int i =0;i<n;i++){
        scanf("%d",&a[i]);
    }
    maxv = a[max_element(a,a+n)-a];
    find_l();
}