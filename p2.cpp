#include<iostream>
#include<algorithm>

using namespace std;
int n,m;
bool cmp(pair<int,int> n1,pair<int,int> n2){
    return n1.second<n2.second;
}
bool cmp1(pair<int,int> n1,pair<int,int> n2){
    return n1.first>n2.first;
}
void sort1(pair<int,int> arr[],int l,int r){
    int len = r-l+1;
    pair<int,int>a[len];
    for(int i =0;i<len;i++){
        a[i].first = arr[i+l].first;
        a[i].second = arr[i+l].second;
    }
    sort(a,a+len,cmp1);
    for(int i =0;i<len;i++){
        arr[i+l].first = a[i].first;
        arr[i+l].second = a[i].second;
    }

}
void sortFirst(pair<int,int> arr[],int l, int r){
    
    if(l>=r) return;
    int i=l ,j=l;
    while(j+1<r){
        if(arr[i].second == arr[j+1].second){
            j++;
        }
        
    }
     cout<<"here1";
    sort1(arr,i,j);
    
    sortFirst(arr,j+1,r);

}
 int main(){
     cin>>n;
     cin>>m;
     pair<int,int> arr[n];
     m = (int)m*1.5;
     for(int i =0;i<n;i++){
         cin>>arr[i].first;
         cin>>arr[i].second;
     }
     sort(arr,arr+n,cmp);
     int k = n-m ;
     while(k-1>=0){
         if(arr[k-1].second == arr[k].second) k--;
         else break;
     }


     cout<<"here2";
     cout<<arr[k].second<<" "<<n-k<<endl;
     
     sortFirst(arr,k,n-1);
    
     for(int i =n-1;i>=k;--i){
         cout<<arr[i].first<<" "<<arr[i].second<<endl;
     }
     return 0;
     
 }