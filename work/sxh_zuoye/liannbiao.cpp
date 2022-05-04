#include <bits/stdc++.h>
using namespace std;
struct Llist
{
    int n;
    int score;
    int num;
    char *name;
    Llist* link;
};
typedef Llist Node;
//创建空链表
Llist* createEmptyList()
{
    Llist *llist = (Llist *)malloc(sizeof(struct Llist));
    if (llist != NULL)
    {
        llist->n = 0;
        llist->link = NULL;
        llist->name = (char *)malloc(sizeof(char) * 50);
        printf("创建成功\n");
    }
    else
        printf("创建失败\n");
    return llist;
}
//创建学生结点
Node* createStu(char* name,int score,int num){
    Node* node = (Node*)malloc(sizeof(Node));
    if(node != NULL){
        node->link = NULL;
        node->score = score;
        node->num = num;
        node->name = (char*)malloc(sizeof(name));
        strcpy(node->name,name);
    }
    return node;

}

//在末尾添加一名学生x
int addOne(Llist* llist,char* name,int score,int num){
    if(llist ==NULL){
        printf("请先创建空链表\n");
        return 0;
    }
    Node* node = createStu(name,score,num);
    Node* p1 = llist;
    while(p1->link!=NULL)
        p1 = p1->link;
    p1->link = node;
    llist->n++;
    printf("添加成功\n");
    return 1;

}
//在学生p后插入学生name
int insertX(Llist *llist, char* p, char* name,int score,int num)
{
    Node* p1;
    Node* x = createStu(name,score,num);
    if(x == NULL){
        printf("创建学生失败\n");
        return 0;
    }
    if(llist ==NULL)
        {printf("请先创建链表\n");
        return 0;}
     if(llist->n==0)
        {printf("请先添加学生\n");
        return 0;}
    p1 = llist->link; // p1指向第一个结点
    while (p1 != NULL && strcmp(p1->name,p)!=0)
        p1 = p1->link;
    if (p1 != NULL)
    { //插入
        x->link = p1->link;
        p1->link = x;
        printf("插入成功\n");
        llist->n+=1;
        return 1;
    }
     printf("插入失败\n");
    return 0;
}
//查询学生x的学号
int numOfx(Llist *llist, char *name)
{
    if(llist ==NULL)
        {printf("请先创建链表\n");
        return 0;}
     if(llist->n==0)
        {printf("请先添加学生\n");
        return 0;}
    Node *p1 = llist->link;
    while (p1 != NULL && strcmp(p1->name, name) != 0)
        p1 = p1->link;
    if (p1 == NULL)
    {
        printf("未找到该学生\n");
        return 0;
    } //未找到该学生
    else
        printf("%s的学号为:%d\n",p1->name,p1->num);
        return p1->num;
}

