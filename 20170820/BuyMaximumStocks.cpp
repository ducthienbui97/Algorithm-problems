#include <bits/stdc++.h>

using namespace std;

long buyMaximumProducts(int n, long k, vector <int> a) {
    vector<long> cnt(101,0);
    for(int i = 0; i < a.size();i ++)
        cnt[a[i]] += i+1;
    long rep = 0;
    for(int i = 1; i < cnt.size(); i++){
        long num = min(cnt[i], k/i);
        rep += num;
        k -= num*i;
    }
    return rep;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    long k;
    cin >> k;
    long result = buyMaximumProducts(n, k, arr);
    cout << result << endl;
    return 0;
}
