#include <bits/stdc++.h>
using namespace std;
const int Max = 1e5+20;
int x[Max];
long long s[Max];
int cnt[Max];
vector<pair<long long,int> > queries;
int get(int idx){
    int rep = 0;
    while (idx > 0){
        rep += cnt[idx];
        idx -= (idx & -idx);
    }
    return rep;
}
void update(int idx){
    while (idx < Max){
        cnt[idx] ++;
        idx += (idx & -idx);
    }
}
main(){
    ios_base::sync_with_stdio(false);
    int n;
    long long m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> x[i];
    int ans = 0;
    int done = 0;
    for(int i=1;i<=n;i++){
        s[i] = s[i-1]+x[i];
        if(s[i] <= m) ans ++;
    }
    for(int i=1;i<=n;i++){
        queries.push_back(make_pair(s[i],i));
        queries.push_back(make_pair(s[i]+m,n+i));
    }
    sort(queries.begin(),queries.end());
    for(int i=0;i<queries.size();i++){
        long long v = queries[i].first;
        int idx = queries[i].second;
        if(idx > n){
            ans += done - get(idx - n);
        }else{
            done ++;
            update(idx);
        }
    }
    cout << 2.0*ans/(1ll*n*(n+1));
}
