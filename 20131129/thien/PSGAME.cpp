#include <iostream>
#include <cstdio>
#include <cstring>
#define mp make_pair
#include <string>
#include <vector>
#include <algorithm>
#define elif else if
using namespace std;
vector<int> lis;
vector<int> a;
int m;
vector<pair<int,int> > ans;
main() {
   freopen("PSGAME.INP","r",stdin);
    freopen("PSGAME.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    lis.resize(6);
    for(int i=0;i<6;i++)
        cin>>lis[i];
    a=lis;
    reverse(a.begin(),a.end());
    cin>>m;
    for(int i=1;i<=5;i++)
    for(int j=5;j>=i;j--){
        ans.push_back(mp(j,2));
        ans.push_back(mp(j+1,3));
        ans.push_back(mp(j,4));
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
}
