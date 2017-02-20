#include <bits/stdc++.h>
using namespace std;
const int Maxn=100011;
int n,m,q;
vector<int> lis[Maxn];
long long a[Maxn];
long long suma[Maxn];
int bigid[Maxn];
int connect[Maxn][400];
bool vs[Maxn];
long long addtobig[Maxn];
vector<int> lisbig;
bool inbig(int t) {
    return t>=310;
    }
long long check(int id) {
    long long ans=suma[id];
    if(!bigid[id]) {
        ans=0LL;
        for(int i=0; i<lis[id].size(); i++)
            ans+=a[lis[id][i]];
        }
    for(int i=0; i<lisbig.size(); i++) {
        ans+=addtobig[i]*(long long) connect[id][i];
        }
    return ans;
    }
void add(int id,int k) {
    if(bigid[id]) {
        addtobig[bigid[id]-1]+=k;
        }
    else {
        for(int i=0; i<lis[id].size(); i++)
            a[lis[id][i]]+=k;
        for(int i=0; i<lisbig.size(); i++) {
            suma[lisbig[i]]+=1LL*k*connect[id][i];
            }
        }
    }
main() {
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>q;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    int x,y;
    for(int i=1; i<=m; i++) {
        cin>>x;
        while(x--) {
            cin>>y;
            lis[i].push_back(y);
            suma[i]+=a[y];
            }
        if(inbig(lis[i].size())) lisbig.push_back(i),bigid[i]=lisbig.size();
        }
    for(int i=0; i<lisbig.size(); i++) {
        int b=lisbig[i];
        memset(vs,0,sizeof vs);
        for(int j=0; j<lis[b].size(); j++)
            vs[lis[b][j]]=true;
        for(int j=1; j<=m; j++)
            for(int l=0; l<lis[j].size(); l++)
                if(vs[lis[j][l]]) connect[j][i]++;
        }
    string s;
    while(q--) {
        cin>>s;
        if(s[0]=='?') {
            int id;
            cin>>id;
            cout<<check(id)<<endl;
            }
        else {
            int id,k;
            cin>>id>>k;
            add(id,k);
            }

        }
    }
