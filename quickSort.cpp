#include<iostream>
using namespace std;

int getPositition(int arr[], int l,int r){
    int i =l+1;
    int j = r;

    //srand((int)time(NULL));
   // int guard = rand()*(r-l+1)+l;
    while (true)
    {
       while (i<=r && arr[i] < arr[l])
       {
           i++;
       }
       while (j>=l+1 && arr[j]>arr[l])
       {
           j--;
       }
    
    
        if (i>j)
        {
            break;
        }
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        ++i;--j;
   }
         int temp = arr[j];
        arr[j] = arr[l];
        arr[l] = temp;
        return j;
       
    }
void quickSort(int arr[],int l, int r){
    if(l>=r) return;
    int positition = getPositition(arr,l,r);
    quickSort(arr,l,positition-1);
    quickSort(arr, positition+1,r);
}
    
int main(){
    int arr[9] = {3, 6, 2, 1, 8, 4, 8, 6, 7};
    for (int i = 0; i < 9; i++)
    {
        cout<< arr[i]<<"\t";
    }
    cout<<endl;
    quickSort(arr, 0, 8);
    for (int i = 0; i < 9; i++)
    {
        cout<< arr[i]<<"\t";
    }
    
}
