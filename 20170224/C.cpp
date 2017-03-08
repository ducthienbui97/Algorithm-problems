#include <bits/stdc++.h>
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    int n,k;
    long long sum = 0;
    cin >> n >> k;
    map<long long,int> cnt;
    cnt[0] = 1;
    long long ans = 0;
    long long MIN = 0;
    long long MAX = 0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        sum += x;
        if(cnt.find(sum-1)!=cnt.end())
            ans += cnt[sum - 1];
        if(k == -1 && cnt.find(sum + 1) != cnt.end())
            ans += cnt[sum + 1];
        if(abs(k) > 1){
            for(long long tmp = k;(sum - tmp >= MIN && tmp > 0) || (sum - tmp <= MAX && tmp < 0);tmp*=k*k){
                if(cnt.find(sum-tmp) != cnt.end())
                    ans += cnt[sum - tmp];
            }
            for(long long tmp = k*k;sum - tmp >= MIN;tmp*=k*k){
                if(cnt.find(sum-tmp) != cnt.end())
                    ans += cnt[sum - tmp];
            }
        }
        cnt[sum] ++;
        MIN = min(MIN,sum);
        MAX = max(MAX,sum);
    }
    cout << ans <<endl;
}
