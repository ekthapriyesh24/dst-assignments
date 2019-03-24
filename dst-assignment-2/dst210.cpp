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
void print(lol* temp)
{
    if(top(temp))
    {
        pp(pop(temp)->ch);
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
int check(lola* p,int x)
{
    lola temp=*p;
    int c=0;
    while(x--)
    {
        if(temp->head==NULL)
        {
            c++;
        }
        temp=temp->next;
    }
    return c;
}
void roundq(lola* p,int x)
{
    int i=x;
    lola tt=*(p);
    char ch[20]="zzzzzzzzzzzzzzzzzzz";
   // lola tt1=tt;
    lol* x1=&(tt->head);
    while(i--)
    {
        if(tt->head==NULL)
        {
            tt=tt->next;
        }
        else
        {
            int diff=strcmp((tt->head)->ch,ch);
            if(diff<0)
            {
                strcpy(ch,(tt->head)->ch);
                x1=&(tt->head);
            }
            tt=tt->next;
        }
    }
    print(x1);
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
        while(1)
        {
            if(check(&hn,x)==x)
            break;
            roundq(&hn,x);
        }
    }
}
