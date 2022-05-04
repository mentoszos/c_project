#include<bits/stdc++.h>
using namespace std;
struct markTable{
    int MAXNUM;
    int n;
    int* score;
    char* name;
};
//创建空成绩表
// m:最大人数
markTable* createTable(int m){
    markTable* table = (markTable*)malloc(sizeof(markTable));
    if(table != NULL){
        table->score = (int*)malloc(sizeof(int)*m);
        table->name = (char*)malloc(sizeof(char)*m);
        if(table->score !=NULL&&table->name!=NULL){
            table->MAXNUM = m;
            table->n = 0;
            printf("create successful\n");
            return table;
        }
    }
    else 
        free(table);
    printf("创建失败，重新启动程序");
    return NULL;
}
//在p前插入x
int insert_x(markTable* table, int p, char x,int mark){
    int q;
    if(table->n == table->MAXNUM){
        printf("overflow\n");
        return 0;
    }
    if(p<0||p>=table->n){
        printf("not exist\n");
        return 0;
    }
    for(q = table->n-1;q>=p;q--){//将p及之后学生往后挪一格
        table->name[q+1] = table->name[q];
        table->score[q+1] = table->score[q];
    }
    table->name[q] = x;
    table->score[q] = mark;
    table->n = table->n+1;

    printf("insert successful\n");
    return 1;
}

//查询学生x的序号
int inquire_x(markTable* table,char x){
    for(int i =0;i<table->n;i++){
        if(x == table->name[i]) 
            {
                printf("学生x的序号:%d\n",i);
                return 1;
            }
    }
    printf("查无此人\n");
    return 0;
}

//删除学生x
int del_x(markTable* table,char x){
    int p = inquire_x(table,x);//学生x的位置
    if(p ==-1){
        printf("x is not exist\n");
        return -1;
    }
    for(int i =p+1;i<=table->n-1;i++){
        table->score[i-1] = table->score[i];
        table->name[i-1] = table->name[i];
    }
    table->n = table->n-1;
    printf("delete successful\n");
    return 1;
}

//统计学生人数
int count_x(markTable* table){
    return table->n;
}
//平均分
double cal_ave(markTable* table){
    double ave=0;
    for(int i=0;i<table->n;i++){
        ave += table->score[i];
    }
    return ave/table->n;
}
//最高分
int find_max(markTable* table){
    int maxx = 0;//最高分学生下标
    for(int i=1;i<table->n;i++){
        if(table->score[maxx]<table->score[i]) 
            maxx = i;
    }
    return maxx;
}
//最低分
int find_min(markTable* table){
    int minn = 0;//最低分学生下标
    for(int i=1;i<table->n;i++){
        if(table->score[minn]>table->score[i]) 
            minn = i;
    }
    return minn;
}
//打印学生x的成绩
int print_x(markTable* table,char x){
   int p = inquire_x(table,x);
   if(p==-1){
       printf("no such student\n");
       return -1;
   }
   printf("%c:%d",table->name[p],table->score[p]);
   return 1;
}
//打印所有学生成绩
int print_all(markTable* table){
    for(int i=0;i<table->n;i++){
        printf("%c:%d\n",table->name[i],table->score[i]);
    }
    return 1;
}

int main(){
    int m;
    char x;
    int score;
    printf("输入成绩表最大容量:\n");
    scanf("%d",&m);
    markTable* table = createTable(m);
    printf("请先添加一名学生信息：(x 100)\n");
    scanf("\n%c %d",&x,&score);
    table->name[0] = x;
    table->score[0] = score;
    table->n = 1;
    int fun=0;
    while(true){
        printf("--------------选择你的操作:(输入功能序号)---------------\n");
        printf("1.在p位置前插入学生x\n");
        printf("2.查询学生x的序号\n");
        printf("3.删除学生x\n");
        printf("4.统计学生人数\n");
        printf("5.取平均分\n");
        printf("6.取最高分学生的信息\n");
        printf("7.取最低分学生的信息\n");
        printf("8.输出学生x的信息\n");
        printf("9.输出所有学生信息\n");
        
        scanf("%d",&fun);
        if(fun==1){
            int score,p;
            char x;
            printf("输入位置p，学生x，及成绩score:\n");
            scanf("%d %c %d",&p,&x,&score);
            insert_x(table,p,x,score);
        }
        if(fun==2){
            char x;
            printf("输入学生x:\n");
            scanf("\n%c",&x);
            inquire_x(table,x);
        }
        if(fun==3){
            printf("输入学生x:\n");
            char x;
            scanf("\n%c",&x);
            del_x(table,x);
        }
        if(fun==4){
            printf("学生总人数为%d\n",count_x(table));
        }
        if(fun==5){
            printf("学生的平均分为%.2lf\n",cal_ave(table));
        }
        if(fun==6){
            int maxx = find_max(table);
            printf("最高分学生的信息为:学生:%c,分数:%d",table->name[maxx],table->score[maxx]);
        }
        if(fun==7){
            int minn = find_min(table);
            printf("最低分学生的信息为:学生:%c,分数:%d",table->name[minn],table->score[minn]);
        }
        if(fun==8){
            printf("输入学生x:\n");
            char x;
            scanf("\n%c",&x);
            print_x(table,x);

        }
        if(fun==9){
            print_all(table);
        }
    }
    
}