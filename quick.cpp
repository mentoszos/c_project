#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int getP(int arr[], int l, int r){
    int i = l+1;
    int j = r;
    srand((int) time(0));
    int v = rand()%(r-l+1)+l;
    int temp = arr[v];
    arr[v] = arr[l];
    arr[l] = temp;
    
    
    while(true){
        while(i<=r&&arr[i]<arr[l] ){ 
        i++;
    }
    while(j>=1+l&&(arr[j]>=arr[l]))j--;
     if(i>j)  break;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    ++i;--j;
    
    }
     temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;
        return j;
}
void sort(int arr[], int l, int r ){
    if(l>=r) return;
    int p = getP(arr,l,r);
    sort(arr,l,p-1);
    sort(arr,p+1,r);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    sort(arr,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}