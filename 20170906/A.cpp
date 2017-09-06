#include <bits/stdc++.h>
using namespace std;
priority_queue <pair<int,int> > pr;
main(){
    ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<int> c(n);
    vector<int> vans(n);
    for(auto&u:c)
        cin >> u;
    long long ans = 0;
    long long total = 0;
    int cnt = 0;
    for(int i = 0; i < k; i++){
        total += c[i];
        pr.emplace(c[i],i);
        ans += total;
        cnt ++;
    }
    for(int i = k; i < n; i++){
        total += c[i];
        pr.emplace(c[i],i);
        total -= pr.top().first;
        ans += total;
        vans[pr.top().second] = ++cnt;
        pr.pop();
    }
    while(!pr.empty()){
        total -= pr.top().first;
        ans += total;
        vans[pr.top().second] = ++cnt;
        pr.pop();
    }
    cout << ans <<'\n';
    for(int u:vans)
        cout << u <<' ';
    return 0;

}
