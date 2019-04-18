/*Implement Dijkstra’s algorithm on vertices, where each vertex is a string. Implement the graph using an adjacency list only.

 

Input Format: The first input is T, the number of test cases. Thereafter, each test case starts with “V E”, where V is the number of vertices and E is the number of edges. The next V lines print the vertex names. Thereafter, each E line contains “u v w” denoting an edge from the vertex named u to the vertex named v with weight w. The next input is Q, the number of queries. The next Q lines are in the form of “u v” asking to print the cost from the vertex named u to the vertex named v.

 

Output Format: Q lines, each printing the path between the queried vertices. If there is no path, print NIL.

 

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

0

6

7

7

8

9

-1*/
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
int dks(gph* g,int x,int v,int val)
{
	lola q=createq();
	int visit[v];
	int dist[v];
	for(int i=0;i<v;i++)
	{
	    visit[i]=0;
	    dist[i]=INT_MAX;
	}
	dist[x]=0;
	visit[x]=1;
	enqueue(&q,x);
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
			if (dist[x]+(l1->weight)<dist[l1->data])
			{
				dist[l1->data]=dist[x]+(l1->weight);
			}
			l1=l1->next;
		}
		visit[(front(&q))->data]=1;
		if (visit[val]==1)
		{
			return dist[val];
		}
		dequeue(&q);
		int minv=INT_MAX;
		int mini=0; 
		for (int i=0;i<v;++i)
		{
			if (visit[i]==0 && dist[i]<minv)
			{
				minv=dist[i];
				mini=i;
			}
		}
		if(mini==0 && minv==INT_MAX)
		{
			return -1;
		}
		else
		{
		enqueue(&q,mini);
		}
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
		//printGraph(&g);
		int qe,i1,i2;
		scd(qe);
		for (int i=0;i<qe;++i)
		{
		    sc(vs);
		    i1=find(V,ch,vs);
		    sc(vs);
		    i2=find(V,ch,vs);
			ppd(dks(&g,i1,V,i2));	
		}
	}
	return 0;
}

