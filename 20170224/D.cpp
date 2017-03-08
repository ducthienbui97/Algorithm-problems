#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> d;

int findr(int u) {
    if(d[u] != u) d[u] = findr(d[u]);
    return d[u];
}
main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    vector<int> r(n);
    vector<vector<int> > w(n);
    d.resize(m<<1);
    for(int i=0; i<2*m; i++)
        d[i] = i;
    for(int i=0; i<n; i++)
        cin >> r[i];
    for(int i=0; i<m; i++) {
        int x;
        cin >> x;
        for(int j=0; j<x; j++) {
            int y;
            cin >> y;
            w[--y].push_back(i);
        }
    }
    for(int i=0; i<n; i++) {
        int u,v;
        if(r[i]) {
            u = findr(w[i][0]);
            v = findr(w[i][1]);
            d[u] = v;
            u = findr(w[i][0] + m);
            v = findr(w[i][1] + m);
            d[u] = v;
        } else {
            u = findr(w[i][1]);
            v = findr(w[i][0] + m);
            d[u] = v;
            u = findr(w[i][0]);
            v = findr(w[i][1] + m);
            d[u] = v;
        }
    }

    for(int i=0; i<m; i++)
        if(findr(i) == findr(i + m)) {
            puts("NO");
            return 0;
        }
    puts("YES");

}
