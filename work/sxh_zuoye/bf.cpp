//暴力最大子字符串
#include<bits/stdc++.h>
using namespace std;
int findSub(char* ans,char* s1,char* s2,int len1,int len2){//s2是否匹配s1；
    int i=0,j=0;
    for(int k =0;k<=len1-len2;k++){
        i=k;
        j=0;
        while(j<len2){
            if(s1[i] == s2[j]){
                ++i;
                ++j;
            }
        }
        if(j>=len2) return 1;
    }
    return 0;
}

int main(){
    char s1[200],s2[200];
    char ans[200];
    int len1,len2;
    int n = len2;
    printf("输入两个字符串:\n");
    scanf("%s",s1);
    scanf("%s",s2);
    len1 = strlen(s1);
    len2 = strlen(s2);
    
    
}