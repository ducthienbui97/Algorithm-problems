#include <bits/stdc++.h>

using namespace std;
int rol[11];
int A[11][11];
int C[11][11];
int ans;
int n,m;
void bt(int t){
    if(t == m){
        int tmp = 0;
        for(int j = 0; j < m; j++)
            for(int i = 0; i < n; i++)
                C[i][j] = A[i][j] + rol[j];
        for(int i = 0 ; i < n; i++){
            int c[3] = {0,0,0};
            for(int j = 0; j < m; j++)
                c[C[i][j]%3]++;
            tmp += max(max(c[0],c[1]),c[2]);
        }

        ans = max(ans,tmp);
        return;
    }
    for(int i = 0; i < 3;i++){
        rol[t] = i;
        bt(t + 1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> A[i][j];
        }
    bt(0);
    cout << ans << endl;
}



