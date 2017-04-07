#include <bits/stdc++.h>
using namespace std;
map<long long,long long> fee;
main(){
    ios_base::sync_with_stdio(false);
    int q;
    for(cin >> q; q > 0; q--){
        int t;
        long long u,v,w;
        cin >> t >> u >> v;
        if(t == 1){
            cin >> w;
            while(u!=v){
                if(u > v){
                    fee[u] += w;
                    u>>=1;
                }else{
                    fee[v] += w;
                    v>>=1;
                }
            }
        }else{
            long long ans = 0;
            while(u!=v){
                if(u > v){
                    ans += fee[u];
                    u >>=1;
                }else{
                    ans += fee[v];
                    v>>=1;
                }
            }
            cout << ans <<endl;
        }
    }
}
