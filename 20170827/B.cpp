#include <bits/stdc++.h>
using namespace std;
void solve(int ntest){
    int n;
    cin >> n;
    vector<int> v (n);
    map<long long,long long> mp;
    map<int,long long> cnt;
    for(auto&u:v)
        cin >> u;
    sort(v.begin(),v.end());
    for(int i = 0; i < v.size(); i++){
        int j = i;
        while(j + 1 < v.size() && v[j + 1] == v[i]) j++;
        if(j != i)
            mp[2*v[i]] = (j - i + 1)*(j - i) / 2; 
        cnt[v[i]] = j - i + 1;
        i = j;
    }
    long long total = 0;
    long long ans = 0;
    mp[0] = 0;
    for(auto&it: mp){
        it.second += total;
        total = it.second;
    }
    v.resize(unique(v.begin(),v.end()) - v.begin());
    for(int i = 0; i < v.size(); i++)
    for(int j = 0; j < i; j++){
        int dif = v[i] - v[j];
        auto it = mp.upper_bound(dif);
        while(it == mp.end() || (it -> first) > dif) it --;
        long long tmp =  total - it -> second;
        if(2*v[i] > dif){
            tmp -= cnt[v[i]]*(cnt[v[i]] - 1) / 2;
        }
        if(2*v[j] > dif){
            tmp -= cnt[v[j]] * (cnt[v[j]] - 1) / 2;
        }
        ans += tmp * cnt[v[i]] * cnt[v[j]];
        if(2*v[i] > dif){
            ans += cnt[v[i]]*(cnt[v[i]] - 1)*(cnt[v[i]] - 2) / 6 * cnt[v[j]];
        }
        if(2*v[j] > dif){
            ans += cnt[v[j]]*(cnt[v[j]] - 1)*(cnt[v[j]] - 2) / 6 * cnt[v[i]];
        }
    }
    cout << "Case #" << ntest <<": " << ans <<endl;
}
main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    for(int i = 1; i <= test; i++)
        solve(i);
}