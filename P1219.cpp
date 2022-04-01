#include<cstdio>
#include<vector>

 
 bool lie[15];
 bool xie1[20];
 bool xie2[90];
 std::vector<int> vec;
 int ans = 0;
 int n;
void dfs(int x ){

    if(x>n){
        ans++;
        if(ans<=3){
            for(auto i:vec){
                printf("%d ",i);
            }
            printf("\n");
        }
        return;
    }

    for(int y=1;y<=n;y++){
            if(lie[y]) {continue;}
            if(xie1[x+y]) {continue;}
            if(xie2[x-y+n]) {continue;}
            lie[y] = true;
            xie1[x+y] = true;
            xie2[x-y+n] = true;
            vec.push_back(y);
            dfs(x+1);
            lie[y] = false;
            xie1[x+y] = false;
            xie2[x-y+n] = false;
            vec.pop_back();
        }
    
}

int main(){
    //scanf("%d",&n);
    n= 6;
    dfs(1);
    printf("%d",ans);
}