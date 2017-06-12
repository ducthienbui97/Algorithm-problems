#include<bits/stdc++.h>
using namespace std;
const int MaxA = 1e6 + 10;
const int Maxn = 1e5 + 10;
vector<int> primes;
vector<pair<int,int> > pk[MaxA];
bool notPrime[MaxA];
bool inList[MaxA];
vector<pair<int,int> > IT[Maxn << 3];
vector<pair<int,int> > S[Maxn << 3];
vector<int> v;
void era() {
    notPrime[0] = true;
    notPrime[1] = true;
    for(int i=0; i<MaxA; i++)
        if(!notPrime[i]) {
            primes.push_back(i);
            for(int j=i+i; j<MaxA; j+=i){
                notPrime[j] = true;
                if(!inList[j]) continue;
                int t = j;
                int cnt = 0;
                while(t%i == 0){
                    cnt++;
                    t/=i;
                }
                pk[j].emplace_back(i,cnt);
            }
            if(inList[i]) pk[i].emplace_back(i,1);
        }
}
void init(int node,int l,int r){
    if(l == r){
        for(auto&p:pk[v[l-1]]) IT[node].push_back(p);
        sort(IT[node].begin(),IT[node].end());
    }else{
        init(2*node,l,(l+r)/2);
        init(2*node+1,((l+r)/2)+1,r);
        for(int i=0,j=0; i < IT[2*node].size() || j < IT[2*node+1].size();){
            if(i == IT[2*node].size()) IT[node].push_back(IT[2*node + 1][j++]);
            else if(j == IT[2*node + 1].size()) IT[node].push_back(IT[2*node][i++]);
            else if(IT[2*node][i].first < IT[2*node+1][j].first) IT[node].push_back(IT[2*node][i++]);
            else if(IT[2*node][i].first > IT[2*node+1][j].first) IT[node].push_back(IT[2*node + 1][j++]);
            else{
                IT[node].emplace_back(IT[2*node][i].first,IT[2*node][i].second + IT[2*node+1][j].second);
                i++;j++;
            }
        }
    }
    S[node].emplace_back(0,0);
    for(int i=0;i<IT[node].size();i++){
        S[node].emplace_back(IT[node][i].first,S[node][i].second + IT[node][i].second);
    }
}
int get(int node,int l,int r,int X,int Y,int L,int R){
    if(l > Y || r < X) return 0;
    if(X <= l && r <= Y){
        int up = upper_bound(S[node].begin(),S[node].end(),make_pair(R,1<<30)) - S[node].begin() - 1;
        int dw = upper_bound(S[node].begin(),S[node].end(),make_pair(L,0)) - S[node].begin() - 1;
        return S[node][up].second - S[node][dw].second;
    }
    else{
        int LL = get(2*node,l,(l+r)/2,X,Y,L,R);
        int RR = get(2*node+1,(l+r)/2+1,r,X,Y,L,R);
        return LL + RR;
    }
}
void solve() {
    int n;
    cin >> n;
    v.resize(n);
    for(auto&u:v){
        cin >> u;
        inList[u] = true;
    }
    era();
    init(1,1,n);
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int X,Y,L,R;
        cin >> L >> R >> X >> Y;
        cout << get(1,1,n,L,R,X,Y) <<endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i=0; i<t; i++) solve();
}


