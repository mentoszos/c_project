#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> vec;
int count=0;
bool vis[100];
int num = 0;
int len = 0;
void swap(int* a,int* b ){
    int temp = *a;
    *a=*b;
    *b=temp;
}

bool isPrime(int count){
for(int i=2;i<=sqrt(count);i++){
  if(count%i==0){
   return false;
  }
 }
 return true;
}

void dfs(int count,int deep,int k){

     for(int i =0;i<len;i++){
         if(!vis[i]){
             count+=vec[i];
             vis[i] = true;
             deep++;
             if(deep==k&&isPrime(count)){
                 num++;
             }
             dfs(count,deep,k);
             vis[i] = false;
             count-=vec[i];
             deep--;
         }
     }

}

int main(){
    int n,k;
    cin>>n>>k;
    for(int i =0;i<n;++i){
        int t;
        cin>>t;
        vec.push_back(t);
    }
    len = n;
    count = vec[0];
   dfs(count,1,k);
    cout<<num;
    
}
