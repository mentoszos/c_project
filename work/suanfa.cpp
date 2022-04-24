#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
vector<int> ans;
vector<int> vec1;
//int arr[50];
void dfs(int cnt){
    if(cnt >=5){
        if(!vec.empty()){
            for(auto element:vec){
                vec1.push_back(element);
            }
        }
        int cnt=0;
        while(!vec1.empty()){
            ans.push_back(vec1.back());
            vec1.pop_back();
            ++cnt;
        }
        for(auto element:ans){
            printf("%d ",element);
        }
        printf("\n");
        for(int i=0;i<cnt;i++){
            ans.pop_back();
        }
        return ;
    }
    for(int i =0;i<2;i++){
        if(i==0){//压栈
        vec.push_back(cnt);
        cnt++;
        dfs(cnt);
        cnt--;
        vec.pop_back();
        }
        if(i == 1){//出栈
        if(vec.empty()) break;
        ans.push_back(vec.back());
        vec.pop_back();
        dfs(cnt);
        vec.push_back(ans.back());
        ans.pop_back();
        }
        
    }
}
int main(){
    vec.push_back(1);
    dfs(2);
}