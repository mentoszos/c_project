#include<iostream>
using namespace std;
int main(){

}

void merge(int arr[], int l, int mid, int r ){
    int* a = new int[r-l];
    int i =l;
    int j = mid+1;
    for (int k = l; k <= r; k++)
    {
        if (i>mid)
        {
            arr[k] = a[i-l];
        }
        else if (j>r)
        {
            arr[k] = a[j-l];
        }
        else if (a[i-l]<a[j-l])
        {
            arr[k] = a[i-l];
        }
        else arr[k] = a[j-l];
    }

}

void sort(int arr[],int l,int r){
        if (l>=r)
        {
            return;
        }
        int mid = (l+r)/2;
        sort(arr,l,mid);
        sort(arr,mid+1,r);
        if (arr[mid]>arr[mid+1])
        {
            merge(arr,l,mid,r);
        }
        
    }