//删除学生x
int delX(Llist* llist,char* name){
    if(llist ==NULL)
        {printf("请先创建链表\n");
        return 0;}
     if(llist->n==0)
        {printf("请先添加学生\n");
        return 0;}
    Node *p1 = llist;
    while (p1->link != NULL && strcmp(p1->link->name, name) != 0)
        p1 = p1->link;
    if(p1->link !=NULL){
        Node* p2 = p1->link;
        p1->link = p1->link->link;
        free(p2);
        llist->n = llist->n-1;
        printf("删除成功\n");
        return 1;//删除成功
    }
    else{
        printf("没有该学生\n");
        return 0;//删除失败
    }
}
//统计学生人数
int countX(Llist* llist){
    if(llist ==NULL)
        {printf("请先创建链表\n");
        return 0;}
    printf("学生人数为%d\n",llist->n);
    return llist->n;
}
//平均分
double calAve(Llist* llist){
    if(llist ==NULL)
        {printf("请先创建链表\n");
        return 0;}
     if(llist->n==0)
        {printf("请先添加学生\n");
        return 0;}
    double ave = 0.0;
    Node* node = llist->link;
    while(node!=NULL){
        ave += node->score;
        node = node->link;
    }
    printf("平均分为%.2lf\n",ave/llist->n);
    return ave/llist->n;
}
//最高分
int findMax(Llist* llist){
    if(llist ==NULL)
        {printf("请先创建链表\n");
        return 0;}
     if(llist->n==0)
        {printf("请先添加学生\n");
        return 0;}
    Node* maxNode = llist->link;
    Node* node = llist->link;
    while(node!=NULL){
        if(maxNode->score < node->score)
            maxNode = node;
        node = node->link;
    }
    printf("学生%s的分数最高:%d\n",maxNode->name,maxNode->score);
    return maxNode->score;
}
//最低分
int findMin(Llist* llist){
    if(llist ==NULL)
        {printf("请先创建链表\n");
        return 0;}
     if(llist->n==0)
        {printf("请先添加学生\n");
        return 0;}
    Node* minNode = llist->link;
    Node* node = llist->link;
    while(node!=NULL){
        if(minNode->score > node->score)
            minNode = node;
        node = node->link;
    }
    printf("学生%s的分数最低:%d\n",minNode->name,minNode->score);
    return minNode->score;
}
//打印学生name的成绩
int printOne(Llist* llist,char* name){
    if(llist ==NULL)
        {printf("请先创建链表\n");
        return 0;}
     if(llist->n==0)
        {printf("请先添加学生\n");
        return 0;}
    Node *p1 = llist->link;
    while (p1 != NULL && strcmp(p1->name, name) != 0)
        p1 = p1->link;
    if(p1!=NULL){
        printf("%s的成绩为:%d\n",p1->name,p1->score);
        return 1;
    }
    else{
        printf("查无此人\n");
        return 0;
    }
}
//打印所有学生成绩
int printAll(Llist* llist){
    if(llist ==NULL)
        {printf("请先创建链表\n");
        return 0;}
     if(llist->n==0)
        {printf("请先添加学生\n");
        return 0;}
    Node *p1 = llist->link;
    while(p1!=NULL){
        printf("%s的成绩为%d\n",p1->name,p1->score);
        p1 = p1->link;
    }
    return 1;
}

int main(){
    int fun;
    int flag=0;
    Llist* llist;
     while(true){
        printf("--------------选择你的操作:(输入功能序号)---------------\n");
        printf("0.创建空链表\n");
        printf("1.在学生p后插入学生x\n");
        printf("2.查询学生x的序号\n");
        printf("3.删除学生x\n");
        printf("4.统计学生人数\n");
        printf("5.取平均分\n");
        printf("6.取最高分学生的信息\n");
        printf("7.取最低分学生的信息\n");
        printf("8.输出学生x的信息\n");
        printf("9.输出所有学生信息\n");
        printf("10.在末尾添加一名学生:\n");
        scanf("%d",&fun);
        if(fun ==10){
            char name[50];
            int num;
            int score;
            printf("输入该学生的姓名学号及成绩(zhangsan 15 100):\n");
            scanf("%s",name);
            scanf("%d %d",&num,&score);
            addOne(llist,name,score,num);
        }
        if(fun ==0){
            if(flag==1){
                printf("已存在链表\n");
            }
            else
                {llist = createEmptyList();
                flag =1;}
        }
        if(fun==1){
            char p[50];
            char x[50];
            int num;
            int score;
            printf("学生p，学生x，及其成绩和学号:\n");
            scanf("%s %s %d %d",p,x,&score,&num);
            insertX(llist,p,x,score,num);
        }
        if(fun==2){
            char x[50];
            printf("输入学生x(name):\n");
            scanf("%s",x);
            numOfx(llist,x);
            
        }
        if(fun==3){
            printf("输入学生x:\n");
            char x[50];
            scanf("%s",x);
            delX(llist,x);
        }
        if(fun==4){
            countX(llist);
        }
        if(fun==5){
            calAve(llist);
        }
        if(fun==6){
            findMax(llist);
        }
        if(fun==7){
           findMin(llist);
        }
        if(fun==8){
            printf("输入学生x(name):\n");
            char x[50];
            scanf("%s",x);
            printOne(llist,x);

        }
        if(fun==9){
            printAll(llist);
        }
        getchar();
        getchar();
    
    }
    
}
