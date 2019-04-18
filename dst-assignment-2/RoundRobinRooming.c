/*In the rooming question, the TA instead sends all students to classrooms in a circular manner. The first student entering goes to the first classroom, the second student entering goes to the second classroom and so on. There are k classrooms with infinite capacity. Implement using a circular linked list of stacks.
SAMPLE INPUT
1
10 3
IIT2018001
IIT2018002
IIT2018003
IIT2018004
IIT2018005
IIT2018006
IIT2018007
IIT2018008
IIT2018009
IIT2018010
SAMPLE OUTPUT
IIT2018001
IIT2018004
IIT2018007
IIT2018010
IIT2018003
IIT2018006
IIT2018009
IIT2018002
IIT2018005
IIT2018008*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ppd(x) printf("%d\n",x)
#define pp(x) printf("%s\n",x)
#define scd(x) scanf("%d",&x)
#define sc(x) scanf("%s",x)
#define lol struct s*
#define lola struct h* 
struct s
{
    char ch[20];
    lol next;
};
struct h
{
    lol head;
    lola next;
};
lol create()
{
    char ch[20];
    lol a=(lol)(malloc(sizeof(struct s)));
    sc(ch);
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
        (*h)=(*h)->next;
        return (temp);
    }
}
lol top(lol* h)
{
    if(*h==NULL)
    {
        return NULL;
    }
    else
    {
       return (*h);
    }
}
void push(lol* h)
{
    lol temp=create();
    temp->next=(*h);
    (*h)=temp;
}
void push1(lol* h,lol temp)
{
    temp->next=(*h);
    (*h)=temp;
}
void insert1(lola* head,lola* prev,lol ts)
{
    lola temp;
    if(*prev==NULL)
    {
        *prev=*head;
        temp=*(prev);
        push1(&(temp->head),ts);
    }
    else
    {
      temp=(*prev)->next;
      push1(&(temp->head),ts);
      *prev=(*prev)->next;
    }
}
void print(lol temp)
{
    while(top(&temp))
    {
        pp(pop(&temp)->ch);
    }
}
void init(lola* head,int k)
{
    int i=0;
    lola p;
    p=*head;
    while(i<k)
    {
    lola temp=(lola)(malloc(sizeof(struct h)));
    temp->head=NULL;
    temp->next=NULL;
    if((*head)==NULL)
    {
      (*head)=temp;
      p=(*head);
    }
    else
    {
      p->next=temp;
      p=p->next;
    }
    i++;
    }
    p->next=(*head);
}
int main()
{
    int t,n,x;
    char ch[20];
    scd(t);
    while(t--)
    {
        scd(n);
        scd(x);
        lol h=NULL;
        lola hn=NULL;
        lola prev=NULL;
        for(int i=0;i<n;i++)
        {
            push(&h);
        }
        init(&hn,x);
        while(top(&h))
        {
            lol temp=pop(&h);
            insert1(&hn,&prev,temp);
        }
        lola tt=hn;
        int j=0;
        while(j<x)
        {
            print(tt->head);
            tt=tt->next;
            j++;
        }
    }
}
