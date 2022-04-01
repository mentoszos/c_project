#include<iostream>
#include<cstring>
using namespace std;
int maxnum,n;
string str;
int main(){
    cin>>n;
    string max2;
    for(int i =0;i<n;i++){
        
        cin>>str;
        if(str.length()>max2.length()) {max2 = str;maxnum = i+1;}
        else if(str.length()<max2.length()) int j=0;
        else if(max2>=str)int j=0;
        else {max2 = str;maxnum = i+1;}
    }
    cout << maxnum << endl << max2 << endl;
    
}
