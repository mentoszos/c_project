#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,a[10005];
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    n = unique(a,a+n)-a;
    printf("%d\n",n);
    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
}