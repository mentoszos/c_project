#include<bits/stdc++.h>
using namespace std;
int n,x=0,y=0;
char str[105][105];
char outstr[105][105];
vector<pair<int,int>> pos;
char yz[]="yizhong";
int step[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{0,-1},{1,-1},{1,0},{1,1}};
void toOutstr(){
    for(int i =0;i<sizeof(yz)-1;i++){
        int x =pos[i].first;
        int y = pos[i].second;
        outstr[x][y] = yz[i];
    }
}
void find_word(int deep,int xx,int yy){

    if(deep>sizeof(yz)-1) {
        //将pos的坐标对应输入到outstr；
        toOutstr();
        return;
    }
    for(int i=0;i<8;i++){
        xx += step[i][0];
        yy += step[i][1];
        deep++;
        if((xx>=0&&xx<n&&yy>=0&&yy<n)&&str[xx][yy] == yz[deep]){// go
            pos.push_back({xx,yy});
            find_word(deep,xx,yy);
            pos.pop_back();
        }
        deep--;
        xx -= step[i][0];
        yy -= step[i][1];
    }
    
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",&str[i]);
    }
    for(int i=0;i<105;i++){
        for(int j=0;j<105;j++){
            outstr[i][j] = '*';
        }
    }
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            if(str[i][j] == 'y')
                find_word(0,i,j);
        }
    }
      for(int i=0;i<n;i++){
        
    }
}