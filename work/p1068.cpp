#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,mark,count1=0;
struct stu
{
    int mark;
    int num;
};
stu a[5005];

bool cmpmark(stu a, stu b){
    return a.mark>b.mark;
}
bool cmpnum(stu a, stu b){
    return a.num<b.num;
}
void subsort(){
    int begin=0;
    while(begin<=count1){
        int point = begin;
        while(point<=count1 && a[point].mark == a[begin].mark)   point++;
        sort(&a[begin],&a[point-1]+1,cmpnum);
        begin = point;
    }
    
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i =0;i<n;i++){
        scanf("%d %d",&a[i].num,&a[i].mark);
    }
    sort(a,a+n,cmpmark);
    
    count1=(int)(m*1.5)-1;
    mark = a[count1].mark;
    while(a[count1+1].mark == mark)
        count1++;
    printf("%d %d\n",mark,count1+1);
    subsort();
    for(int i =0;i<=count1;i++){
         printf("%d %d\n",a[i].num,a[i].mark);
    }
    

}
