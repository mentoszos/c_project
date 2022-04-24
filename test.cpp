#include<bits/stdc++.h>
using namespace std;
int fun1(char str[],int index,int n){ // index:字符串最后一个字符下标；n：当前数字是x位数。
   if(index <0) return 0;
   int temp = str[index]-48;//字符转数字
   for(int i =0;i<n;i++){
      temp*=10;
   }
   return temp+fun1(str,index-1,n+1);
}
int main(){
   char str[100];
   scanf("%s",str);
   int i=0;
   for(;i<100;i++){
      if(str[i]=='\0') break;
   }
 printf("%d",fun1(str,i-1,0));
}