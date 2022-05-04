<<<<<<< Updated upstream
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(){
    char chs[7] = "hello";
    for(int i =0;i<7;i++){
        if(chs[i]=='\0'){
            printf("hhhh");
        }
    }
    getchar();}
=======
#include<bits/stdc++.h>
using namespace std;
<<<<<<< Updated upstream
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
=======
bool a[11];
int cnt =0;
//vector<int> steps;
vector<int> ans;
void change(int x){
    a[x] = false;
    int index = x;
    while(x>0){
        if(index+1>10) index  = 1;//若当前index为10，转到1;
        else index+=1;
        //手指状态转换
        if(a[index]) a[index] =false;
        else a[index] = true;
        x--;//次数
    }
}
int main(){
   memset(a,false,sizeof(a));
   a[1]=true;
   while (1)
   {  int x;
      scanf("%d",&x);
      change(x);
      for (int i = 1; i <= 10; i++)
      {
         printf("%d",a[i]);
      }
      printf("\n");
      

   }
   
>>>>>>> Stashed changes
}
>>>>>>> Stashed changes
