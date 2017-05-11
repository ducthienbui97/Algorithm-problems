#include <bits/stdc++.h>
using namespace std;
void solve(int nTest){
    int n, s;
    cin >> n >> s;
    deque<int> v(n);
    for(int i=0;i<v.size();i++)
        cin >> v[i];
    sort(v.begin(),v.end());
    int ans = 0;
    while(v.size()){
        int b = v.back();
        v.pop_back();
        if(v.size() && b + v.front() <= s) v.pop_front();
        ans++;
    }
    cout << "Case #"<<nTest<<": "<<ans<<endl;
    }
main(){
    freopen("A-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}
