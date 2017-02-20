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
#include <stack>
#include <complex>
#define x real()
#define y imag()
#define elif else if
#define mp make_pair
using namespace std;
const double EFS=1e-9;
typedef pair<long long int,long long int> pii;
typedef complex<double> pointd;
typedef complex<long long int> pointi;
struct line
{
    double A,B,C;
    pointd u,n,p,q;
    void set(pointi p,pointi q)
    {
        u=p-q;
        n=(-u.y,u.x);
        A=n.x;
        B=n.y;
        C=-(A*p.x+B*p.y);
    }
};
long long int ccw(pointi p1,pointi p2,pointi p3)
{
    double a1,a2,b1,b2,t;
    a1=p2.x-p1.x;
    b1=p2.y-p1.y;
    a2=p3.x-p1.x;
    b2=p3.y-p1.y;
    t=a1*b2-a2*b1;
    if(fabs(t)<EFS) return 0;
    elif (t<0) return -1;
    else return 1;
}

bool cmp(pointi a1,pointi a2){
    long long int X=ccw((0,0),a1,a2);
    if(X==1) return true;
    elif(X==0){
        return (abs(a1)<abs(a2));
    }
    return false;
}
vector<pointi> a;
pointi z;
main(){
    long long int n;
    scanf("%lld",&n);
    for(long long int i=1;i<=n;i++)
    scanf("%lld%lld",&z.x,&z.y),a.push_back(z);
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<n;i++)
    cout<<a[i].x<<" "<<a[i].y<<endl;
}
