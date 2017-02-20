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
deque<pointi> graham;
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
vector<pointi> a;
bool cmp(pointi a1,pointi a2)
{
    long long int X=ccw(a[0],a1,a2);
    if(X==1) return true;
    elif(X==0)
    {
        return (abs(a1)<abs(a2));
    }
    return false;
}
pointi z;
bool check(int n)
{
    int l=graham.size();
    pointi s1=graham[l-2],s2=graham[l-1];
    int X=ccw(s1,s2,a[n]);
    if(X>=0) return true;
    return false;
}
main()
{
    long long int n;
    scanf("%lld",&n);
    int minn,xx=INT_MAX,yy=INT_MAX;
    for(long long int i=1; i<=n; i++)
    {
        scanf("%lld%lld",&z.x,&z.y),a.push_back(z);
        if(z.y<yy)
        {
            yy=z.y;
            xx=z.x;
            minn=i-1;
        }
        elif(z.y==yy&&z.x<xx)
        {
            yy=z.y;
            z.x=xx;
            minn=i-1;
        }
    }
    swap(a[minn],a[0]);
    for(int i=0; i<n; i++){
        a[i].x-=xx,a[i].y-=yy;
    }
    sort(&a[1],&a[n],cmp);
    int d=0;
    while(d<n)
    {
        if(graham.size()<2) graham.push_back(a[d]),d++;
        elif(check(d)) graham.push_back(a[d]),d++;
        else graham.pop_back();
    }
    long long int s=0;
    for(int i=0; i<graham.size()-1; i++)
        s=s+(graham[i].y+graham[i+1].y)*(graham[i+1].x-graham[i].x);
    s=s+(graham.back().y+graham.front().y)*(graham.front().x-graham.back().x);
    printf("%lld",abs(s));
}
