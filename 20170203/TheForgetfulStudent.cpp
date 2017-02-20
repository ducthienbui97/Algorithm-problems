#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    vector<int> v;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    cin >> q;
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        int tmp = lower_bound(v.begin(),v.end(),x) - v.begin();
        if(tmp >= v.size() || v[tmp] != x) cout << "NO "<<tmp<<endl;
        else cout <<"YES "<<tmp<<endl;
    }
}
