#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#define fi "TRAVEL.INP"
#define fo "TRAVEL.OUT"
#define nmax 2000+5
#define mmax 150+5
#define kmax 300000+5
#define INF 1000000000
using namespace std;
typedef double dd;
typedef pair<int,int> II;
typedef vector<II> VII;
//VARIABLES
int n,m,t,nHeap,b[nmax],p[nmax][mmax],d[nmax][mmax],cnt[mmax];
II h[kmax];
VII c[nmax];
//FUNCTION PROTOTYPES

void Init();
void Process();

//MAIN
int main()
{
       freopen(fi,"r",stdin);
       freopen(fo,"w",stdout);
       Init();
       Process();
       return 0;
}

//FUNCTIONS AND PROCEDURES
void Add(int p, int q, int r)
{
	c[p].push_back(II(q,r));
}
void Init()
{
	int p,q,r;
	scanf("%d%d%d",&n,&m,&t);
	for (int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&p,&q,&r);
		Add(p,q,r);
		scanf("%d",&r);
		Add(q,p,r);
	}
	for (int i=1;i<=t;++i)
	{
		scanf("%d",&r);
		b[r]=i;
	}
	for (int i=0;i<(1<<t);++i)
	for (int j=0;j<t;++j)
	cnt[i]+=((i>>j)&1);
}
void UpHeap(int pos)
{
	II key=h[pos];int dad=pos/2;
	while ((pos>1) && (d[h[dad].first][h[dad].second]>d[key.first][key.second]))
	{
		h[pos]=h[dad];
		p[h[pos].first][h[pos].second]=pos;
		pos=dad;
		dad=pos/2;
	}
	h[pos]=key;
	p[key.first][key.second]=pos;
}
void DownHeap(int pos)
{
	II key=h[pos];int son=pos*2;
	while (son<=nHeap)
	{
		if (son<nHeap)
		if (d[h[son].first][h[son].second]>d[h[son+1].first][h[son+1].second]) ++son;
		if (d[h[son].first][h[son].second]>d[key.first][key.second]) break;
		h[pos]=h[son];
		p[h[pos].first][h[pos].second]=pos;
		pos=son;
		son=pos*2;
	}
	h[pos]=key;
	p[key.first][key.second]=pos;
}
void Push(II k)
{
	h[++nHeap]=k;
	p[k.first][k.second]=nHeap;
	UpHeap(nHeap);
}
II Pop()
{
	II S=h[1];
	p[h[1].first][h[1].second]=0;
	p[h[nHeap].first][h[nHeap].second]=1;
	h[1]=h[nHeap];
	h[nHeap--]=II(0,0);
	DownHeap(1);
	return S;
}
void Process()
{
	VII::iterator it;
	II k;
	int u,v,vx,w;
	for (int i=1;i<=n;++i)
	for (int j=0;j<(1<<t);++j)
	d[i][j]=INF;
	for (int i=1;i<=n;++i)
	if (b[i]!=0) d[i][1<<(b[i]-1)]=0;
	for (int i=1;i<=n;++i)
	for (int j=0;j<(1<<t);++j)
	Push(II(i,j));
	while (nHeap>0)
	{
		k=Pop();u=k.first;v=k.second;
//		cout << u << " " << v << "    " << d[u][v] << endl;
		if (cnt[v]==t) break;
		for (it=c[u].begin();it!=c[u].end();++it)
		{
		 	vx=v;
		 	if (b[it->first]!=0)
		 	if (((v>>(b[it->first]-1))&1)==0) vx+=(1<<(b[it->first]-1));
			w=int((0.1*dd(max(10-cnt[v],0)))*dd(it->second));
			if (d[it->first][vx]>d[u][v]+w)
			{
                            d[it->first][vx]=d[u][v]+w;
				UpHeap(p[it->first][vx]);
			}
		}
	}
	if (d[u][v]!=INF) printf("%d\n",d[u][v]); else printf("-1\n");
}
