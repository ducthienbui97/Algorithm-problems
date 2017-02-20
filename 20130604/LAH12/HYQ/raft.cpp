#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <utility>
#include <climits>
#include <vector>
#include <cstring>
#include <deque>
#include <queue>
#include <algorithm>
#include <map>
#define elif else if
#include <complex>
#define X real()
#define Y imag()
using namespace std;
typedef complex<double> point;
int n,m;
double mini;
double  findS(double a, double b,double c){
	double p;
	p=(a+b+c)*0.5;
	return	sqrt(p*(p-a)*(p-b)*(p-c));
}
double findu(point a,point b){
	return (a.X*b.X+a.Y*b.Y);
}
double distance(point a,point b,point c){
	point BA=a-b;
	point BC=c-b;
	point CB=b-c;
	point CA=a-c;
	double ans;
	if(findu(BA,BC)>=0&&findu(CA,CB)>=0)
		ans=(2*findS(abs(BA),abs(CA),abs(BC)))/abs(BC);
	else ans= min(abs(a-b),abs(a-c));
	return ans;
}
point A[111],B[111];
main(){
	freopen("raft.inp","r",stdin);
	freopen("raft.out","w",stdout);
	mini=1e6;
	int n1,n2;
	scanf("%d",&n1);
	for(int i=0;i<n1;i++)
		scanf("%lf%lf",&A[i].X,&A[i].Y);
	scanf("%d",&n2);
	for(int i=0;i<n2;i++){
		scanf("%lf%lf",&B[i].X,&B[i].Y);
		for(int j=0;j<n1;j++){
		mini=min(mini,distance(B[i],A[j],A[(j+1)%n1]));
		}
	}
	for(int i=0;i<n1;i++){
		for(int j=0;j<n2;j++){
		mini=min(mini,distance(A[i],B[j],B[(j+1)%n2]));
		}
	}
	
	printf("%.6lf\n",0.5*mini);
}
