#include <cstdio>
#include <algorithm>
#include <iostream>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ii,ii> pi;

const ll INF= 1000000000000005LL;

ll n, w, h;
pi a[6005];
ll c[6005], d[6005], m;
ll sum[6005];
ll res[2];

int main(){
    ios_base::sync_with_stdio(false);
    cin >> w >> h; cin >> n;
    for(ll i=1;i<=n;i++){
        string str; ll x, y, z;
        cin >> str; cin >> x >> y >> z;
        ii p1= ii(x-z,y), p2= ii(x+z,y);
        p1= ii(p1.x-p1.y,p1.x+p1.y); p2= ii(p2.x-p2.y,p2.x+p2.y);
        if(str=="W"){
            a[2*i-1]= pi(ii(p1.x,1),ii(p1.y,p2.y));
            a[2*i]= pi(ii(p2.x+1,-1),ii(p1.y,p2.y));
        }
        else{
            a[2*i-1]= pi(ii(p1.x,-1),ii(p1.y,p2.y));
            a[2*i]= pi(ii(p2.x+1,1),ii(p1.y,p2.y));
        }
        c[2*i-1]= p1.y; c[2*i]= p2.y+1;
    }
    sort(a+1,a+1+2*n);
    sort(c+1,c+1+2*n);
    d[1]= c[1]; m= 1;
    for(ll i=2;i<=2*n;i++){
        if(c[i]!=c[i-1]) m++;
        d[m]= c[i];
    }
    a[2*n+1]= pi(ii(INF,0),ii(INF,INF)); a[0]= pi(ii(-INF,0),ii(INF,INF));

    ll j= 1;
    for(ll i=1;i<=2*n;){
        while(j<=2*n && a[i].x.x==a[j].x.x) j++; j--;
        for(ll k=1;k<m;k++){
            ll x1= a[i-1].x.x+INF, x2= a[i].x.x-1+INF, y1= d[k]+INF, y2= d[k+1]-1+INF;
            ll even1= ((x2-(x2%2))-(x1+(x1%2))+2)/2, even2= ((y2-(y2%2))-(y1+(y1%2))+2)/2;
            ll odd1= (x2-x1+1)-even1, odd2= (y2-y1+1)-even2;
            if(sum[k]>0) res[0]+= (even1*even2+odd1*odd2);
            if(sum[k]<0) res[1]+= (even1*even2+odd1*odd2);
        }
        for(ll k=i;k<=j;k++){
            ll l= 1, r= 1;
            while(d[l]<a[k].y.x) l++;
            while(d[r]<=a[k].y.y) r++; r--;
            while(l<=r){
                sum[l]+= a[k].x.y;
                l++;
            }
        }
        //
        i= j+1; j++;
    }
    cout << res[0] << " " << res[1] << "\n";

    return 0;
}
