/*queue using arrays
SAMPLE INPUT
1
6 2
enqueue 1
enqueue 2
enqueue 3
dequeue
dequeue
front
SAMPLE OUTPUT
queue overflow
1
2
queue underflow*/
#include<stdio.h>
#include<stdlib.h>
#define ppd(x) printf("%d\n",x)
#define pp(x) printf("%s\n",x)
#define scd(x) scanf("%d",&x)
#define sc(x) scanf("%s",x)
#define lol struct s* 
struct s
{
    int start;
    int rear;
    int size; 
    int capacity;
    int *data;
};
lol create(int n)
{
    lol a=(lol)(malloc(sizeof(struct s)));
    a->start=0;
    a->size=0;
    a->rear=n-1;
    a->data=(int*)(malloc(sizeof(int)*n));
    a->capacity=n;
    return a;
}
void dequeue(lol h)
{
    if(h->size==0)
    {
        pp("queue underflow");
    }
    else
    {
        int z=(h->data)[(h->start)];
        h->start=(h->start+1)%(h->capacity);
        ppd(z);
        (h->size)--;
    }
}
void front(lol h)
{
    if(h->size==0)
    {
        pp("queue underflow");
    }
    else
    {
        ppd((h->data)[(h->start)]);
    }
}
void enqueue(lol h,int x)
{
    if(h->size==(h->capacity))
    {
        pp("queue overflow");
    }
    else
    {
        h->rear=(h->rear+1)%(h->capacity);
        (h->data)[(h->rear)]=x;
        (h->size)++;
    }
}
int main()
{
    int t,n,k,x;
    char ch[10];
    scd(t);
    while(t--)
    {
        scd(n);
        scd(k);
        lol h=create(k);
        for(int i=0;i<n;i++)
        {
            sc(ch);
            //pp(ch); 
            if(ch[0]=='e')
            {
                scd(x);
                enqueue(h,x);
            }
            else if(ch[0]=='d')
            {
                dequeue(h);
            }
            else
            {
                front(h);
            }
            //ppd((h->data)[h->top]);
        }
    }
}
