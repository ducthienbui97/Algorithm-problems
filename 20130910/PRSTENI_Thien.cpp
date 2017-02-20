#include <bits/stdc++.h>
#define elif else if
using namespace std;
int n,x,a;
int ucln(int u,int v){
	if(u>v) swap(u,v);
	if(u==0) return v;
	return ucln(v%u,u);
	}
main(){
	ios_base::sync_with_stdio(false);
	cin>>n;
	n--;
	cin>>a;
	while(n--){
		cin>>x;
		int t=ucln(x,a);
		printf("%d/%d\n",a/t,x/t);	
	}
}
