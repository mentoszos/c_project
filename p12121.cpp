#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int m,n;
    cin>>n>>m;
    int* a = new int[m];
    for (int i = 0; i < m; i++)
    {
        cin>>a[i];
    }

    sort(a,a+m);
    for (int i = 0; i < m; i++)
    {
        cout<<a[i]<<" ";
    }

}