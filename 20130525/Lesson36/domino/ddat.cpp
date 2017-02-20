#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#define nmax 200000+5
#define fi "DOMINO.INP"
#define fo "DOMINO.OUT"
#define INF 1000000000

using namespace std;
typedef pair<int,int> II;
typedef pair<II,int> III;
typedef map<int,int> MII;
int n,b[nmax],f[nmax],d[nmax],bit[nmax];
III a[nmax];
MII my_map;
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
void Init()
{
	MII::iterator it;
	int t=0;
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&a[i].first.first,&a[i].first.second);
		a[i].second=i;
		my_map[a[i].first.first]=1;
		my_map[a[i].first.first+a[i].first.second-1]=1;
	}
	sort(a+1,a+n+1);
	for (it=my_map.begin();it!=my_map.end();++it) it->second=++t;
	for (int i=1;i<=n;++i) b[my_map[a[i].first.first]]=1;
	for (int i=1;i<=t;++i) b[i]+=b[i-1];
}
void Update(int x, int y)
{
	for (;x<nmax;x+=(x&(-x))) bit[x]=max(bit[x],y);
}
int Get(int x)
{
	int S=0;
	for (;x>0;x-=(x&(-x))) S=max(S,bit[x]);
	return S;
}
void Process()
{
	int k;
	for (int i=n;i>=1;--i)
	{
		k=my_map[a[i].first.first+a[i].first.second-1];
		d[i]=max(k,Get(k));
		k=my_map[a[i].first.first];
		Update(k,d[i]);
		f[a[i].second]=b[d[i]]-b[k-1];
	}
	for (int i=1;i<=n;++i) printf("%d ",f[i]);
}
