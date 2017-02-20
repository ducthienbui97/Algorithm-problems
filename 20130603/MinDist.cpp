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
typedef complex<double> point;
const double EPS=1e-7;
struct line{
	int A,B,C;
	void set(int _A,int _B,int _C){
			A=_A;
			B=_B;
			C=_C;
	}
	void setn(point n,point _A){
		A=n.X;
		B=n.Y;
		C=-(n.X*_A.X+n.Y*_A.Y);
	}
	void setu(point u,point _A){
			setu(point(-u.Y,u.X),_A);
	}
	point findx(double y){
			point a;
			a.Y=y;
			a.X=(-C-B*y)/A;
			return a;
	}
	point findy(double x){
			point a;
			a.X=x;
			a.Y=(-C-A*x)/B;
			return a;
	}
};
int N;
point n[11111];
line S;
double l,r;
double find(point a){
	double dis=0;
	for(int i=1;i<=N;i++)
		dis+=abs(a-n[i]);
	return dis;
}
main(){
	double ans=0;
	scanf("%d",&N);
	scanf("%d%d%d",&S.A,&S.B,&S.C);
	for(int i=1;i<=N;i++){
		scanf("%lf%lf",&n[i].X,&n[i].Y);	
	}
	l=-1e6;
	r=1e6;
	double m1,m2;
	point mid1,mid2;
	double d1,d2;
	while(l+EPS<=r){
		m1=(r-l)/3;;
		m2=l+2*m1;
		m1=l+m1;
		mid1=S.findy(m1);
		mid2=S.findy(m2);
		d1=find(mid1);
		d2=find(mid2);
		ans=min(d1,d2);
		if(abs(d1-d2)<EPS) l=m1,r=m2;
		else if(d1<d2) r=m2;
		else l=m1;
	}
	printf("%.6lf",ans);
	return 0;
}
