#include<stdio.h>
#define dn   1.0
int i;
double v,s,h;
double l,d;
int n;
int main(void) {
	freopen("barrel.inp","r",stdin);
	freopen("barrel.out","w",stdout);
	scanf("%lf",&s);
	scanf("%lf",&h);
	scanf("%lf",&v);
	scanf("%d",&n);
	for (i=1;i<=n;i=i+1) {
		scanf("%lf",&l);
		scanf("%lf",&d);
		if (d>=dn) v=v+l*l*l;
		else v=v+(l*l*l*d)/dn;		
	}
	printf("%.9lf",v/s);	
}
