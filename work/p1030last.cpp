//已知中序前序序求后序
#include<bits/stdc++.h>
using namespace std;
char mid[20];
char pre[20];
void printPre(int l1,int r1,int l2,int r2){//先序中序的起点终点
    if(l1>r1) return;//遍历出界
    int i=l2;
    while(mid[i]!=pre[l1]) i++;//在中序中找根根
    printPre(l1+1,l1+i-l2,l2,i-1);//左遍历
    printPre(l1+i-l2+1,r1,i+1,r2);//右遍历
    printf("%c",pre[l1]);


}
int main(){
    scanf("%s",mid);
    scanf("%s",pre);
    printPre(0,sizeof(pre)-2,0,sizeof(mid)-2);
    return 0;
}