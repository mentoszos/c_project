#include<bits/stdc++.h>
using namespace std;
int n;
char inn[105][105],outt[105][150];
//bool vis[105][105];
char yz[]="yizhong";
int step[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{0,-1},{1,-1},{1,0},{1,1}};
vector<pair<int,int>> pos;

void updateOut(){
    int len = pos.size();
    for(int i=0;i<=6;++i){
        int x = pos[i].first;
        int y = pos[i].second;
        outt[x][y] = yz[i];
    }
}
void find_words(int deep,int xx, int yy,int dic){
    if(deep == 6){
        //update outt
        updateOut();
        return;
    }
    //deep为0，确定方向
    if(deep ==0){
        for(int i=0;i<8;i++){
            xx += step[i][0];
            yy += step[i][1];
            deep++;
            if((xx>=0&&xx<n&&yy>=0&&yy<n) && inn[xx][yy]==yz[deep])
                //不越界，可走
                {
                pos.push_back({xx,yy});
                find_words(deep,xx,yy,i);
                pos.pop_back();
                
                }
            xx -= step[i][0];
            yy -= step[i][1];
            deep--;
            
        }
    }
    else{//deep不为0，即已确定方向i
        xx += step[dic][0];
        yy += step[dic][1];
        
        if((xx>=0&&xx<n&&yy>=0&&yy<n) && inn[xx][yy]==yz[deep+1])
                //不越界，可走
                {deep++;
                pos.push_back({xx,yy});
                find_words(deep,xx,yy,dic);
                pos.pop_back();
                deep--;}
        xx -= step[dic][0];
        yy -= step[dic][1];
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",&inn[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            outt[i][j]='*';
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(inn[i][j] == 'y'){
                pos.push_back({i,j});
                find_words(0,i,j,0);
                pos.pop_back();
            }
        }
    }
    //输出
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%c",outt[i][j]);
        }
        printf("\n");
    }
    return 0;
}