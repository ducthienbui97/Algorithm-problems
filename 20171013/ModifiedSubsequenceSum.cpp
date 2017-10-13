#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5+30;
long long F[MAX << 3];
long long X[MAX << 3];
long long k;
void update(int node, int l,int r,long long val,int x) {
    if(r <= x) return;
    if(l > x) {
        //cout << node <<":"<< l <<" "<<x <<endl;
        long long L = val - k*(l - x - 1)*(l - x - 1);
        long long R = val - k*(r - x - 1)*(r - x - 1);
        long long cur_L = F[node] - k*(l - X[node] - 1)*(l - X[node] - 1);
        long long cur_R = F[node] - k*(r - X[node] - 1)*(r - X[node] - 1);
        //cout << cur_L <<" "<<cur_R <<" "<<L <<" "<<R <<endl;
        if(cur_L > L && cur_R > R)
            return;
        if(cur_L < L && cur_R < R) {
            F[node] = val;
            X[node] = x;
            return;
        }
    }
    if(l == r)
        return;
    int mid = (l + r)/2;
    update(2*node,l,mid,val,x);
    update(2*node+1,mid+1,r,val,x);
}

long long get(int node,int l,int r,int v) {

    long long val = F[node] - k*(v - X[node] - 1)*(v - X[node] - 1);
    if(l == r)
        return val;
    int mid = (l+r)/2;
    if(v > mid)
        return max(val, get(2*node+1,mid+1,r,v));
    else
        return max(val, get(2*node, l, mid, v));

}
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    long long ans = 0;
    long long MAX = -(1ll<<60);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        long long v;
        cin >> v;
        MAX = max(MAX,v);
        long long tmp = max(v, v + get(1,1,n,i));
        ans = max(ans,tmp);
        update(1,1, n, tmp,i);
        //cout << get(1,1,n,i) << endl;
    }

    if(MAX < 0)
        cout << MAX;
    else
        cout << ans;
    return 0;
}

