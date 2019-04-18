/*Subsequent to question dijkshatra's-cost-revisited , print the path instead of cost

Sample Input

1

7 14

A

B

C

D

E

F

G

A F 12

F A 12

A B 6

B A 6

B C 1

C B 1

C F 3

F C 3

A D 7

D A 7

D E 1

E D 1

E F 1

F E 1

7

A A

A B

A C

A D

A E

A F

A G

 

Sample Output

A

A B

A B C

A D

A D E

A D E F

NIL*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
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
int find(int v,char ch[v][20],char s[])
{
    for(int i=0;i<v;i++)
    {
        int ctr=0;
        for(int j=0;ch[i][j]!='\0';j++)
        {
            if(ch[i][j]!=s[j])
            {
                ctr++;
                break;
            }
        }
        if(ctr==0)
        return i;
    }
}
void rec(int a[],int V,int src,int dest,char ch[V][20])
{
    if(dest==src)
    {
        printf("%s ",ch[dest]);
        return;
    }
    rec(a,V,src,a[dest],ch);
    printf("%s ",ch[dest]);
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
int lexico(int V,char ch[V][20],int i,int j)
{
    return strcmp(ch[i],ch[j]);
}
void dks(gph* g,int source,int V,int dest,char ch[V][20])
{
    int src=source;
	int ctr=0;
	lola q=createq();
	int parent[V];
	int visit[V];
	int dist[V];
	for(int i=0;i<V;i++)
	{
	    visit[i]=0;
	    dist[i]=INT_MAX;
	    parent[i]=-1;
	}
	parent[source]=-1;
	dist[source]=0;
	enqueue(&q,source);
	while(front(&q))
	{
		source=(front(&q))->data;
		gph g1=(*g);
		while(g1)
		{
			if (g1->data==source)
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
			if (dist[l1->data]==(dist[source]+l1->weight))
			{
			    int check=lexico(V,ch,parent[l1->data],source);
				if(parent[l1->data]==-1)
				{
				parent[l1->data]=source;
				dist[l1->data]=dist[source]+(l1->weight);
				}
				else if(parent[l1->data]!=-1 && check>0)
				{
				parent[l1->data]=source;
				dist[l1->data]=dist[source]+(l1->weight);
				}
			}
		     else if (dist[source]+(l1->weight)<dist[l1->data])
			{
				//dist[l1->data]=dist[x]+(l1->weight);
				parent[l1->data]=source;
				dist[l1->data]=dist[source]+(l1->weight);
				
			}
			l1=l1->next;
		}
		visit[source]=1;
		if (visit[dest]==1)
		{
			ctr++;
			break;
		}
		dequeue(&q);
		int minv=INT_MAX;
		int mini=-1; 
		for (int i=0;i<V;++i)
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
	if(ctr || dest==src)
	{
	    rec(parent,V,src,dest,ch);
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
		char ch[V][20];
		char vs[20];
		char es[20];
		for(int i=0;i<V;i++)
		{
		    sc(ch[i]);
		}
		for (int i=0;i<E;++i)
		{
			sc(vs);
			sc(es);
			scd(w);
			v=find(V,ch,vs);
			e=find(V,ch,es);
			insertVE(&g,v,e,w);
		}
		int qe,i1,i2;
		scd(qe);
		for (int i=0;i<qe;++i)
		{
		    sc(vs);
		    i1=find(V,ch,vs);
		    sc(vs);
		    i2=find(V,ch,vs);
			dks(&g,i1,V,i2,ch);	
		}
	}
	return 0;
}
