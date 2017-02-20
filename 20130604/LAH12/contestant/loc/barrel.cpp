#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <complex>
#define X real()
#define Y imag()

using namespace std;

typedef complex<double> point;
double S,H,V,n,m=0;
double sum=0;
int main()
{
    freopen("barrel.inp","r",stdin);
    freopen("barrel.out","w",stdout);
    cin>>S>>H>>V;
    cin>>n;
    sum=(V/S);
    for(int i=1;i<=n;i++)
    {
        double a,b,ans;
        cin>>a>>b;
        ans=(pow(a,3)*b);
        cout<<ans<<endl;
        if(ans>=V)
        {
            m=1;
            double h;
            h=V/(S-a);
            cout<<V<<" "<<S<<" "<<a<<endl;
            printf("%.7f",h);
        }
        else
        {
            sum+=(ans/S);
        }
    }
    if(sum>H&&m==0) printf("%.7f\n",H);
    else if(sum<=H&&m==0) printf("%.7f\n",sum);
    return 0;
}

