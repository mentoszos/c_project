#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
stack<int> sta;
void dfs(int cnt){
    if(cnt>=5){
        while(!sta.empty()){
            vec.push_back(sta.top());
            sta.pop();
        }
        for(auto temp:vec){
            printf("%d ",temp);
        }
        printf("\n");
        return;
    }

    for(int i=0;i<2;i++){
        if(i==0){//压栈
            sta.push(cnt);
            cnt++;
            dfs(cnt);
            cnt--;
            sta.pop();
        }
        if(i==1){//弹栈
            if(sta.empty()) break;
            vec.push_back(sta.top());
            sta.pop();
            dfs(cnt);
            sta.push(vec.back());
            vec.pop_back();
        }
    }
}
int main(){
    sta.push(1);
    dfs(2);

    
}