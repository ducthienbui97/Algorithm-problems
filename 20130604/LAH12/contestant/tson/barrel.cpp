#include<stdio.h>
    
int main()
{
    freopen("barrel.inp","r",stdin);
    freopen("barrel.out","w",stdout);
    double s,h,v;
    int n,i;
    double  l,d;
    //double l[1000],d[1000];
    scanf("%lf%lf%lf",&s,&h,&v);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        double h1=v/s;
        scanf("%lf%lf",&l,&d);
        double h2=d/(l*l);
        if (h1<h2) h2=h1;
        d=l*l*h2;
        v=v+d;
    }
    v=v/s;
    if (v>h) printf("%.6lf",h) ;else printf("%.6lf",v);
    //for(;;);
}
    
    
