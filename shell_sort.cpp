#include<iostream>
using namespace std;
int main(){
    int arr[8];
    cout<<"输入数组:";
    for (int i = 0; i < 8; i++)
    {
        /* code */cin>>arr[i];
    }
    
    int len = sizeof(arr)/sizeof(arr[0]);
    for (int gap = len/2; gap>0; gap/=2)
    {
        for (int i = gap; i < len; i++)
        {
            for(int j = i; j>=gap;j-=gap){
                if(arr[j]>arr[j-gap]){
                    int temp = arr[j];
                    arr[j] = arr[j-gap];
                    arr[j-gap] = temp;
                }
                else break;
                
            }
        }
        
    }
    for (int i = 0; i < 8; i++)
    {
        /* code */cout<<arr[i];
    }
    
}