#include <bits/stdc++.h>
using namespace std;
long long ans;
int n,m;
vector<int> k;
vector<int> l;
vector<vector<int> > a;
vector<vector<int> > c;
vector<int> use;
vector<pair<int,long long> > st;
set<pair<int,long long> > ms;
void bt(int cur,int mx,int used,long long bst,bool tm){
    if(used > m) return;
   // cout << cur <<" "<<mx <<" "<<used <<" "<<bst <<endl;
    if(cur == mx){
        if(tm){
            st.push_back(make_pair(m - used,bst));
        }else{
            auto it = ms.lower_bound(make_pair(used,0));
            if(it != ms.end())
                ans = max(ans,it->second+bst);

        }
    }else
    for(int i=0;i<a[use[cur]].size();i++){
        bt(cur+1,mx,used+c[use[cur]][i],bst+a[use[cur]][i],tm);
    }
}
void cal(){
    ms.clear();
    st.clear();
    bt(0,4,0,0,1);
    sort(st.begin(),st.end());
    long long mx = -1;
    for(int i=st.size()-1;i>=0;i--){
        if(st[i].second > mx){
            mx = st[i].second;
            ms.insert(st[i]);
        }
    }
    bt(4,8,0,0,0);
}
void choose(int cur){
    if(use.size() == 8) cal();
    else if(cur >= n) return;
    else{
        choose(cur + 1);
        use.push_back(cur);
        choose(cur + 1);
        use.pop_back();
    }
}
void solve(int nTest){
    cin >> m >> n;
    ans  = 0;
    k.resize(n);l.resize(n);a.resize(n);c.resize(n);
    for(int i=0;i<n;i++){
        cin >> k[i] >> l[i];
        int pw = 0;
        int cu = 0;
        a[i].clear();
        c[i].clear();
        for(int it=1;it<=k[i];it++){
            cin >> pw;
            if(it>=l[i])a[i].push_back(pw);
        }
        c[i].push_back(0);
        pw = 0;
        for(int it=1;it<k[i];it++){
            cin >> cu;
            if(it >= l[i]) pw += cu, c[i].push_back(pw);
        }
    }
    choose(0);
    cout <<"Case #"<<nTest<<": "<<ans<<endl;
}
main(){
    freopen("D-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)solve(i);
}

