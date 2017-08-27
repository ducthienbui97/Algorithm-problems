#include <bits/stdc++.h>
using namespace std;
map<int,int> F[333];
int pw[333];
set<int> hs[333];
void solve(int ntest){
    int n;
    string  s;
    cin >> s;
    n = s.size();
    pw[0] = 1;

    for(int i = 0; i < n; i++){
        hs[i].clear();
        F[i].clear();
        pw[i + 1] = pw[i]*31;
    }

    for(int i = 0; i < n; i++){
        int h = 0;
        for(int j = i; j < n; j++){
            h = h*31 + s[j] - 'a' + 1;
            hs[j].insert(h);
        }
    }
    for(int i = 1; i < n; i++)
        for(int v: hs[i - 1])
            hs[i].insert(v);
    F[0][0] = 1;
    for(int i = 1; i < n; i++){
        int h = 0;
        for(auto&it: F[i - 1])
            F[i][it.first] = it.second + 1;
        for(int j = i; j > 0; j--){
            h = h + pw[i - j] * (s[j] - 'a' + 1);
            if(hs[j -1].find(h) != hs[j - 1].end()){
                if(F[i].find(h) == F[i].end())
                    F[i][h] = 1 << 30;
                for(auto&it: F[j - 1])
                    if(it.first == h){
                        F[i][h] = min(F[i][h], it.second + 1);
                    }else{
                        F[i][h] = min(F[i][h], it.second + 2);
                    } 
            }
        }
    }
    int ans = 1 << 30;
    for(auto&it : F[n-1])
        ans = min(ans, it.second);
    cout << "Case #" << ntest <<": " << ans <<endl;
}
main(){
    freopen("test.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    for(int i = 1; i <= test; i++)
        solve(i);
}