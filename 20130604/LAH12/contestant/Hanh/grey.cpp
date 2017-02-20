#include<stdio.h>
#define MAX   2048576
bool c[MAX];
int s;
int x[MAX];
int n;
int p;
void init(void) {
	scanf("%d",&n);
	p=(1<<n)-1;
	int i;
	for (i=1;i<=p;i=i+1) c[i]=true;
	s=n;
	c[0]=false;
	x[1]=0;	
}
void print(void) {
	int i,j;
	for (i=1;i<=p+1;i=i+1) {
		for (j=0;j<n;j=j+1) printf("%d",(x[i]|(1<<j))==x[i]);
		printf("\n");
	}	
}
void process(void) {
	int i,j,k,v;	
	for (i=2;i<=p+1;i=i+1)
		for (j=0;j<n;j=j+1) {
			v=x[i-1]^(1<<j);
			if (c[v]) {
				x[i]=v;
				c[v]=false;
				if (i>p) {
					print();
					return;
				}
				for (k=0;k<n;k=k+1)
					if (v==(1<<k)) {
						s=s-1;
						break;
					}
				if (s==0) {
					c[v]=true;
					s=s+1;
					continue;
				}
				break;
			}
		}	
}
int main(void) {
	freopen("grey.inp","r",stdin);
	freopen("grey.out","w",stdout);
	init();
	process();
	return 0;
}
