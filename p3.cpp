#include<iostream>
using namespace std;

void merge(int a[], int l, int r){
    int n = r-l+1;
    int temp[n];
    int mid = (l+r)/2;
    int i= l;
    int j = mid+1;

    for(int i=0;i<n;i++){
        temp[i] = a[i+l];
    }
    for(int k = l;k<=r;k++){
        if(i>mid){
            a[k] = temp[j-l];
            j++;
        }
        else if(j>r){
            a[k] = temp[i-l];
            i++;
        }
        else if(temp[i-l]<temp[j-l]){
            a[k] = temp[i-l];
            i++;
        }
        else{
             a[k] = temp[j-l];
            j++;
        }

    }
    
}

void mergeSort(int a[],int l, int r){
    if(l>=r) return;
    int mid =(l+r)/2;
    mergeSort(a,l,mid);
    mergeSort(a,mid+1,r);

    if(a[mid]>a[mid+1]) merge(a,l,r);

}

int main(){
    int n;
    cin>>n;
    int min;
    cin>>min;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    mergeSort(a,0,n-1);
    cout<<a[min];
    
}