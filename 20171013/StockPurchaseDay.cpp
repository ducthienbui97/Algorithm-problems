#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n;
    vector<int> Min(n);
    for(int i = 0; i < n; i++){
        cin >> Min[i];
    }
    for(int i = n - 2; i >= 0; i--)
        Min[i] = min(Min[i], Min[i + 1]);
    cin >> m;
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        int l = 0, r = n - 1;
        int ans = -2;
        while(l <= r){
            int mid = (l+r)/2;
            if(Min[mid] <= x){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        cout  << ans + 1<< endl;
    }
    return 0;
}

