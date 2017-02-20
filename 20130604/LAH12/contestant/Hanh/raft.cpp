#include<stdio.h>
#include<complex>
#define x   real()
#define y   imag()
#define MAX   111
#define INF   1e9
using namespace std;
typedef complex<double> point;
int m,n;
point a[MAX];
point b[MAX];
double res;
void init(void) {
	int i;
	scanf("%d",&m);
	for (i=0;i<m;i=i+1) {
		scanf("%lf",&a[i].x);
		scanf("%lf",&a[i].y);
	}
	scanf("%d",&n);	
	for (i=0;i<n;i=i+1) {
		scanf("%lf",&b[i].x);
		scanf("%lf",&b[i].y);
	}
}
double min(const double &x,const double &y) {
	if (x<y) return (x); else return (y);
}
double dotp(const point &a,const point &b) {
	return (a.x*b.x+a.y*b.y);
}
double crossp(const point &a,const point &b) {
	return (a.x*b.y-a.y*b.x);
}
double mindist(const point &a,const point &b,const point &c) {
	if (dotp(b-a,b-c)<0) return (abs(b-a));
	if (dotp(c-a,c-b)<0) return (abs(c-a));
	return (abs((crossp(a-b,a-c)))/abs(b-c));
}
void process(void) {
	res=INF;
	int i,j;
	for (i=0;i<m;i=i+1)
		for (j=0;j<n;j=j+1) {
			res=min(res,mindist(a[i],b[j],b[(j+1)%n]));
			res=min(res,mindist(b[j],a[i],a[(i+1)%m]));
		}			
	printf("%.6lf",res/2);
}
int main(void) {
	freopen("raft.inp","r",stdin);
	freopen("raft.out","w",stdout);
	init();
	process();
	return 0;
}
