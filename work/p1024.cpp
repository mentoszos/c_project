#include<cstdio>
#include<algorithm>
using namespace std;

double a,b,c,d;
double ans[3];
int cnt=0;
//double left1 = -100.0, right1 = 100.0;

double cal_x1(double x){
    return a*x*x*x+b*x*x+c*x+d;
}

void find_x(){
    for(int i = -100;i<100;i++){
        double l = i;
        double r = i+1;
        double x1 = cal_x1(l);
        double x2 = cal_x1(r);
        if(!x1){
            printf("%.2lf ",l);
            ++cnt;
        }
        else if(x1*x2<0){
            while(r-l>=0.001){
                double mid = (l+r)/2;
                if(x1*cal_x1(mid)<0) r= mid;
                else l=mid;
            }
            printf("%.2lf ",l);
            ++cnt;
        }
        if(cnt==3) break;

    }
}
/*bool check_x1(double x,double y){
    if(cal_x1(x)*cal_x1(y)<=0) return true;
    else return false;
}*/
/*void find_x1(){
    double l = left1;
    double r = right1;
    while(i !=3 && r-l>=0.001){
        double mid = l+(r-l)/2;
        if(check_x1(mid,l) && cal_x1(l)!=0) r = mid-1; 
        else if(cal_x1(l) == 0){
            ans[i] = l;
            ++i;
        }else l = mid + 1;
    }
    ans[i] = l;
    ++i;
    
}*/


int main(){
    
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
    find_x();
    /*sort(ans,ans+3);
    for(int i =0;i<3;i++)
    printf("%.2lf ",ans[i]);*/
}