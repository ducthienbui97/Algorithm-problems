#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <climits>
#include <utility>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
struct pp{
    int id;
    int l,r;
    int X,Y;
} ;

bool cmpX(pp x,pp y){
    if(x.X==y.X) return x.Y<y.Y;
    return x.X<y.X;
}
bool cmpY(pp x,pp y){
    if(x.Y==y.Y) return x.X<y.X;
    return x.Y<y.Y;
}
bool cmpID(pp x,pp y){
    return x.id<y.id;
}
pp a[1000];
main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].X,&a[i].Y);
        a[i].id=i;
    }
    sort(a,a+n,cmpX);
    int s=a[0].id;
    for(int i=0;i<n;i+=2){
            a[i].l=a[i+1].id;
            a[i+1].l=a[i].id;
    }
    sort(a,a+n,cmpY);
    for(int i=0;i<n;i+=2){
            a[i].r=a[i+1].id;
            a[i+1].r=a[i].id;
    }
    sort(a,a+n,cmpID);
    int now=s,rep=0;
    while(1){
        rep++;
        if(rep%2==1){
            a[now].r=0;
            now=a[now].l;
        }
        else{
            a[now].l=0;
            now=a[now].r;
        }
        if(now==s) break;
    }
    rep=0;
    now=0;
    int nex=0;
    while(++rep<=n){
        nex=a[now].l+a[now].r;
        if(a[now].X>a[nex].X) putchar('W');
        else if(a[now].X<a[nex].X) putchar('E');
        else if(a[now].Y>a[nex].Y) putchar('S');
        else putchar('N');
        now=nex;
    }
}
