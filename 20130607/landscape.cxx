#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <algorithm>
#include <map>
#include <utility>
#include <complex>
#include <set>
#include <deque>
#define elif else if
using namespace std;
int n,n1,n2;
int w[1002][1002];
bool vs[1002][1002];
int xi[]={-1,1,0,0,1,-1,1,-1};
int yi[]={0,0,-1,1,1,-1,-1,1};
bool dfs1(int x,int y){
	vs[x][y]=true;
	bool check=true;
	for(int i=0;i<8;i++){
		if(x+xi[i]<1) continue;
		if(y+yi[i]<1) continue;
		if(x+xi[i]>n) continue;
		if(y+yi[i]>n) continue;
		if(w[x+xi[i]][y+yi[i]]==w[x][y]) {
			if(!vs[x+xi[i]][y+yi[i]])
			check=check&dfs1(x+xi[i],y+yi[i]);
		}
		else if(w[x+xi[i]][y+yi[i]]<w[x][y])
			check=false;
	}
	return check;
}
bool dfs2(int x,int y){
	vs[x][y]=false;
	bool check=true;
	for(int i=0;i<8;i++){
		if(x+xi[i]<1) continue;
		if(y+yi[i]<1) continue;
		if(x+xi[i]>n) continue;
		if(y+yi[i]>n) continue;
		if(w[x+xi[i]][y+yi[i]]==w[x][y]) {
			if(vs[x+xi[i]][y+yi[i]])
			check=check&dfs2(x+xi[i],y+yi[i]);
			}
		else if(w[x+xi[i]][y+yi[i]]>w[x][y])
			check=false;
	}
	return check;
}
main(){
	freopen("landscape.inp","r",stdin);
	freopen("landscape.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&w[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(!vs[i][j]) if(dfs1(i,j)) n1++;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(vs[i][j]) 	if(dfs2(i,j)) n2++;
	swap(n1,n2);
	cout<<n1<<" "<<n2;
}
