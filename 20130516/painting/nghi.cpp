#include<iostream>
#include<cstdio>
using namespace std;
int a[110][110],n,m,b[110][110];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int all=0,res[110],cnt=0;
int vs[110][110];

void dfs(int x,int y) {
	res[cnt]+=b[x][y];
	vs[x][y]=1;
	for(int c=0;c<n;c++){
		int i=x+dx[c],j=y+dy[c];
		if(!vs[i][j] && a[i][j]) dfs(i,j);
	}
}

int main()
{
	//freopen("a","r",stdin);
	freopen("PAINTING.INP","r",stdin);
	freopen("PAINTING.OUT","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int c=0;c<4;c++){
				int x=i+dx[c],y=j+dy[c];
				b[i][j]+=max(0,a[i][j]-a[x][y]);
			}
			//cout << b[i][j] << " ";
			all+=b[i][j];
		}
		//cout << endl;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j] && !vs[i][j]){
				cnt++;
				dfs(i,j);
			}
	cout << cnt << endl;
	cout << all << endl;
	int mx=0,x=0;
	for(int i=1;i<=cnt;i++)
		if(res[i]>mx)
			mx=res[i],x=i;
	cout << x << " " << mx;
	return 0;
}
