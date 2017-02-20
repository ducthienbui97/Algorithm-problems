#include <bits/stdc++.h>
using namespace std;
vector<int> r;
vector<int> w;
vector<int> m;
int findroot(int p){
    if(r[p] == p) return r[p];
    return r[p] = findroot(r[p]);
}
const int base = 1e9+7;
main(){
    ios_base::sync_with_stdio(false);
    int n1,n2;
    cin >> n1 >> n2;
    r.resize(n1+n2),w.resize(n1+n2),m.resize(n1+n2);
    for(int i=0;i<n1+n2;i++){
        r[i] = i;
        if(i<n1){
            m[i] = 1;
            w[i] = 0;
        }else{
            w[i] = 1;
            m[i] = 0;
        }
    }
    int q1;
    cin >> q1;
    for(int i=0;i<q1;i++){
        int x,y;
        cin >>x>>y;
        x = findroot(x-1);
        y = findroot(y-1);
        if(x != y){
            r[x] = y;
            m[y] += m[x];
            w[y] += w[x];
        }
    }
    cin >> q1;
    for(int i=0;i<q1;i++){
        int x,y;
        cin >>x>>y;
        x = findroot(n1+x-1);
        y = findroot(n1+y-1);
        if(x != y){
            r[x] = y;
            m[y] += m[x];
            w[y] += w[x];
        }
    }
    cin >> q1;
    for(int i=0;i<q1;i++){
        int x,y;
        cin >>x>>y;
        x = findroot(x-1);
        y = findroot(n1+y-1);
        if(x != y){
            r[x] = y;
            m[y] += m[x];
            w[y] += w[x];
        }
    }
    long long ans = 0;
    for(int i=0;i<n1;i++){
        ans += (n2-w[findroot(i)]);
    }
    for(int i=0;i<n2;i++){
        ans += (n1-m[findroot(n1+i)]);
    }
    cout << ans/2;
}
