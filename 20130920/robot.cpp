#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef pair<long long int,long long int> ii;
long long int n, p[100005][3];
ii a[100005];
long long int b[100005], s[100005];

int main(){
	freopen("robot.inp","r",stdin);
	freopen("robot.out","w",stdout);
	long long int i, x, y, res= 0, mini, add, comp;
	int nn, xx, yy;
	scanf("%d", &nn); n= nn;
	for(i=1;i<=n;i++){
		scanf("%d%d", &xx, &yy);
		x= xx; y= yy;
		p[i][1]= x;
		p[i][2]= y;
		a[i].first= x;
		a[i].second= y;
	}
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++){
		res+= abs(a[i].first-i);
		b[i]= a[i].second;
	}
	sort(b+1,b+1+n);
	//cout << res << endl;
	mini= 1000000000000000000LL;
	for(i=1;i<=n;i++){
		s[i]= s[i-1] + b[i];
	}
	for(i=1;i<=n;i++){
		add= i*b[i]- s[i] + s[n]- s[i]- (n-i)*b[i];
		mini= min(add,mini);
	}
	res+= mini;
	comp= res;
	for(i=1;i<=n;i++){
		a[i].first= p[i][2];
		a[i].second= p[i][1];
	}
	sort(a+1,a+1+n);
	res= 0; mini= 1000000000000000000LL;
	for(i=1;i<=n;i++){
		res+= abs(a[i].first-i);
		b[i]= a[i].second;
	}
	sort(b+1,b+1+n);
	for(i=1;i<=n;i++){
		s[i]= s[i-1] + b[i];
	}
	for(i=1;i<=n;i++){
		add= i*b[i]- s[i] + s[n]- s[i]- (n-i)*b[i];
		mini= min(add,mini);
	}
	res= min(res+mini, comp);
	cout << res << endl;
	return 0;
}
