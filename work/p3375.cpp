//没写完
#include<bits/stdc++.h>
using namespace std;

void makeNext(char* s1,int* next){
    int i=0,k=-1;
    next[0] =-1;
    while((i<strlen(s1)-1)){
        while(k>=0&&s1[i]!=s1[k]){i++;k++;}
        if(s1[i]==s1[k]) next[i] = next[k];
        else next[i] = k;
    }
}
int match(char* s1, char* s2,int* next){
    int i,j;
    while(i<strlen(s1)&&j<strlen(s2)){
        if(i ==-1||s1[i]==s2[i]){
            ++i;j++;
        }
        else i = next[i];
    }
    if(i>=strlen(s1)) return (j-strlen(s1)+1);
    else return 0;
}

int main(){
    char s1[200];
    char s2[200];
    int next[100];
    scanf("%s",s1);
    scanf("%s",s2);
    makeNext(s2,next);
    int ans = match(s2,s1,next);
    printf("%d",ans);

}