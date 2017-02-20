#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<long> > a(10005);
vector<long> b;
long x, y, result, mini, timer;
bool have, sign[10005];

void dfs(long i, long loop, bool n1, bool n2, bool start){
	long j;
	//timer++;
	//if(timer>10000) return;
	if(have==true) return;
	if(start==false) sign[i]= true;
	if(n1==false){
		if(start==false) loop++;
		if(i==y) {
			n1= true; n2= false;
		}
		for(j=0;j<a[i].size();j++){
					if(sign[a[i][j]]==false) dfs(a[i][j],loop,n1,n2,false);
					}
		return;
	}
	if(n2==false){
		if(i==x) {
			n2= true;
			result= loop;
			have= true;
			return;
		}
		for(j=0;j<a[i].size();j++){
					if(sign[a[i][j]]==false) dfs(a[i][j],loop,n1,n2,false);
					}
		return;
	}
}

main(){
	freopen("1.inp","r",stdin);
	freopen("1.out","w",stdout);
	long n, i;
	scanf("%ld", &n);
	for(i=1;i<=n;i++){
		scanf("%ld %ld", &x, &y);
		a[x].push_back(y);
		b.push_back(x); b.push_back(y);
		}
	for(;;){
	scanf("%ld %ld", &x, &y);
	if(x==0 && y==0) break;
	have= false; //timer= 0;
	for(i=0;i<b.size();i++) sign[b[i]]= false;
	dfs(x,-1,false,true,true);
	if(have==false) printf("No\n");
	else printf("Yes %ld\n", result);
	}
}
