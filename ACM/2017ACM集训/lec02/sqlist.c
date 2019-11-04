/*单链表1.1*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
typedef int elemtype;
typedef struct lnode
{//单链表存储结构
    struct lnode *next;
    elemtype data ;
} lnode;
lnode *newlist(int n)
{//创建一个单链表
    lnode *L;
L=(lnode*)malloc(sizeof(lnode));
if(L==NULL)printf("没有分配内存！\n");
int i; lnode *p,*s;s=L;
    for(i=1;i<=n;i++)
    { printf("请输入第%d个元素： ",i);
    p=(lnode *)malloc(sizeof(lnode));if(p==NULL)printf("没有分配内存！\n");
        scanf("%d",&p->data);
        s->next=p;
        s=p;
    }p->next=NULL;
    return L;
}
int getelem(lnode *L,int i)
{//单链表的取值
    lnode *p;
    p=L;int j=1;
    while(p&&j<=i)
    {
        p=p->next;
        ++j;
    }
    if(p==NULL)
        return ERROR;

     return p->data;
}

void putinlist(lnode *L,int i,elemtype e)
{//单链表：在第i个元素插入e
    lnode *p,*s;
   s=(lnode *)malloc(sizeof(lnode));
    int j=1;p=L;
    while(p&&j<i){
        j++;
        p=p->next;
    }
    s->data=e;
    s->next=p->next;
    p->next=s;
}
int  foundlist(lnode *L,elemtype e)
{//单链表的查询
    lnode *p;
   p=L;int j;
     while(p){if(j==e)
                 return p->data;
                 p=p->next;++j;
                 }
                    return ERROR;
}
void dellist(lnode*L,int i)
{//删除第i个元素
lnode *p;
p=L;int j=1;
while(p&&j<i){p=p->next;j++;}
p->next=p->next->next;
}
int main()
{
    lnode *L;
    int n;
    printf("请输入单链表的长度为：");
    scanf("%d",&n);
    L=newlist(n);//创建链表
    int sum=n;
    int i;
    printf("单链表元素为：");
    for(i=1;i<=n;i++)
    {
               elemtype e=getelem(L,i);if(e)
                    printf("%d ",e);
                    else printf("NO have!\n");
    }
    printf("\n");
    printf("请输入需要查询的元素：");
    elemtype x;
    scanf("%d",&x);elemtype data=foundlist(L,x);
    if(data)printf("第%d个元素为：%d\n",x,data);
    else printf(" NO FOUND!!\n");
    printf("请输入插入的位置及元素：");
    int m;
    scanf("%d%d",&m,&x);
    putinlist(L,m,x);n;
    printf("插入后单链表元素为：");
    for(i=1;i<=n+1;i++)
    {
               elemtype e=getelem(L,i);if(e)
                    printf("%d ",e);
                    else printf("NO have!\n");
    }
    printf("\n");
    printf("删除第%d个元素！\n",m);
    dellist(L,m);
    printf("单链表元素为：");
    for(i=1;i<=n;i++)
    {
               elemtype e=getelem(L,i);if(e)
                    printf("%d ",e);
                    else printf("NO have!\n");
    }
    printf("\n");



    return 0;
}
//@auther LLZ 