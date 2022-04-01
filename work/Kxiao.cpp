#include<cstdio>
using namespace std;

int a[5000000],k,n;
void swap(int left, int right){
    int temp = a[left];
    a[left] = a[right];
    a[right] = temp;
}

void qsort(int left, int right){
    int mid = a[(left+right)/2];
    int i =left;
    int j = right;
    while(i<=j){
        while( a[i]<mid) i++;
        while(a[j]>mid){ j--;}
        if(i<=j) {swap(i,j);++i;--j;}
    }

    if(k<=j) qsort(left,j);
    else if(k>=i) qsort(i,right);
    else {printf("%d",a[j+1]);
    return;}

}

int main(){
    scanf("%d %d",&n,&k);
    for(int i = 0; i<n;i++){
        scanf("%d",&a[i]);
    }
    qsort(0,n-1);
}