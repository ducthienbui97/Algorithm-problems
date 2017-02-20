#include <bits/stdc++.h>
using namespace std;
int F[10011][22];
int T[10011][22][22];
int trie[1000111][2];
int size;
void insert(int v) {
    int cur = 0;
    for(int i=28; i >=0; i--) {
        int b = (v>>i)&1;
        if(!trie[cur][b]) {
            trie[cur][b] = ++size;
        }
        cur = trie[cur][b];
    }
}
int get(int v) {
    int cur = 0;
    int rep = 0;
    for(int i=28; i >=0; i--) {
        int b = (v>>i)&1;
        if(trie[cur][!b]) {
            cur = trie[cur][!b];
            rep |= (!b) << i;

        } else {
            cur = trie[cur][b];
            rep |= b << i;
        }
    }
    return rep;
}
int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >>m;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            cin >> F[i][j];
    for(int l=0; l<n; l++)
        for(int i=0; i<m; i++) {
            T[l][i][i] = F[l][i];
            for(int j=i+1; j<m; j++)
                T[l][i][j] = T[l][i][j-1]^F[l][i];
        }
    for(int l=1; l<n; l++)
        for(int i=0; i<m; i++)
            for(int j=i; j<m; j++)
                T[l][i][j] ^= T[l-1][i][j];
    int ans = 0;
    for(int i=0; i<m; i++)
        for(int j=i; j<m; j++) {
            memset(trie,0,sizeof trie);
            size = 0;
            insert(0);
            for(int l=0; l<n; l++) {
                ans = max(ans,get(T[l][i][j])^T[l][i][j]);
                insert(T[l][i][j]);
            }
        }
    cout << ans <<endl;
}
