#include <cstdio>
#include <iostream>
#include <complex>
using namespace std;
#define X real()
#define Y imag()

typedef complex<double> point;
typedef struct line
{
    double a,b,c;
    point p1,p2,n,u;
    void make(point P1, point P2)
    {
        p1=P1;p2=P2;
        point u=p1-p2;
        n=point(-u.Y,u.X);
        a=n.X;
        b=n.Y;
        c=-(a*p1.X+b*p1.Y);
    }
};
double dist(point p1, point p2)
{
    return hypot(p1.X-p2.X, p1.Y-p2.Y);
}
point temp;
double distTL(point p, point A, point B)
{
    double scale = ((p.X - A.X) * (B.X - A.X) + (p.Y - A.Y) * (B.Y - A.Y))/ ((B.X - A.X) * (B.X - A.X) + (B.Y - A.Y) * (B.Y - A.Y));
    temp.X = A.X + scale * (B.X - A.X);
    temp.Y = A.Y + scale * (B.Y - A.Y);
    return dist(p, temp);
}
double ans=2e9;
line l1[101], l2[101];
point p1[101], p2[101];
int main()
{
    freopen("raft.inp","r",stdin);
    freopen("raft.out","w",stdout);
    int n1,n2;
    int j;
    int i;
    scanf("%d",&n1);
    for(i=1;i<=n1;i++)
    {
        scanf("%lf%lf",&p1[i].X,&p1[i].Y);
        //printf("%lf %lf\n",p1[i].X,p1[i].Y);
    }
    for(i=1;i<=n1-1;i++) l1[i].make(p1[i],p1[i+1]);
    l1[n1].make(p1[n1],p1[1]);
    scanf("%d",&n2);
    for(i=1;i<=n2;i++)
    {
        scanf("%lf%lf",&p2[i].X,&p2[i].Y);
        //printf("%lf %lf\n",p2[i].X,p2[i].Y);
    }
    for(i=1;i<=n2-1;i++) l2[i].make(p2[i],p2[i+1]);
    l1[n2].make(p2[n2],p2[1]);
    for(i=1;i<=n1;i++)
    {
        for(j=1;j<=n2;j++) ans=min(ans,distTL(p1[i],l2[j].p1,l2[j].p2));
    }
    printf("%.7lf",ans/2);
}
