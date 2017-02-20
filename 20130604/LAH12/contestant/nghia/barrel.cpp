#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#define eps 1e-9
using namespace std;

main()
{
	freopen("barrel.inp","r",stdin);
	freopen("barrel.out","w",stdout);
	int n;
	double S,H,V;
	cin>>S>>H>>V;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		double l,d;
		cin>>l>>d;
		if(d<1) V+=(l*l*l*d);
		else V+=(l*l*l);
	}
	double H1;
	H1=V/S;
	printf("%.7lf",min(H1,H));
}
