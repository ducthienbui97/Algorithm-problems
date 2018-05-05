#include <bits/stdc++.h>
using namespace std;
void solve(int ntest) {
    int n;
    cin >> n;
    vector<int> counter(n, 0);
    vector<bool> sold(n,false);
    for(int i = 0 ; i < n; i++){
        int d;
        cin >> d;
        int minF = 1<<30;
        vector<int> minV;
        for(int i = 0; i < d; i++){
            int u;
            cin >> u;
            if(sold[u])
                continue;
            counter[u] ++;
            if(counter[u] < minF){
                minV.clear();
                minF = counter[u];
            }
            if(counter[u] == minF){
                minV.push_back(u);
            }
        }
        if(!minV.empty()){
            int u = minV[rand()%minV.size()];
            sold[u] = true;
            cout << u << endl;
        }
        else
            cout << -1 << endl;
    }
}
int main() {
    srand(time(NULL));
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
        solve(i);
}

