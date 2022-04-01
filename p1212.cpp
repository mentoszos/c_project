#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int i = l;
    int j = mid + 1;
    int *a = new int[r - l + 1];
    for (int i = 0; i < r - l + 1; i++)
    {
        a[i] = arr[l + i];
    }

    for (int k = l; k <= r; k++)
    {
        if (i > mid)
        {
            arr[k] = a[j-l];
            j++;
        }
        else if (j > r)
        {
            arr[k] = a[i-l];
            i++;
        }
        else if (a[i-l] < a[j-l])
        {
            arr[k] = a[i-l];
            i++;
        }
        else
        {
            arr[k] = a[j-l];
            j++;
        }
    }
}

void sort(int arr[], int l, int r)
{
    if (l >= r)
        {return;}
    int mid = (l + r) / 2;
    sort(arr, l, mid);
    sort(arr, mid + 1, r);

    merge(arr, l, mid, r);
}

int main()
{
    int n;
    int m;
    int *arr = new int[m];
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }



    sort(arr, 0, m - 1);
    for (int i = 0; i < m; i++)
    {
        cout << arr[i]<<" ";
    }
}