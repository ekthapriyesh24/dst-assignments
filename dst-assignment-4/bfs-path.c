/*In question bfs-cost, print the path instead of the cost. Print “NIL” if no path exists.
Sample Input

1

7 14

0 5

5 0

0 1

1 0

1 2

2 1

2 5

5 2

0 3

3 0

3 4

4 3

4 5

5 4

 

Sample Output

0

0 1

0 5 2

0 3

0 5 4

0 5

NIL*/
#include<stdio.h>
#include<stdlib.h>
#define ppd(x) printf("%d ",x)
#define pp(x) printf("%s\n",x)
#define scd(x) scanf("%d",&x)
#define sc(x) scanf("%s",x)
#define gph struct graph*
#define ls struct list*
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
lol front(lola* h)
{
    if((*h)->front==NULL)
    {
        return NULL;
    }
    else
    {
        return(((*h)->front));
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
struct graph
{
	int data;
	ls head;
	gph next;
};
struct list
{
	int data;
	ls next;
};
ls createNode(int x)
{
	ls n=(ls)(malloc(sizeof(struct list)));
	n->data=x;
	n->next=NULL;
	return n;
}
gph createGraph(int v)
{
	gph g=(gph)(malloc(sizeof(struct graph)));
	g->data=0;
	g->head=createNode(-1);
	g->next=NULL;
	gph y=g;
	for (int i=1;i<v;++i)
	{
		gph x=(gph)(malloc(sizeof(struct graph)));
		x->data=i;
		x->head=createNode(-1);
		x->next=NULL;
		y->next=x;
		y=y->next;		
	}
	return g;
}
void insertNode(ls* l,int e)
{
	ls x=(*l);
	while(x->next)
	{
		x=x->next;
	}
	x->next=createNode(e);
}
void insertVE(gph* g,int v,int e)
{
	gph x=(*g);
	while(x)
	{
		if (x->data==v)
		{
			insertNode(&(x->head),e);
			break;
		}
		x=x->next;
	}
}
void rec(int a[],int v)
{
    if(v==0)
    {
        ppd(0);
        return;
    }
    rec(a,a[v]);
    ppd(v);
}
void bfs(gph* g,int x,int v,int val)
{
	int ctr=0;
	lola q=createq();
	int visit[v];
	int dist[v];
	for(int i=0;i<v;i++)
	{
	    visit[i]=0;
	    dist[i]=0;
	}
	visit[x]=1;
	enqueue(&q,x);
	while(front(&q))
	{
		x=(front(&q))->data;
		dequeue(&q);
		gph g1=(*g);
		while(g1)
		{
			if (g1->data==x)
			{
				break;
			}
			g1=g1->next;
		}
		ls l1=g1->head;
		while(l1)
		{
		    if(l1->data==val)
		    {
		        ctr++;
		    }
			if (l1->data!=-1 && visit[l1->data]==0)
			{
				visit[l1->data]=1;
				dist[l1->data]=x;
				enqueue(&q,l1->data);
			}
			l1=l1->next;
		}
	}
	if(ctr || val==0)
	{
	    rec(dist,val);
	    pp("");
	}
	else
	{
	    pp("NIL\n");
	}
}
void printGraph(gph* g)
{
	gph t=(*g);
	while(t)
	{
		ls x=t->head;
		ppd(t->data);
		while(x)
		{
			if (x->data!=-1)
			{
			ppd(x->data);
			}
			x=x->next;
		}
		t=t->next;
		pp("");
	}
}
int main()
{
	int t,V,E,v,e;
	scd(t);
	while(t--)
	{
		scd(V);
		scd(E);
		gph g=createGraph(V);
		for (int i=0;i<E;++i)
		{
			scd(v);
			scd(e);
			insertVE(&g,v,e);
		}
		//printGraph(&g);
		for (int i=0;i<V;++i)
		{
			bfs(&g,0,V,i);
		}
	}
	return 0;
}

