#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
using namespace std;
#define pb push_back
#define mp make_pair
#define input "PROCRAS.INP"
#define output "PROCRAS.OUT"
typedef pair<int,int> pi;
void openfile() {
    freopen(input,"r",stdin);
    freopen(output,"w",stdout);
    }
vector<pi> pr;
main() {
#ifndef HYQ
    openfile();
#endif // HYQ
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    pr.resize(n);
    for(int i=0; i<n; i++)
        cin>>pr[i].second>>pr[i].first;
    sort(pr.begin(),pr.end());
    int cnt=INT_MAX;
    for(int i=n-1; i>=0; i--) {
        cnt=min(cnt,pr[i].first);
        cnt-=pr[i].second;
        }
    cout<<cnt<<endl;
    }
