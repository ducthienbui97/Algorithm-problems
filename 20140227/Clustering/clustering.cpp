#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>

#define For(i,n) for(int i=0; i<n; i++)
#define maxn 1001

using namespace std;

int trace[maxn], N, K;
vector<int> edges[maxn];
vector<int> codes[maxn];

void read(){
	int x, y;
	scanf("%d", &N);
	For(i,maxn)
		edges[i].clear();
	For(i,N-1){
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
}

bool isSmaller(const vector<int> &a, const vector<int> &b){
	int len = min(a.size(), b.size());
	For(i,len)
		if (a[i] != b[i])
			return a[i] < b[i];
	return a.size() < b.size();
}

int travel(int x){
	queue<int> q;
	trace[x] = x;
	q.push(x);
	while (!q.empty()){
		x = q.front(), q.pop();
		For(i, edges[x].size()){
			int y = edges[x][i];
			if (trace[y] == 0){
				trace[y] = x;
				q.push(y);
			}
		}
	}
	return x;
}

void tracePath(vector<int>& path, int x){
	while (x != trace[x]) path.push_back(x), x = trace[x];
	path.push_back(x);
}

void getCode(int x, vector<int>& code){
	code.clear();
	trace[x] = 1;
	vector<vector<int> > cs;
	cs.clear();

	For(i, edges[x].size())
		if (trace[edges[x][i]] == 0){
			cs.push_back(vector<int>());
			getCode(edges[x][i], cs[cs.size()-1]);
		}
	
	sort(cs.begin(), cs.end(), isSmaller);

	code.push_back(cs.size());
	For(i,cs.size())
		For(j,cs[i].size())
			code.push_back(cs[i][j]);
}

void encode(vector<int>& code){
	For(i,maxn) trace[i] = 0;
	int x = travel(1);
	For(i,maxn) trace[i] = 0;
	x = travel(x);
	vector<int> path;
	tracePath(path, x);
	//cout<<"path "<<path.size()<<" "<<x<<endl;
	if (path.size() % 2 == 1){
		For(i,maxn) trace[i] = 0;
		getCode(path[path.size() / 2], code);
	} else {
		vector<int> v1, v2;

		For(i,maxn) trace[i] = 0;
		getCode(path[path.size() / 2], v1);
		
		For(i,maxn) trace[i] = 0;
		getCode(path[path.size() / 2 - 1], v2);
		
		if (isSmaller(v1, v2))
			For(i,v1.size()) code.push_back(v1[i]);
		else
			For(i,v2.size()) code.push_back(v2[i]);
	}
}

int main(){
	int T;
	freopen("G.inp", "r", stdin);
	scanf("%d", &T);
	For(t, T){
		For(i,maxn) codes[i].clear();
		scanf("%d", &K);
		For(k,K){
			read();
			encode(codes[k]);
		}
		int ans = 1;
		sort(codes, codes+K, isSmaller);
		For(i,K-1)
			ans += isSmaller(codes[i], codes[i+1]);
		cout<<ans<<endl;
	}
	return 0;
}