#include<iostream>
using namespace std;
int main(){
    int arr[8];
    int n = sizeof(arr)/sizeof(int);
    cout<<"输入数组";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for(int j = i; j>0;j--){
            if(arr[j]<arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            else break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    
    
    


}