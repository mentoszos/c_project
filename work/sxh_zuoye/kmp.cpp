//最大公共子串
#include<bits/stdc++.h>
using namespace std;
void makeNext(int* nextt, char* t,int len){
    nextt[0]=-1;
    for(int i=1;i<len;i++){
        int lastt = nextt[i-1];
        while(lastt!=-1 && t[lastt+1]!=t[i]) lastt = nextt[lastt];
        if(t[lastt+1] == t[i]) lastt+=1;
        nextt[i] = lastt;
    }
}
int kmp(char*s,char* t,int lenS,int lenT,int* nextt){//找到一个匹配项则返回1，找不到返回0
    int j=-1;
    for(int i=0;i<lenS;i++){
        while(j!=-1 && t[j+1]!=s[i]) j =nextt[j];
        if(t[j+1] == s[i]) j++;
        if(j==lenT-1) return 1;
 
    }
    return 0;
}
//取i到j的子串,返回子串长度
int getSub(char* t,char* sub,int i,int j){
    int len = j-i+1;
    for(int k=0;k<=len-1;k++){
        sub[k] = t[i];
        i++;
    }
    sub[len]='\0';
    return len;
}
int main(){
    char s[100005];
    char t[100005];
    char sub[100005];
    char ans[100005];
    int nextt[100005];
    printf("输入两个字符串:\n");
    scanf("%s",s);
    scanf("%s",t);
    int lenS = strlen(s);
    int lenT = strlen(t);
    int i=0,j=0;
    int flag =0;//用于判断是否找到最大公共子串
    //从大到小寻找公共子串
    for(int k=lenT;k>0;k--){//取长度为k的子串进行匹配,
        i=0;
        j=k-1;
        while(j<=lenT-1){
            int lenSub = getSub(t,sub,i,j);
            makeNext(nextt,sub,lenSub);
            if(kmp(s,sub,lenS,lenSub,nextt)){
                printf("%s",sub);
                flag=1;
                break;
            }
            i++;
            j++;
        }
        if(flag==1) return 0;
    }
    //找不到
    printf("无公共子串");
    return 0;
    
    
}