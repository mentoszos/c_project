#include<cstdio>
#include<algorithm>
using namespace std;
struct stu
{
    int sum;
    int chi;
    int num;
};
stu stus[305];
int n;
bool cmpsum(stu a,stu b){
    return a.sum>b.sum;
}
bool cmpchi(stu a,stu b){
    return a.chi>b.chi;
}
bool cmpnum(stu a,stu b){
    return a.num<b.num;
}
void subsort(){
    int begin = 0;
    int i;
    while(begin<5){
        i=begin;
        while(i+1<5 && stus[i+1].sum == stus[i].sum) ++i;
        sort(stus+begin,stus+i+1,cmpchi);
        begin = i+1;
    }
    begin =0;
    while(begin<5){
        i=begin;
        while(i+1<5 &&stus[i+1].sum == stus[i].sum &&stus[i+1].chi == stus[i].chi) ++i;
        sort(stus+begin,stus+i+1,cmpnum);
        begin = i+1;
    }
}

int main(){
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        int math,eng;
        scanf("%d %d %d",&stus[i].chi,&math,&eng);
        stus[i].sum = stus[i].chi+math+eng;
        stus[i].num =i+1;
    }
    sort(stus,stus+n,cmpsum);
    subsort();
    for(int i =0;i<5;i++){
        printf("%d %d\n",stus[i].num,stus[i].sum);
    }
}
