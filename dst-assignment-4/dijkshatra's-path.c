/*In question dijkshatra's cost print the path instead of the cost. Print “NIL” if no path exists.

 

Sample Input

1

7 14

0 5 12

5 0 12

0 1 6

1 0 6

1 2 1

2 1 1

2 5 3

5 2 3

0 3 7

3 0 7

3 4 1

4 3 1

4 5 1

5 4 1

 

Sample Output

0

0 1

0 1 2

0 3

0 3 4

0 3 4 5

NIL*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define ppd(x) printf("%d\n",x)
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
	int weight;
	int data;
	ls next;
};
ls createNode(int x,int w)
{
	ls n=(ls)(malloc(sizeof(struct list)));
	n->data=x;
	n->weight=w;
	n->next=NULL;
	return n;
}
gph createGraph(int v)
{
	gph g=(gph)(malloc(sizeof(struct graph)));
	g->data=0;
	g->head=createNode(-1,-1);
	g->next=NULL;
	gph y=g;
	for (int i=1;i<v;++i)
	{
		gph x=(gph)(malloc(sizeof(struct graph)));
		x->data=i;
		x->head=createNode(-1,-1);
		x->next=NULL;
		y->next=x;
		y=y->next;		
	}
	return g;
}
void insertNode(ls* l,int e,int w)
{
	ls x=(*l);
	while(x->next)
	{
		x=x->next;
	}
	x->next=createNode(e,w);
}
void insertVE(gph* g,int v,int e,int w)
{
	gph x=(*g);
	while(x)
	{
		if (x->data==v)
		{
			insertNode(&(x->head),e,w);
			break;
		}
		x=x->next;
	}
}
void rec(int a[],int v)
{
    if(v==0)
    {
        printf("%d ",0);
        return;
    }
    rec(a,a[v]);
    printf("%d ",v);
}
int prevbaap(gph g,int search,int visit[])
{
	int min=INT_MAX;
	gph x=g;
	while(x)
	{
		ls y=x->head;
		while(y)
		{
			if ((y->data)==search && (x->data)<min && visit[x->data]==1)
			{
				min=x->data;
			}
			y=y->next;
		}
		x=x->next;
	}
	return min;
}
void dks(gph* g,int x,int v,int val)
{
	int ctr=0;
	lola q=createq();
	int parent[v];
	int visit[v];
	int dist[v];
	for(int i=0;i<v;i++)
	{
	    visit[i]=0;
	    dist[i]=INT_MAX;
	    parent[i]=-1;
	}
	parent[0]=0;
	dist[0]=0;
	enqueue(&q,0);
	while(front(&q))
	{
		x=(front(&q))->data;
		gph g1=(*g);
		while(g1)
		{
			if (g1->data==x)
			{
				break;
			}
			g1=g1->next;
		}
		ls l1;
		if(((g1->head)->next)!=NULL)
			l1=(g1->head)->next;
		else
			l1=NULL;
		while(l1)
		{
			if (dist[l1->data]==(dist[x]+l1->weight))
			{
				if(parent[l1->data]==-1)
				{
				parent[l1->data]=x;
				dist[l1->data]=dist[x]+(l1->weight);
				}
				else if(parent[l1->data]!=-1 && parent[l1->data]>x)
				{
				parent[l1->data]=x;
				dist[l1->data]=dist[x]+(l1->weight);
				}
			}
			else if (dist[x]+(l1->weight)<dist[l1->data])
			{
				//dist[l1->data]=dist[x]+(l1->weight);
				parent[l1->data]=x;
				dist[l1->data]=dist[x]+(l1->weight);
				
			}
			l1=l1->next;
		}
		visit[x]=1;
		if (visit[val]==1)
		{
			ctr++;
			break;
		}
		dequeue(&q);
		int minv=INT_MAX;
		int mini=-1; 
		for (int i=0;i<v;++i)
		{
			if (visit[i]==0 && dist[i]<minv)
			{
				minv=dist[i];
				mini=i;
			}
		}
		if(mini==-1)
		{
			ctr=0;
			break;
		}
		else
		{
		enqueue(&q,mini);
		}
	}
	if(ctr || val==0)
	{
	    rec(parent,val);
	    pp("");
	}
	else
	{
	    pp("NIL");
	}
}
void printGraph(gph* g)
{
	gph t=(*g);
	while(t)
	{
		ls x=(t->head)->next;
		ppd(t->data);
		while(x)
		{
			ppd(x->data);
			ppd(x->weight);
			pp("");
			x=x->next;
		}
		t=t->next;
		pp("");
	}
}
int main()
{
	int t,V,E,v,e,w;
	scd(t);
	while(t--)
	{
		scd(V);
		int visit[V];
		scd(E);
		gph g=createGraph(V);
		for (int i=0;i<E;++i)
		{
			scd(v);
			visit[v]=1;
			scd(e);
			scd(w);
			insertVE(&g,v,e,w);
		}
		//printGraph(&g);
		for (int i=0;i<V;++i)
		{
			dks(&g,0,V,i);	
		}
	}
	return 0;
}
