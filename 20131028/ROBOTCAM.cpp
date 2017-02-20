#include <bits/stdc++.h>
#define elif else if
using namespace std;
vector<pair<int,int> > d;
vector<int> a,stf;
main() {
    freopen("ROBOTCAM.INP","r",stdin);
    freopen("ROBOTCAM.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    d.resize(n);
    a.resize(n);
    for(int i=0;i<n;i++)
        cin>>d[i].first>>d[i].second;
    sort(d.begin(),d.end());
    int k=0;
    for(int i=0;i<n;i++)
        a[i]=-d[i].second;
    stf.push_back(-(1<<30));
    for(int i=0;i<n;i++){
        int t=lower_bound(stf.begin(),stf.end(),a[i])-stf.begin();
        if(t==stf.size()) stf.push_back(a[i]);
        else stf[t]=a[i];
    }
    printf("%d",stf.size()-1);
}
