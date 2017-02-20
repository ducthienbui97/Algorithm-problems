#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<deque>
#include<set>
#include<complex>
#define oo 1000000000
#define base 1000000007ll
#define X real()
#define Y imag()
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef complex<double> point;
const double eps=1e-5;
double dpp(point A,point B)
{
    return sqrt(pow(A.X-B.X,2.0)+pow(A.Y-B.Y,2.0));
}
struct line
{
    double A,B,C;
    point p1,p2,u,n;
    void Set(point p1,point p2)
    {
        u=p2-p1;
        n.X=u.Y; n.Y=-u.X;
        A=n.X; B=n.Y;
        C=-A*p1.X-B*p1.Y;
    }
};

double dpl(point p,line x)
{
    return fabs((x.A*p.X+x.B*p.Y+x.C)/(sqrt(x.A*x.A+x.B*x.B)));
}

struct circle
{
    point cent;
    double radius;
};

vector<point> cutcl(circle I,line u)
{
    vector<point> tmp;
    double XX=u.p1.X-I.cent.X,YY=u.p1.Y-I.cent.Y;
    double _A=u.u.X*u.u.X+u.u.Y*u.u.Y,_B=2.0*(u.u.X*XX+u.u.Y*YY),_C=XX*XX+YY*YY-I.radius*I.radius;
    double delta=_B*_B-4.0*_A*_C;
    if(delta<0) return tmp;
    delta=sqrt(delta);
    double t1=(-_B+delta)/(2*_A),t2=(-_B-delta)/(2*_A);
    tmp.push_back(point(u.p1.X+u.u.X*t1,u.p1.Y+u.u.Y*t1));
    tmp.push_back(point(u.p1.X+u.u.X*t2,u.p1.Y+u.u.Y*t2));
    return tmp;
}
                            /*                           END OF TEMPLATE                            */
// VOI 2013
// IOI 2014
int n,k;
circle NET;
typedef pair<double,int> di;
point fish[1005],donvi[1005];
line way[1005];
vector<di> net;
double Max(double a,double b) { return a>=b? a:b; }
void solve(int i)
{
    vector<point> t=cutcl(NET,way[i]);
    double t1,t2;
    if(!t.size()) return;
    if(way[i].u.X!=0) t1=(t[0].X-fish[i].X)/way[i].u.X;
    else t1=(t[0].Y-fish[i].Y)/way[i].u.Y;
    if(way[i].u.X!=0) t2=(t[1].X-fish[i].X)/way[i].u.X;
    else t2=(t[1].Y-fish[i].Y)/way[i].u.Y;
    if(t2<t1) swap(t1,t2);
    if(t2<0) return;
    net.push_back(di(t1,-1));
    net.push_back(di(t2,1));
}
bool check(double key)
{
    NET.radius=key;
    net.clear();
    int i,caught=0;
    for(i=1; i<=n; i++) solve(i);
    sort(net.begin(),net.end());
    for(i=0; i<net.size(); i++)
    {
        caught-=net[i].second;
        if(caught>=k) return true;
    }
    return false;
}
int main()
{
    freopen("fish.inp","r",stdin);
    freopen("fish.out","w",stdout);
    int i;
    point A,B;
    cin>>NET.cent.X>>NET.cent.Y;
    scanf("%d %d",&n,&k);
    for(i=1; i<=n; i++)
    {
        cin>>fish[i].X>>fish[i].Y>>donvi[i].X>>donvi[i].Y;
        way[i].p1=fish[i]; way[i].p2=donvi[i];
        way[i].Set(fish[i],donvi[i]);
    }
    double low=0,high=10000000,mid;
    for(i=1; i<=64; i++)
    {
        mid=(low+high)/2.0;
        if(check(mid)) high=mid;
        else low=mid;
    }
    printf("%.5lf\n",mid);
    return 0;
}
