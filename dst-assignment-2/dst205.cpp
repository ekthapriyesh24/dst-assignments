#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ppd(x) printf("%d\n",x)
#define ppn(x) printf("%s\n",x)
#define pp(x) printf("%s ",x)
#define scd(x) scanf("%d",&x)
#define sc(x) scanf("%s",x)
#define lol struct qn* 
#define lola struct q*
struct qn
{
    char ch[20];
    int data;
    lol next;
};
struct q
{
    lol front;
    lol rear;
};
lola createq()
{
    lola a=(lola)(malloc(sizeof(struct q)));
    a->rear=NULL;
    a->front=NULL;
    return a;
}
lol create()
{
    lol a=(lol)(malloc(sizeof(struct qn)));
    sc(a->ch);
    scd(a->data);
    a->next=NULL;
    return a;
}
lol dequeue(lola* h)
{
    if((*h)->front==NULL)
    {
       return NULL;
    }
    else
    {
        lol temp=(*h)->front;
        (*h)->front=((*h)->front)->next;
        if((*h)->front==NULL)
        (*h)->rear=NULL;
        return temp;
    }
}
int front(lola* h)
{
    if((*h)->front==NULL)
    {
        return 0;
        pp("queue underflow");
    }
    else
    {
        return 1;
        ppd(((*h)->front)->data);
    }
}
void enqueue(lola* h)
{
    lol temp=create();
    if((*h)->front==NULL)
    {
        (*h)->rear=temp;
        (*h)->front=temp;
    }
    else
    {
        lol temp1=(*h)->front;
        lol prev=temp1;
        if(strcmp(temp->ch,((*h)->rear)->ch)>=0)
         {
          ((*h)->rear)->next=temp;
          (*h)->rear=temp;
         }
        else if(strcmp(temp->ch,(*h)->front)<0)
          {
              temp->next=(*h)->front;
            (*h)->front=temp;
          }
        else
          {
           while(strcmp(temp1->ch,temp->ch)<0 && temp1)
           {
               prev=temp1;
            temp1=temp1->next;
           }
          prev->next=temp;
          temp->next=temp1;
          }
    }  
}
void enqueue1(lola* h,lol temp)
{
    //lol temp=create(x);
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
void printq(lola* h)
{
    lol temp=(*h)->front;
    while(temp)
    {
        pp(temp->ch);
        ppd(temp->data);
        temp=temp->next;
    }
    
}
lol creates(int n,char ch[])
{
    lol a=(lol)(malloc(sizeof(struct qn)));
    a->data=n;
    strcpy(a->ch,ch);
    a->next=NULL;
    return a;
}
lol pop(lol* h)
{
    if(*h==NULL)
    {
        return NULL;
    }
    else
    {
        lol temp;
        temp=*h;
        //ppd((*h)->data);
        (*h)=(*h)->next;
        return (temp);
    }
}
int top(lol* h)
{
    if(*h==NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void push(lol* h,lol temp)
{
    //lol temp=create(x);
    temp->next=(*h);
    (*h)=temp;
}
lola sort(int d,lol* s,lola h)
{
    lola hn=createq();
    lola temp=h;
    while(front(&temp))
    {
        lol temp1=dequeue(&temp);
        if((temp1->data)>d && (temp1->data)<=(d+10))
        {
            push(s,temp1);
        }
        else
        {
            enqueue1(&hn,temp1);
        }
    }
    return hn;
}
int main()
{
    int t,n;
    scd(t);
    char ch[20];
    while(t--)
    {
        scd(n);
        lola h=NULL;
        lola hn=NULL;
        lol s=NULL;
        h=createq();
        for(int i=0;i<n;i++)
        {
            enqueue(&h);
        }
        int d=90;
        while(front(&h) && d>=-10)
        {
           h=sort(d,&s,h);
           d=d-10;
         //printq(&s);
        }
        while(top(&s))
        {
            lol temp=pop(&s);
            pp(temp->ch);
            ppd(temp->data);
        }
        //printq(&h);
    }
}
