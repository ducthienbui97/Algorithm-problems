#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <algorithm>
#include <deque>
#define elif else if
#define pb push_back
#define mp make_pair
#include <utility>
#include <complex>
#define X real()
#define Y imag()
const int  Maxn = 222;
using namespace std;
typedef complex<double>  vec;
struct pick{
    vec lo,v;
    int color;
};
struct bumper{
    vec lo,v;
};
struct sled{
    vec lo;
    vec v;
};
int t,n,m,y,ss;
vec mi,z;
pick p[Maxn];
bumper b[5];
sled s[3];
int nx;
vec x[3][Maxn];
double randd(){
  return -rand()/(rand()+1);
}
void input(){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%lf%lf%lf%lf%d",&p[i].lo.X,&p[i].lo.Y,&p[i].v.X,&p[i].v.Y,&p[i].color);
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
            scanf("%lf%lf%lf%lf",&b[i].lo.X,&b[i].lo.Y,&b[i].v.X,&b[i].v.Y);
        scanf("%d",&ss);
        for(int i=1;i<=ss;i++){
            scanf("%lf%lf%lf%d",&s[i].lo.X,&s[i].lo.Y,&s[i].v.X,&y);
            s[i].v.Y=cos(s[i].v.X);
            s[i].v.X=sin(s[i].v.X);
            if(i==1) nx=y;
            for(int j=1;j<=y;j++){
            scanf("%lf%lf",&x[i][j].X,&x[i][j].Y);
            }
        }
}
main(){
    srand(time(NULL));
    scanf("%d",&t);
    int delay=3;
    while(t>-1){
        input();
        vec d=s[2].lo-b[1].lo;
        vec mi=s[1].lo-b[2].lo;
        vec xx,zz,yy;
        int kk=INT_MAX;
        for(int i=1;i<=n;i++)
        if(p[i].color==1){
            zz=p[i].lo-s[2].lo;
            xx=p[i].lo-s[1].lo;
            if(min(abs(xx),abs(zz))<kk){
                kk=abs(zz);
                yy=p[i].lo;
            }
        }
        mi=yy-b[2].lo;
        d.X=100*d.X;
        d.Y=100*d.Y;
        mi.X=100*mi.X;
        mi.Y=100*mi.Y;
        if(nx<3) delay=nx,cout<<randd()<<" "<<randd()<<" "<<randd()<<" "<<randd()<<" "<<0<<endl;
        elif(delay<5) cout<<randd()<<" "<<randd()<<" "<<randd()<<" "<<randd()<<" "<<randd()<<endl;
        else cout<<d.X<<" "<<d.Y<<" "<<mi.X<<" "<<mi.Y<<" "<<0.17<<endl;
        delay++;
        scanf("%d",&t);
    }
}
