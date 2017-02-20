#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    freopen("barrel.inp","r",stdin);
    freopen("barrel.out","w",stdout);
    double s,h,v,ha;
    int i;
    double a,d;
    int num;
    scanf("%lf%lf%lf",&s,&h,&v);
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        scanf("%lf%lf",&a,&d);
        if(d>1) v+=a*a*a;
        else v+=a*a*a*d;
    }
    ha=v/s;
    printf("%.7lf",min(h,ha));
}

