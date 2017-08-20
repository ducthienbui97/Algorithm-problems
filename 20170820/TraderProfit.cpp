#include <bits/stdc++.h>

using namespace std;

int traderProfit(int k, int n, vector <int> A) {
    // Complete this function
    vector< vector<int> > F(n + 1, vector<int> (k + 1, 0));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= k; j++){
            F[i][j] = max(F[i - 1][j], F[i][j - 1]);
            for(int l = 1; l < i; l++) if(A[i - 1] > A[l - 1]){
                F[i][j] = max(F[i][j], F[l - 1][j - 1] + A[i - 1] - A[l - 1]);
            }
        }
    return F[n][k];
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        int result = traderProfit(k, n, arr);
        cout << result << endl;
    }
    return 0;
}

