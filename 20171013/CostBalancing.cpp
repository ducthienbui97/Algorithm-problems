#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    int total = 0;
    vector<int> spent(m,0);
    for(int i=0; i < n; i++) {
        int x, s;
        cin >> x >> s;
        spent[x - 1] += s;
        total += s;
    }
    int each = total/m;
    int more = total%m;
    for(int i = 0; i < m; i++) {
        spent[i] -= each;
    }
    spent[0] -= more;
    for(int i=0; i<m; i++) {
        cout << i +1 <<" "<<spent[i] << endl;
    }
    return 0;
}
