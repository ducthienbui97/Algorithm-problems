#include <bits/stdc++.h>

using namespace std;

int minimumTime(vector <int> x) {
    sort(x.begin(),x.end());
    return x.back() - x[0];
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> x(n);
        for(int x_i = 0; x_i < n; x_i++){
           cin >> x[x_i];
        }
        int result = minimumTime(x);
        cout << result << endl;
    }
    return 0;
}

