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
#include <utility>
#include <complex>
#define elif else if
#define X real()
#define Y imag() 
using namespace std;    
typedef pair<int,int> pii;     
bool v[1111],vs[1111];
int min1[1111];
int n,m;
priority_queue<pii> dx;
main(){
	memset(min1,0x3f,sizeof min1);
	freopen("Dagmst.inp","r",stdin);
	freopen("Dagmst.out","w",stdout);
	int x,y,z;
	int con=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		if(!v[y]){
			v[y]=true;
			con++;
		}
		min1[y]=min(min1[y],z);
	}
	if(con!=n-1){
		printf("-1");
	}
	else{
		int j=0;
		for(int i=1;i<=n;i++)
		if(v[i]) {
			j+=min1[i];
		}
		printf("%d",j);
	}
	return 0;
	
}
