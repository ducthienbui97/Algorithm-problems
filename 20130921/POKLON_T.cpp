#include <bits/stdc++.h>
using namespace std;
struct houses {
    int h,d;
    bool operator < (const houses& x ) const {
        return x.d!=d?d>x.d:h<x.h;
        }
    };
const int Maxn=100011;
int ans[Maxn];
vector<int> stf;
vector<int> Ans;
houses a[Maxn];
main() {
    int n;
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>a[i].h>>a[i].d;
        }
    stf.push_back(INT_MIN);
    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++) {
        int k=upper_bound(stf.begin(),stf.end(),a[i].h)-stf.begin();
        ans[i]=k;
        if(k==stf.size()) stf.push_back(a[i].h);
        else stf[k]=a[i].h;
    }
    stf.pop_back();
    printf("%d\n",stf.size());
    int Last=INT_MAX;
    for(int i=n;i>0;i--)
    if(ans[i]==stf.size()&&a[i].h<=Last){
            Last=a[i].h;
            stf.pop_back();
            Ans.push_back(i);
    }
    for(int i=Ans.size()-1;i>=0;i--){
        printf("%d %d\n",a[Ans[i]].h,a[Ans[i]].d);
    }
}
