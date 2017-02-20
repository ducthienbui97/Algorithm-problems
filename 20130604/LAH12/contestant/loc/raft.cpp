#include <iostream>
#include <stdio.h>
#include <complex>
#include <math.h>
#define X real()
#define Y imag()

using namespace std;

double n,m,in=1000000000;
complex<double>N[200];
complex<double>M[200];

double S(complex<double> a,complex<double> b,complex<double> d)
{
    double ss=0;
    ss+=(a.Y+b.Y)*(b.X-a.X);
    ss+=(b.Y+d.Y)*(d.X-b.X);
    ss+=(d.Y+a.Y)*(a.X-d.X);
    return (fabs(ss)/2);
}
double lolo1(complex<double> a,complex<double> b)
{
    return sqrt(pow((a.X-b.X),2)+pow((a.Y-b.Y),2));
}
double lolo(complex<double> c,complex<double> x,complex<double> y)
{
    double s=S(c,x,y);
    if(s!=0)
    {
    double h=((s*2)/lolo1(x,y));
    cout<<x<<" "<<y<<" "<<c<<":"<<s<<"va"<<lolo1(x,y)<<"va"<<h/2<<endl;
    cout<<endl;
    if(h/2<in) in=h/2;
    }
}
int main()
{
    freopen("raft.inp","r",stdin);
    freopen("raft.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        double a,b;
        cin>>a>>b;
        N[i].X=a;
        N[i].Y=b;
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        M[i].X=a;
        M[i].Y=b;
    }
    for(int i=1;i<=n;i++)
    {
        for(int ii=1;ii<=m;ii++)
        {
            if(ii==m) lolo(N[i],M[ii],M[1]);
            else lolo(N[i],M[ii],M[ii+1]);
        }
    }
    printf("%.6f\n",in);
    return 0;
}
