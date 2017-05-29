#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5+20;
long long OverR[Maxn<<3];
vector<pair<int,int> > UndeL[Maxn<<3];
vector<long long> S[Maxn<<3];
vector<long long> Cos[Maxn<<3];
vector<int> Min[Maxn<<3];
int w[Maxn];
int g[Maxn],p[Maxn];
int n,q;


void init(int node,int l,int r){
    if(l > r) return;
    long long s = 0;
    long long cos = 0;
    if(l==r){
        OverR[node] = max(0,g[l] - w[l]);
        UndeL[node].emplace_back(max(0,w[l] - g[l]),p[l]);
    }
    else{
        init(2*node,l,(l+r)/2);
        init(2*node+1,(l+r)/2+1,r);
        OverR[node] = OverR[2*node+1];
        long long Over = OverR[2*node];

        for(auto&u: UndeL[2*node]){
            UndeL[node].push_back(u);
        }
        int mmin = -Min[2*node].back();
        //cout << mmin <<endl;
        for(auto&u: UndeL[2*node+1]){
            if(Over > u.first){
                Over -= u.first;
                UndeL[node].emplace_back(0,min(mmin,u.second));
            }else{
                UndeL[node].emplace_back(u.first-Over,min(mmin,u.second));
                Over = 0;
            }
        }
        OverR[node] += Over;
    }
    for(auto&u: UndeL[node]){
            s += u.first;
            cos += 1ll*u.first*u.second;
            S[node].push_back(s);
            Cos[node].push_back(cos);
            Min[node].push_back(-u.second);
            //cout << S[node].back() <<" "<<Cos[node].back() <<" "<<Min[node].back() <<endl;

        }

}
void getOver(int node,int l,int r,int u,int v,long long& Over,long long& ans,int &mmin){
    //cout << node <<" "<<l <<" "<<r <<" "<<u <<" "<<v<<endl;
    if(u > r || v < l || u > v) return;
    if(u <= l && r <= v){
        int idx1 = upper_bound(S[node].begin(),S[node].end(),Over) - S[node].begin();
        //cout <<idx1 <<" "<<S[node].back() <<"++"<<Over <<endl;
        if(idx1 >= S[node].size()){
            Over -= S[node].back() - OverR[node];
            mmin = min(mmin,-Min[node].back());
            return;
        }
        int idx2 = upper_bound(Min[node].begin(),Min[node].end(),-mmin) - Min[node].begin();
        //cout << node <<" "<<l<<" "<<r<<":\n";
        //cout << ans <<endl;
        //cout << mmin <<" "<<idx2 <<" "<<idx1<<" "<<Min[node].back()<<endl;
        if (idx2 >= S[node].size()){
            //cout << S[node].back() <<"~~"<<Over <<endl;
            ans += 1ll*(S[node].back() - Over)*mmin;
        }else if(idx2 <= idx1) {
            ans -= 1ll*(S[node][idx1] - Over)*Min[node][idx1];
            ans += Cos[node].back() - Cos[node][idx1];
        }else{
            ans += 1ll*(S[node][idx2-1] - Over)*mmin;
            ans += Cos[node].back() - Cos[node][idx2-1];
        }
        mmin = min(mmin,-Min[node].back());
        Over = OverR[node];
    }
    else{
        getOver(2*node,l,(l+r)/2,u,v,Over,ans,mmin);
        getOver(2*node+1,(l+r)/2+1,r,u,v,Over,ans,mmin);
    }
}
long long solve(int fr,int to){
    long long ans = 0;
    long long Over = 0;
    int Min = 1<<30;
    getOver(1,1,n-1,fr,to-1,Over,ans,Min);
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i=1;i<n;i++)
        cin >> w[i];
    for(int i=1;i<=n;i++)
        cin >> g[i] >> p[i];
    init(1,1,n-1);
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        cout << solve(l,r) <<endl;
    }
}
/*
6 4
2 6 1 5 3
0 3
4 2
3 1
1 4
4 6
9 3
2 5
1 6
3 5
4 6
*/
