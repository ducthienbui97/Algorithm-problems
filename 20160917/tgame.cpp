#include <bits/stdc++.h>
using namespace std;
struct cell {
    int sides[4];
    vector<int> next[4];
    int w;
    };
int n;
int full;
long long F[1<<20][4];
int bitToLo[1<<20];
vector<cell> v;
long long dp(int state,int last) {
    if(state == full) return 0;
    else if(F[state][last] >= 0) return F[state][last];
    int avl = full&(~state);
    for(int u = avl&-avl; u; avl -= u, u =avl&-avl) {
        int _u = bitToLo[u];
        for(int j =0; j < v[_u].next[last].size(); j++)
            F[state][last] = max(F[state][last],dp(state|u,v[_u].next[last][j])+v[_u].w);
        F[state][last] = max(F[state][last],dp(state|u,last));
        }
    return F[state][last];
    }
main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    memset(F,-1,sizeof F);
    full = (1 << n) - 1;
    for(int i = 0; i < n; i++)
        bitToLo[1<<i] = i;
    v.resize(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j ++) {
            cin >> v[i].sides[j];
            }
        for(int j = 0; j < 4; j ++) {
            v[i].next[v[i].sides[j]].push_back(v[i].sides[(j+2)&3]);
            }
        cin >> v[i].w;
        }
    if(n <= 20) {
        long long ans = -1;
        for(int i = 0; i < 4; i++) {
            ans = max(ans,dp(0,i));
            }
        cout << ans <<endl;
        }
    else {

        }
    }

/*
4
1 1 1 1 12412
2 2 2 2 5124
3 3 3 3 4
0 0 0 0 3
*/
