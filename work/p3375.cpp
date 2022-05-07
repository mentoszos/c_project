
#include<bits/stdc++.h>
using namespace std;
char s[1000005];
char t[1000005];
int nextt[1000005];
void makeNext(int* nextt, char* t,int len){
    nextt[0]=-1;
    for(int i=1;i<len;i++){
        int lastt = nextt[i-1];
        while(lastt!=-1 && t[lastt+1]!=t[i]) lastt = nextt[lastt];
        if(t[lastt+1] == t[i]) lastt+=1;
        nextt[i] = lastt;
    }
}
void kmp(char*s,char* t,int lenS,int lenT,int* nextt){
    int j=-1;
    for(int i=0;i<lenS;i++){
        while(j!=-1 && t[j+1]!=s[i]) j =nextt[j];
        if(t[j+1] == s[i]) j++;
        if(j==lenT-1) printf("%d\n",i-lenT+1);
    }
}
int main(){
    scanf("%s",s);
    scanf("%s",t);
    makeNext(nextt,t,strlen(t));
    kmp(s,t,strlen(s),strlen(t),nextt);
   /* for(int i=0;i<strlen(t);i++){
        printf("%d ",nextt[i]+1);
    }*/
}
