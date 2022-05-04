#include<bits/stdc++.h>
using namespace std;
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
void rechange(bool copyy[]){
    for(int i=1;i<=10;i++){
        a[i] = copyy[i];
    }
}

void dfs(int cnt){
    if(cnt==20) return;
    for(int i=1;i<=10;i++){//stop
        if(!a[i]) break;
        if(i==10){
            for(auto j:ans) printf("%d ",j);//print ans
            return;
        } 
    }
    vector<int> steps;
    for(int i=1;i<=10;i++){//可走手指输入
        if(a[i]) steps.push_back(i);
    }
    //copy current a;
    bool copyy[11];
    for(int i =1;i<=10;i++){
        copyy[i]=a[i];
    }
    for(auto step:steps){
        change(step);
        ans.push_back(step);
        cnt++;
        dfs(cnt);
        cnt--;
        ans.pop_back();
        rechange(copyy);
    }

    //while(!steps.empty()) steps.pop_back();//弹出
    
}
int main(){
    memset(a,false,sizeof(a));
    a[1] = true;
    dfs(1);
}