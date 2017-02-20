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
double s,S,H,V,li,di,vi;
main(){
		freopen("barrel.inp","r",stdin);
		freopen("barrel.out","w",stdout);
		scanf("%lf%lf%lf",&S,&H,&V);
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lf%lf",&li,&di);
			vi=li*li*li;
			s=vi*di;
			V+=s;
		}
		printf("%.7lf",V/S);
}
