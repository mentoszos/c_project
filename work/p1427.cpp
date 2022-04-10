#include<cstdio>
using namespace std;
long long a[105];
int cnt;
int main(){
    for(int i =0;i<105;i++){
        scanf("%lld",&a[i]);
        if(a[i]==0) break;
    }
    for(int i =0;i<105;i++){
        if(a[i]!=0) cnt =i;
        else break;
    }
    for(int i=cnt;i>=0;i--){
        printf("%lld ",a[i]);
    }
}