#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(false);
    int n;
    vector<int> values;
    vector<int> f;
    cin >> n;
    f.resize(n);
    for(int i=0;i<f.size();i++){
        cin >>  f[i];
        values.push_back(f[i]-1);
    }
    bool ok = true;
    sort(values.begin(),values.end());
    values.resize(unique(values.begin(),values.end()) - values.begin());
    for(int i=0;i < values.size(); i++)
        if(f[values[i]] -1 != values[i] ) ok = false;
    if(!ok){
        cout << -1;
        return  0;
    }
    cout << values.size() <<endl;
    for(int i=0;i<f.size();i++)
        cout << (upper_bound(values.begin(),values.end(),f[i]-1) - values.begin())<< ' ';
    cout << endl;
    for(int i=0;i<values.size();i++)
        cout << values[i]+1 <<' ';
}
