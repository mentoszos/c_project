#include<cstdio>
#include<algorithm>
using namespace std;
int a[25];
int s[4];
int mini;
int sum =0;
int left =0,right = 0;
void search_min(int x,int len){
    if(x>=len){
        mini = min(mini,max(left,right));
        return;
    }
    left+=a[x];
    search_min(x+1,len);
    left -= a[x];
    right += a[x];
    search_min(x+1,len);
    right -=a[x];
}
int main(){
    for(int i=0;i<4;i++){
        scanf("%d",&s[i]);
    }
    for(int i = 0;i<4;i++){
        for(int j = 0;j<s[i];j++){
            scanf("%d",&a[j]);
        }
        left = 0;
        right = 0;
        mini = 20000;
        search_min(0,s[i]);
        sum +=mini;
    }
    printf("%d",sum);
}