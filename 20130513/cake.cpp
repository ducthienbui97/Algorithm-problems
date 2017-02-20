#include<stdio.h>
#include<math.h>
#include<complex>
#define MAX   111
#define EPS   1e-9
#define x   real()
#define y   imag()
using namespace std;
typedef complex<double> point;
int l,u,g;
int t,c;
point a[MAX];
point b[MAX];
double s;
double w;
void init(void) {
    int i;
    scanf("%lf",&w);
    scanf("%d",&l);
    scanf("%d",&u);
    scanf("%d",&g);
    for (i=1;i<=l;i=i+1) {
        scanf("%lf",&a[i].x);
        scanf("%lf",&a[i].y);
    }
    for (i=1;i<=u;i=i+1) {
        scanf("%lf",&b[i].x);
        scanf("%lf",&b[i].y);
    }
    s=0;
    for (i=1;i<l;i=i+1) s=s+(a[i+1].y+a[i].y)*(a[i+1].x-a[i].x);
    for (i=1;i<u;i=i+1) s=s+(b[i+1].y+b[i].y)*(b[i].x-b[i+1].x);
    s=abs(s)/2.0;
}
int lleft(int l,int r,double val) {
    if (l==r) return (r);
    if (r-l==1) {
        if (a[r].x<=val) return (r);
        return (l);
    }
    int m=(l+r)/2;
    if (a[m].x<=val) return (lleft(m,r,val));
    return (lleft(l,m-1,val));
}
int uleft(int l,int r,double val) {
    if (l==r) return (r);
    if (r-l==1) {
        if (b[r].x<=val) return (r);
        return (l);
    }
    int m=(l+r)/2;
    if (b[m].x<=val) return (uleft(m,r,val));
    return (uleft(l,m-1,val));
}
double scut(double dx) {
    int m=lleft(1,l,dx);
    int n=uleft(1,u,dx);
    double al,bt,yl,yu;
    al=(a[m+1].x-dx)/(a[m+1].x-a[m].x);
    bt=(dx-a[m].x)/(a[m+1].x-a[m].x);
    yl=al*a[m].y+bt*a[m+1].y;
    al=(b[n+1].x-dx)/(b[n+1].x-b[n].x);
    bt=(dx-b[n].x)/(b[n+1].x-b[n].x);
    yu=al*b[n].y+bt*b[n+1].y;
    double ds=0;
    int i;
    for (i=1;i<m;i=i+1) ds=ds+(a[i+1].y+a[i].y)*(a[i+1].x-a[i].x);
    for (i=1;i<n;i=i+1) ds=ds+(b[i].y+b[i+1].y)*(b[i].x-b[i+1].x);
    ds=ds+(yl+a[m].y)*(dx-a[m].x)+(yu+b[n].y)*(b[n].x-dx);
    return (abs(ds)/2.0);
}
double cut(double l,double r,double ds) {
    if (r-l<=EPS) return (r);
    double m=(r+l)/2;
    //printf("%.6lf %.6lf %.6lf\n",l,r,scut(m));
    if (scut(m)>ds) return (cut(l,m,ds));
    return (cut(m,r,ds));
}
void process(void) {
    printf("Case #%d:\n",c);
    int i;
    for (i=1;i<g;i=i+1){
        //printf("%.6lf\n",(i*s)/g);
        printf("%.6lf\n",cut(1,w,(i*s)/g));
    }
}
int main(void) {
    scanf("%d",&t);
    for (c=1;c<=t;c=c+1) {
        init();
        process();
    }
}
