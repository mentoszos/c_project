#include<bits/stdc++.h>
using namespace std;
int l,n,m; long long a[50005+2];


int main(){
    scanf("%d %d %d",&l,&n,&m);
    //输入数组
    for(int i =1;i<n+1;i++){
        scanf("%lld",&a[i]);
    }
    //数组长度+1，起点终点设置
    n=n+1;
    a[n] = l;
    a[0] = 0;
    //将每个元素设置为与前一个石头的距离
    for(int i = n-1;i>0;i--){
        a[i] = a[i]-a[i-1];
    }
    //循环m次，每次将最小的去除
    for(int i =0;i<m;i++){
        int min_index = min_element(a+1,a+n)-a;
        if(min_index!=n-1)
        {a[min_index+1] += a[min_index]; 
        a[min_index] = 1000000001;}
        else{
            a[min_index] += a[min_index-1];
            a[min_index-1] = 1000000001;
        }
    }
    int min_pace = *min_element(a+1,a+n);
    printf("%d",min_pace);

}