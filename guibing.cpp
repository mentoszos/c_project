#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int *a = new int[r - l];
    int k = l;
    int i = l;
    int j = mid + 1;

    //复制局部数组
    for (int i = 0; i <= r - l; i++)
    {
        a[i] = arr[i + l];
    }

    while (k <= r)
    {
        if (i > mid)
        {
            arr[k] = a[j - l];
            ++j;
        }
        else if (j > r)
        {
            arr[k] = a[i - l];
            i++;
        }
        else if (a[i - l] < a[j - l])
        {
            arr[k] = a[i - l];
            i++;
        }
        else
        {
            arr[k] = a[j - l];
            j++;
        }
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
        return ;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    if (arr[mid] > arr[mid + 1])
        merge(arr, l, mid, r);
}

int main()
{
    /*int arr[9] = {3, 6, 2, 1, 8, 4, 8, 6, 7};
    mergeSort(arr, 0, 8);
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << "\t";
    }*/
    int n;
    int m;
    int *arr = new int[m];
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }



    mergeSort(arr, 0, m - 1);
    for (int i = 0; i < m; i++)
    {
        cout << arr[i];
    }
}


