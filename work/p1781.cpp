#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n;

struct s{
    string str;
    int num;
};
s a[25];
bool cmp(s a, s b){
    if(a.str.length>b.str.length) return 1;
    else if(a.str.length < b.str.length) return 0;
    else{
        return a.str>b.str;
    }
}
int mainm(){
    scanf("%d",&n);
    int count = n;
    for (int i = 0; i < count; i++)
    {
        getline(cin,a[i].str,'');
        a[i].num = i+1;
    }
    sort(a,a+n,cmp);
    cout<<a[0].num<<endl<<a[0];
    
}