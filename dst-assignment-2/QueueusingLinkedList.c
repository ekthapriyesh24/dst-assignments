/*Queue using Linked List
SAMPLE INPUT
1
6
enqueue 1
enqueue 2
enqueue 3
dequeue
dequeue
front
SAMPLE OUTPUT
1
2
3*/
#include<stdio.h>
#include<stdlib.h>
#define ppd(x) printf("%d\n",x)
#define pp(x) printf("%s\n",x)
#define scd(x) scanf("%d",&x)
#define sc(x) scanf("%s",x)
#define lol struct s* 
#define lola struct s1* 
struct s
{
    int data;
    lol next;
};
struct s1
{
    lol front;
    lol rear;
};
lola createq()
{
    lola a=(lola)(malloc(sizeof(struct s1)));
    a->rear=NULL;
    a->front=NULL;
    return a;
}
lol create(int x)
{
    lol a=(lol)(malloc(sizeof(struct s)));
    a->data=x;
    a->next=NULL;
    return a;
}
void dequeue(lola* h)
{
    if((*h)->front==NULL)
    {
        pp("queue underflow");
    }
    else
    {
        ppd(((*h)->front)->data);
        (*h)->front=((*h)->front)->next;
        if((*h)->front==NULL)
        (*h)->rear=NULL;
    }
}
void front(lola* h)
{
    if((*h)->front==NULL)
    {
        pp("queue underflow");
    }
    else
    {
        ppd(((*h)->front)->data);
    }
}
void enqueue(lola* h,int x)
{
    lol temp=create(x);
    if((*h)->rear==NULL)
    {
        (*h)->rear=temp;
        (*h)->front=temp;
    }
    else
    {
        ((*h)->rear)->next=temp;
        (*h)->rear=temp;
    }
}
int main()
{
    int t,n,x;
    char ch[10];
    scd(t);
    while(t--)
    {
        scd(n);
        lola h=NULL;
        h=createq();
        for(int i=0;i<n;i++)
        {
            sc(ch);
            if(ch[0]=='e')
            {
                scd(x);
                enqueue(&h,x);
            }
            else if(ch[0]=='d')
            {
                dequeue(&h);
            }
            else
            {
                front(&h);
            }
            
        }
    }

