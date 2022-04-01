#include<cstdio>
using namespace std;
int n,m,a[1000005];
int left,right;

int bs(int num){
    int l = left,r = right;
    while(l<=r){
        int mid = l+((r-l)/2);
        if(num<a[mid]) 
            r=mid-1;
        else if(num>a[mid])
            l = mid+1 ;
        else{
            if(mid-1>=0 && a[mid-1] == a[mid]){ 
                r=mid-1;
                continue;
                }
            return mid+1;
            
        }
    }
    if(l>r) return -1;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i =0;i<n;i++){
        scanf("%d",&a[i]);
    }
    left=0;right=n-1;
    for(int i=0;i<m;i++){
        int num;
        scanf("%d",&num);
        printf("%d",bs(num));
        if(i!=(m-1))
        printf(" ");
    }
}