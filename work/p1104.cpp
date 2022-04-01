#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct stu
{
    string name;
    int year;
    int month;
    int day;
    int num;
};
stu stus[105];
int n;
bool cmp(stu a,stu b){
   if(a.year<b.year) return 1;
    else if(a.year>b.year) return 0;
    else{
        if (a.month<b.month) return 1;
        else if(a.month>b.month) return 0;
        else{
            if(a.day<b.day) return 1;
            else if(a.day>b.day) return 0;
            else{
                return a.num>b.num;
            }
        }
        
    }
    /*if(a.year != b.year)
	return a.year < b.year;//如果出生年份不相等便直接按照年份进行排序
	else{
	if(a.month != b.month) return a.month < b.month;//年份相等月份不相等
	else if(a.day == b.day && a.month == b.month) return a.num > b.;//同年同月同日生 便把后输入的排在前面
	else if(a.day != b.day && a.month == b.month) return a.day < b.day;//同年同月不同日
	}*/
}
int main(){
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>stus[i].name;
        scanf("%d %d %d",&stus[i].year,&stus[i].month,&stus[i].day);
        stus[i].num = i;
    }
    sort(stus,stus+n,cmp);
    for(int i =0;i<n;i++){
        cout<<stus[i].name<<endl;
         
    }
    
}
