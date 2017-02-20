#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define maxn 1009

using namespace std;

int n;
double s,h,v;
double l[maxn],cube[maxn];

void input() {
    int i;
    scanf("%f%f%f",&s,&h,&v);
    scanf ("%d",&n);
    for (i=1;i<=n;i++) {
        cin>>l[i]>>cube[i];
        //cout<<l[i];
    }
}

void process() {
    int i;
    double V;
    double lenght;
    lenght=v/s;
    for (i=1;i<=n;i++) {
        if (cube[i]>=1) V=l[i]*l[i]*l[i];
        else V=l[i]*l[i]*l[i]*cube[i];
        lenght+=V/s;
    }
    if (lenght>h) cout<<h;
    else printf("%f",lenght);
}

int main(){
    freopen("barrel.inp","r",stdin);
    freopen("barrel.out","w",stdout);
    input();
    process();
}
