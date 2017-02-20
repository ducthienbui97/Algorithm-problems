#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#define nmax 200+5
#define mmax 40000+5
#define fi "XYZ.INP"
#define fo "XYZ.OUT"

using namespace std;
typedef long long ll;
typedef pair<int,int> II;
typedef vector<int> VI;
const ll INF=ll(1e15);
//VARIABLES
int n,m,x,y,cnt,z,nHeap,b[nmax][nmax],f[mmax],g[10],h[mmax],p[mmax],w[10],m1[4]={-1,0,1,0},m2[4]={0,1,0,-1};
ll S,d[10][mmax],res;
bool check[mmax];
VI c[mmax];
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
void Add(int p, int q)
{
	c[p].push_back(q);
}
void Init()
{
	int p,q;
	scanf("%d%d%d%d",&m,&n,&x,&y);
	for (int i=1;i<=m;++i)
	for (int j=1;j<=n;++j)
	b[i][j]=++cnt;
	for (int i=1;i<=x;++i)
	{
		scanf("%d%d",&p,&q);
		g[i]=b[p][q];
	}
	for (int i=1;i<=m;++i)
	for (int j=1;j<=n;++j)
	scanf("%d",&f[b[i][j]]);
	for (int i=1;i<=m;++i)
	for (int j=1;j<=n;++j)
	for (int k=0;k<=3;++k)
	if ((i+m1[k]>=1) && (i+m1[k]<=m) && (j+m2[k]>=1) && (j+m2[k]<=n))
	Add(b[i][j],b[i+m1[k]][j+m2[k]]);
	n=m*n;
}
void UpHeap(int pos)
{
	int key=h[pos],dad=pos/2;
	while ((pos>1) && (d[z][h[dad]]>d[z][key]))
	{
		h[pos]=h[dad];
		p[h[pos]]=pos;
		pos=dad;
		dad=pos/2;
	}
	h[pos]=key;
	p[key]=pos;
}
void DownHeap(int pos)
{
	int key=h[pos],son=pos*2;
	while (son<=nHeap)
	{
		if (son<nHeap)
		if (d[z][h[son]]>d[z][h[son+1]]) ++son;
		if (d[z][h[son]]>d[z][key]) break;
		h[pos]=h[son];
		p[h[pos]]=pos;
		pos=son;
		son=pos*2;
	}
	h[pos]=key;
	p[key]=pos;
}
void Push(int k)
{
	h[++nHeap]=k;
	p[k]=nHeap;
	UpHeap(nHeap);
}
int Pop()
{
	int S=h[1];
	p[h[1]]=0;
	p[h[nHeap]]=1;
	h[1]=h[nHeap];
	h[nHeap--]=0;
	DownHeap(1);
	return S;
}
void Dijkstra()
{
	VI::iterator it;
	int k;
	for (int i=1;i<=n;++i) d[z][i]=INF;
	d[z][g[z]]=(z==0?f[g[z]]:0);
	for (int i=1;i<=n;++i) Push(i);
	while (nHeap>0)
	{
		k=Pop();
//		cout << k << endl;
		for (it=c[k].begin();it!=c[k].end();++it)
		if (d[z][*it]>d[z][k]+f[*it])
		{
                     d[z][*it]=d[z][k]+ll(f[*it]);
                     UpHeap(p[*it]);
		}
	}
}
void Try(int i)
{
	for (int j=1;j<=x;++j)
	if (check[j])
	{
		check[j]=false;
		w[i]=j;
		S+=d[w[i-1]][g[j]];
		if (i==y)
		{
			res=min(res,S+d[w[i]][g[x+1]]);
//			for (int k=1;k<=y;++k) cout << w[k] << " "; cout << endl;
		} else Try(i+1);
		S-=d[w[i-1]][g[j]];
		check[j]=true;
	}
}
void Process()
{
	memset(check,true,sizeof(check));
	g[0]=1;
	g[x+1]=n;
	for (int i=0;i<=x+1;++i)
	{
		z=i;
		Dijkstra();
	}
//	for (int i=0;i<=x+1;++i)
//	{
//		cout << g[i] << endl;
//		for (int j=1;j<=n;++j) cout << d[i][j] << " ";
//		cout << endl;
//	}
	res=INF;
	Try(1);
	cout << res << endl;
}
