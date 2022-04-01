#include<iostream>
using namespace std;
int index = -1;
void bs(int a[],int num, int l, int r){
    if (num == a[r])
    {
        index = r+1;
        return;
    }
    if(num == a[l]){
        index = l+1;
        return;
    }
    
    if(a[l]!=num && l>=r) return ;

    int mid = (l+r)/2;
    if(num<a[mid])  bs(a,num,l,mid-1);
    else if(num == a[mid]){
        while(mid-1>=0 && a[mid-1] == a[mid]){
            mid--;
        }
        index = mid+1;
        return;
    }
    else bs(a,num,mid+1,r);
    
}
/*int bs(int a[], int num, int l, int r){
    int mid;
    
    while(l<r){
        mid=(l+r)/2;
        if(num < a[mid]){
            r=mid-1;
        }
        else if(num>a[mid]){
            l = mid+1;
        }
        else{
            while(mid-1>=l && a[mid-1] == a[mid]){
                mid--;
                return mid+1;
            }
            return mid+1;
        }
    }
    if(num == a[mid]) return mid+1;
    else return -1;
}*/

int main(){
    int n,m;
    cin>>n;
    cin>>m;
    int a[n];
    int nums[m];
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    for(int i =0;i<m;i++){
        cin>>nums[i];
        index = -1;
      // cout<< bs(a,nums[i],0,n-1)<<" ";
        cout<<index<<" ";
    }
    return 0;
}