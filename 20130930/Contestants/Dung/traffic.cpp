#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int h[100005], f[100005][30], f_min[100005][30], f_max[100005][30];
int n, mini, maxi;
typedef pair<int,int> ii;
vector<ii> a[100005];
queue<int> v;

void get(int x, int y){
	maxi= -1000000000; mini= 1000000000;
	int i;
	if(h[x]<h[y]) swap(x,y);
	if(h[x]>h[y]){
		for(i=20;i>=0;i--){
			if(h[f[x][i]]>=h[y]){
				mini= min(mini, f_min[x][i]);
				maxi= max(maxi, f_max[x][i]);
				x= f[x][i];
			}
		}
	}
	if(x==y) return;
	for(i=20;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			mini= min(mini, min(f_min[x][i], f_min[y][i]));
			maxi= max(maxi, max(f_max[x][i], f_max[y][i]));
			x= f[x][i];
			y= f[y][i];
		}
	}
	mini= min(mini, min(f_min[x][0], f_min[y][0]));
	maxi= max(maxi, max(f_max[x][0], f_max[y][0]));
	return;
}

void build(){
	int i, to, x;
	h[1]= 1;
	to= a[1].size();
	for(i=0;i<to;i++){
		v.push(a[1][i].first);
		h[a[1][i].first]= 2;
		f[a[1][i].first][0]= 1;
		f_min[a[1][i].first][0]= a[1][i].second;
		f_max[a[1][i].first][0]= a[1][i].second;
	}
	while(v.empty()==false){
		x= v.front(); v.pop();
		to= a[x].size();
		i= 0;
		while(f[x][i]!=0){
			i++;
			f[x][i]= f[f[x][i-1]][i-1];
			f_min[x][i]= min(f_min[x][i-1], f_min[f[x][i-1]][i-1]);
			f_max[x][i]= max(f_max[x][i-1], f_max[f[x][i-1]][i-1]);
		}
		for(i=0;i<to;i++){
			if(a[x][i].first== f[x][0]) continue;
			v.push(a[x][i].first);
			h[a[x][i].first]= h[x]+1;
			f[a[x][i].first][0]= x;
			f_min[a[x][i].first][0]= a[x][i].second;
			f_max[a[x][i].first][0]= a[x][i].second;
		}
	}
	return;
}

int main(){
	freopen("traffic.inp","r",stdin);
	freopen("traffic.out","w",stdout);
	int i, x, y, z, m;
	scanf("%d", &n);
	for(i=1;i<=n-1;i++){
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(ii(y,z));
		a[y].push_back(ii(x,z));
	}
	//
	build();
	//
	scanf("%d", &m);
	for(i=1;i<=m;i++){
		scanf("%d%d", &x, &y);
		get(x,y);
		printf("%d %d\n", mini, maxi);
	}
	return 0;
}

