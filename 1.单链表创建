#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
    int num;
    float score;
    struct student *pNext;
} ST;
void add(ST **phead,int inum,int iscore);
void showall(ST *head);
void add(ST **phead,int inum,int iscore)
{
    if(*phead==NULL)
    {
        ST *newnode =(ST *)malloc(sizeof(ST));
        if(newnode==NULL)
        {
            printf("内存分配失败");
            return;
        }
        newnode->num=inum;
        newnode->score=iscore;
        newnode->pNext=NULL;
        *phead=newnode;
    }
    else
    {
        ST *p=*phead;
        while(p->pNext!=NULL)
        p=p->pNext;
        ST *newnode =(ST *)malloc(sizeof(ST));
        if(newnode==NULL)
        {
            printf("内存分配失败");
            return ;
        }
        newnode->num=inum;
        newnode->score=iscore;
        newnode->pNext=NULL;
        p->pNext=newnode;
    }
}
void showall(ST *head)
{
    while(head)
    {
        printf("\nnum=%d,score=%f",head->num,head->score);
        printf("%p,%p",head,head->pNext);
        head=head->pNext;
    }
}
void main()
{
    struct student *head=NULL;
    add(&head,1,70);
    add(&head,2,80);
    add(&head,3,90);
    add(&head,4,100);
    add(&head,5,700);
    showall(head);
    system("pause");
    
}
