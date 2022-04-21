//求先序
#include<bits/stdc++.h>
using namespace std;
char mid[20];
char lastt[20];
void printlastt(int l1,int r1,int l2,int r2){//后序中序的起点终点
    if(l1>r1) return;//遍历出界
    int i=l2;
    while(mid[i]!=lastt[r1]) i++;//在中序中找根根
    printf("%c",lastt[r1]);
    printlastt(l1,l1+i-l2-1,l2,i-1);//左遍历
    printlastt(l1+i-l2,r1-1,i+1,r2);//右遍历
    


}
int main(){
    scanf("%s",mid);
    scanf("%s",lastt);
    printlastt(0,strlen(lastt)-1,0,strlen(mid)-1);

    return 0;
}