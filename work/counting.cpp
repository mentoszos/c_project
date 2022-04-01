#include<iostream>
using namespace std;
int getMax(int arr[],int len){
    int max = arr[0];
    
    for (int i = 1; i < len; i++)
    {
        if(max<arr[i]){
            max = arr[i];
        }
    }
    return max;
    
}
void countingSort(int arr[], int max,int len){
    int* a = new int[max+1];
    for(int i = 0; i<max+1; ++i){
        a[i] = 0;
    }
    for(int i = 0; i<len; ++i){
        a[arr[i]]++;
    }
    int j = 0;
    for(int i =0;i<max+1;i++){
        
        while(a[i]>0){
            arr[j] = i;
            j++;
            a[i]--;
        }
    }
}

int main(){
    int arr[]={1,5,7,2,4,8,9};
    int len = sizeof(arr)/sizeof(arr[0]);
    countingSort(arr,9,len);
    for (int i = 0; i < 7; i++)
    {
        /* code */cout<<arr[i]<<"\t";
    }
    
}