#include<bits/stdc++.h>
#define MAX   1111
typedef long long ll;
int n;
ll a[MAX][MAX];
void add(int x,int y,const ll &val) {
    int t;
    while (1<=x && x<=n) {
        t=y;
        while (1<=t && t<=n) {
            a[x][t]+=val;
            t=t+(t&(-t));
        }
        x=x+(x&(-x));
    }
}
ll sum(int x,int y) {
    ll ret=0;
    int t;
    while (1<=x && x<=n) {
        t=y;
        while (1<=t && t<=n) {
            ret+=a[x][t];
            t=t&(t-1);
        }
        x=x&(x-1);
    }
    return (ret);
}
ll sum(const int &x1,const int &y1,const int &x2,const int &y2) {
    return (sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1));
}
void process(void) {
    scanf("%d",&n);
    scanf("%d",&n);
    int t,x1,y1,x2,y2;
    ll v;
    while (true) {
        scanf("%d",&t);
        if (t==3) return;
        if (t==1) {
            scanf("%d",&x1); x1++;
            scanf("%d",&y1); y1++;
            scanf("%lld",&v);
            add(x1,y1,v);
        }
        else {
            scanf("%d",&x1); x1++;
            scanf("%d",&y1); y1++;
            scanf("%d",&x2); x2++;
            scanf("%d",&y2); y2++;
            printf("%lld\n",sum(x1,y1,x2,y2));
        }
    }
}
int main(void) {
    freopen("mobiles.inp","r",stdin);
    freopen("mobiles.out","w",stdout);
    process();
    return 0;
}
