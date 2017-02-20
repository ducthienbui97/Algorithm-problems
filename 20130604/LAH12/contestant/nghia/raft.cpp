#include <cstdio>
//#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <complex>
#define inf 1e9
#define eps 1e-9
#define x real()
#define y imag()
using namespace std;
int N1,N2;
typedef complex<double> point;
point P[105],Q[105];

double r=1000000000.0;
bool CCW(point p1,point p2,point p3)
{
	double a1,a2,b1,b2;
	a1=p2.x-p1.x;
	b1=p2.y-p1.y;
	a2=p3.x-p1.x;
	b2=p3.y-p1.y;
	double t=a1*b2-a2*b1;
	if(abs(t)<eps) return true;
	else return false;
}
double u(point a,point b)
{
	return (conj(a)*b).x;
}
double d(point a,point b)
{
	double t=abs((conj(a)*b).y);
	if(t<0) return -t;
	return t;
}
double solve(int i,int j)
{
	point A=P[i];
	point B=Q[j],C=Q[(j+1)%N2];
	point BA=A-B,BC=C-B,CA=A-C;
	point CB=B-C;
	if(CCW(A,B,C)) return min(abs(BA),abs(CA));
	if(u(BA,BC)<0) return abs(BA);
	if(u(CA,CB)<0) return abs(CA);
	return (d(BA,CA)/abs(BC));
}
double solve1(int i,int j)
{
	point A=Q[i];
	point B=P[j],C=P[(j+1)%N1];
	point BA=A-B,BC=C-B,CA=A-C;
	point CB=B-C;
	if(CCW(A,B,C)) return min(abs(BA),abs(CA));
	if(u(BA,BC)<0) return abs(BA);
	if(u(CA,CB)<0) return abs(CA);
	return (d(BA,CA)/abs(BC));
}
main()
{
	freopen("raft.inp","r",stdin);
	freopen("raft.out","w",stdout);
	scanf("%d",&N1);
	for(int i=0;i<N1;i++)
	{
		cin>>P[i].x>>P[i].y;
	}
	scanf("%d",&N2);
	for(int i=0;i<N2;i++)
	{
		cin>>Q[i].x>>Q[i].y;
	}
	for(int i=0;i<N1;i++)
	for(int j=0;j<N2;j++)
	{
		r=min(r,solve(i,j));
	}
	for(int i=0;i<N2;i++)
	for(int j=0;j<N1;j++)
	{
		r=min(r,solve1(i,j));
	}
	printf("%lf",r/2);
}
/*
3
0 0
1 0
1 1
5
3 -3
3 3
-4 2
-1 -1
-2 -2
*/

