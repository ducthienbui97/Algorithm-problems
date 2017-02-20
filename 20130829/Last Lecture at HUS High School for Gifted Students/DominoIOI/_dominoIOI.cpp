#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

#define fi first
#define se second
#define oo 2000000000
#define maxn 1011

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int n, m, st = 0, sf, f[maxn][maxn], c[maxn][maxn], trace[maxn], k;
int cell[maxn][maxn];
vector<ii> r;

void init()
{
	sf = m*n+1;
	for(int i = 1; i <= m*n; i++)
	{
		if((((i-1) % m) + ((i-1)/m)) % 2 == 0) c[st][i] = 1;
		else c[i][sf] = 1;
	}
	int cnt = 0;
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	cell[i][j] = ++cnt;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(c[st][cell[i][j]])
			for(int k = 0; k < 4; k++)
			{
				int x = i + dx[k], y = j + dy[k];
				if(x >= 0 && x < n && y >= 0 && y < m)
					{
						c[cell[i][j]][cell[x][y]] = 1;
//						cout << cell[i][j] <<' ' <<cell[x][y] << endl;
					}
			}
}

bool bfs()
{
	queue<int> q; q.push(st);
	memset(trace, -1, sizeof(trace));
	trace[st] = st;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		if(u == sf) break;
		for(int v = 1; v <= m*n+1; v++)
		{
			if(trace[v] == -1 && c[u][v] > f[u][v])
			{
				q.push(v);
				trace[v] = u;
			}
		}		
	}
	if(trace[sf] >= 0) return true;
	return false;
}

void incf()
{
	int delta = oo, v = sf;
	while(v != st)
	{
		int u = trace[v];
//		cout << u << ' ';
		delta = min(delta, c[u][v] - f[u][v]);
		v = u;
	}
//	cout << endl;
	v = sf;
	while(v != st)
	{
		int u = trace[v];
		f[u][v] += delta;
		f[v][u] -= delta;
		v = u;
	}
}

void process()
{
	while(1)
	{
		if(!bfs()) break;
		incf();
	}
	for(int i = 1; i <= m*n; i++)
	for(int j = 1; j <= m*n; j++)
	if(f[i][j] > 0) cout << i <<' '<< j << endl;
}

int main()
{
	freopen("DominoIOI.in", "r", stdin);
	freopen("DominoIOI.out", "w", stdout);
	cin >> n >> m >> k;
	init();
	for(int i = 0; i < k; i++)
	{
		int x, y; cin >> x >> y;
		c[x][y] = 0;
		c[y][x] = 0;
	}
	process();
	return 0;
}

