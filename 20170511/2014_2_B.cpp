#include <bits/stdc++.h>
using namespace std;
void solve(int nTest){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int ans = 0;
    while(v.size()){
        int Min = 0;
        for(int i=0;i<v.size();i++)
            if(v[i] < v[Min]) Min = i;
        int cnt = 0;
        for(int i=Min+1;i<v.size();i++){
            swap(v[i-1],v[i]);
            cnt++;
        }
        v.pop_back();
        ans += min(cnt,Min);
    }
    cout << "Case #"<<nTest<<": "<<ans<<endl;
    }
main(){
    freopen("B-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}

