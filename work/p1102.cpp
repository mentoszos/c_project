#include<algorithm>
#include<cstdio>
using namespace std;

long long n,c,a[200005];
long long ans =0;
long long num;


void find_mid(){
    
    for(long long i=0;i<n-1;i++){
        num = a[i]+c;
        long long *begin = lower_bound(&a[i+1],&a[n-1]+1,num);
        while(*begin == num){
            long long *end = upper_bound(&a[i+1],&a[n-1]+1,num);
                ans += end - begin;
                break;
            }
        }printf("%lld",ans);
    }
    


int main(){
    scanf("%lld %lld",&n,&c);
    for (long long i = 0; i < n; i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    find_mid();
    
    
    
}