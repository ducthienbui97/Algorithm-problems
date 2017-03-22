#include <bits/stdc++.h>
using namespace std;
int cnt[2][1024];
int main(){
    ios_base::sync_with_stdio(false);
    int n,k,x;
    bool ok = true;
    cin >> n >> k >> x;
    for(int i=0;i<n;i++){
        int v; cin >> v;
        cnt[0][v]++;
    }
    for(int i=0;i<k && ok;i++){
        int r = 0;
        memset(cnt[!(i&1)],0,sizeof cnt[!(i&1)]);

        for(int v=0;v<1024;v++){
            int t = (cnt[i&1][v] + r)/2;
            cnt[!(i&1)][v] += t;
            cnt[!(i&1)][v^x] += (cnt[i&1][v] - t);
            r = (r + cnt[i&1][v])&1;

        }
        ok = false;
        for(int v=0;v<1024;v++)
            ok |= (cnt[!(i&1)][v] != cnt[i&1][v]);

    }
    vector<int> d;
    for(int v=0;v<1024;v++)
        if(cnt[(k&1)][v]) d.push_back(v);
    cout << *max_element(d.begin(),d.end()) <<" "<< *min_element(d.begin(),d.end())<<endl;
}
