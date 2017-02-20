#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define fi "SQUIRREL.INP"
#define fo "SQUIRREL.OUT"
#define nmax 50000+5
using namespace std;
typedef long long ll;
typedef pair<int,int> II;
const ll INF=ll(1e13);
//VARIABLES
int n,m,t;
ll b[nmax];
II a[nmax];
//FUNCTION PROTOTYPES

void Process();

//MAIN
int main()
{
       freopen(fi,"r",stdin);
       freopen(fo,"w",stdout);
       Process();
       return 0;
}

//FUNCTIONS AND PROCEDURES
bool Check(ll k)
{
	ll S=0;
	for (int i=1;i<=m;++i)
	if (k<ll(a[i].first)) b[i]=0; else b[i]=(k-ll(a[i].first))/ll(a[i].second)+1;
	sort(b+1,b+m+1);
	for (int i=m;i>=max(m-n+1,1);--i) S+=b[i];
//	cout << k << " " << S << endl;
	return S>=t;
}
void Process()
{
	ll x=0,y=INF,mid;
	scanf("%d%d%d",&m,&n,&t);
	for (int i=1;i<=m;++i) scanf("%d",&a[i].first);
	for (int i=1;i<=m;++i) scanf("%d",&a[i].second);
	while (x!=y)
	{
		mid=(x+y)/2ll;
		if (Check(mid)) y=mid; else x=mid+1;
	}
	cout << x << endl;
}
