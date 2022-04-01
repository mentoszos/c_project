#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string s1, string s2){
    return s1+s2>s2+s1;
}
int main(){
    int len;
    
    
    cin>>len;
    long long nums[len];
    string strs[len];
    string s = "";
    for(int i= 0;i<len;i++){
        cin >> nums[i];
        strs[i] = to_string(nums[i]);
    }
    
    sort(strs,strs+len,cmp);
     for(int i= len-1;i>0;i--){
        s+=strs[i];
    }
    cout<<s;





    
    


    return 0;
}