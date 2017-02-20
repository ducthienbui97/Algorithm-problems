#include <bits/stdc++.h>
#define elif else if
using namespace std;
const int Nb=2;
const int Maxn=1e5+20;
int Bs[]= {29,31,37};
int H[3][Maxn][Nb];
int P[Maxn][Nb];
char S[3][Maxn];
int Last[2];
int n,m;
int get(int fr,int to,int cnt,int nb) {
    return H[cnt][to][nb]-H[cnt][fr-1][nb]*P[to-fr+1][nb];
    }
bool ok(int fr1,int to1,int cnt1,int fr2,int to2,int cnt2) {
    for(int i=0; i<Nb; i++)
        if(get(fr1,to1,cnt1,i)!=get(fr2,to2,cnt2,i)) return false;
    return true;
    }
void Hash(int cnt) {
    int m=strlen(S[cnt]+1);
    for(int i=1; i<=m; i++)
        for(int j=0; j<Nb; j++)
            H[cnt][i][j]=H[cnt][i-1][j]*Bs[j]+S[cnt][i]-'A'+1;
    }
struct sbfx {
    int st,fn,cnt;
    bool operator<(const sbfx& X)const {
        int f,t,c;
        f=X.st;
        t=X.fn;
        c=X.cnt;
        if(S[c][f]==S[cnt][st]) {
            int l=0,r=min(t-f,fn-st);
            int k=0;
            while(l<=r) {
                int mid=(l+r)>>1;
                if(ok(f,f+mid,c,st,st+mid,cnt)) l=mid+1,k=mid;
                else r=mid-1;
                }
            if(k==min(t-f,fn-st))
                return fn-st<t-f;
            return S[c][f+k+1]>S[cnt][st+k+1];
            }
        else return S[c][f]>S[cnt][st];
        }
    };
vector<sbfx> lis;
void init() {
    P[0][0]=P[0][2]=P[0][1]=1;
    for(int i=1; i<Maxn; i++)
        for(int j=0; j<Nb; j++)
            P[i][j]=P[i-1][j]*Bs[j];
    n=strlen(S[0]+1);
    m=strlen(S[1]+1);
    for(int i=1; i<=n; i++)
        S[2][n-i+1]=S[0][i];
    for(int i=0;i<3;i++)
        Hash(i);
    sbfx a;
    a.fn=n;
    a.cnt=0;
    for(int i=1; i<=n; i++)
        a.st=i,lis.push_back(a);
    a.fn=m;
    a.cnt=1;
    for(int i=1; i<=m; i++)
        a.st=i,lis.push_back(a);
    sort(lis.begin(),lis.end());
    }
void read() {
    cin>>S[0]+1>>S[1]+1;
    init();
    }
int Max[Maxn];
void doit() {
    Last[0]=Last[1]=-1;
    for(int i=0; i<lis.size(); i++) {
        Last[lis[i].cnt]=i;
        if(Last[!lis[i].cnt]>=0) {
            int t=Last[!lis[i].cnt];
            if(S[lis[t].cnt][lis[t].st]==S[lis[i].cnt][lis[i].st]) {
                int l=0,r=min(lis[t].fn-lis[t].st,lis[i].fn-lis[i].st);
                int k=0;
                while(l<=r) {
                    int mid=(l+r)>>1;
                    if(ok(lis[t].st,lis[t].st+mid,lis[t].cnt,lis[i].st,lis[i].st+mid,lis[i].cnt)) l=mid+1,k=mid;
                    else r=mid-1;
                    }
                if(!lis[i].cnt)t=i;
                Max[lis[t].st]=max(Max[lis[t].st],k);
            }
        }
    }
}
bool ffind(int t){
    for(int i=1;i<=n;i++){
        if(Max[i]>=t&&ok(i,i+t,0,n-(i+t)+1,n-i+1,2)) return true;
    }
    return false;
}
main() {
    ios_base::sync_with_stdio(false);
    read();
    doit();
    int l=0,ans=0;
    int r=(min(n,m)-1)>>1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(ffind(mid<<1)) l=mid+1,ans=max(ans,(mid<<1)+1);
        else r=mid-1;
    }
    l=0,r=(min(n,m)-1)>>1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(ffind((mid<<1)+1)) l=mid+1,ans=max(ans,(mid+1)<<1);
        else r=mid-1;
    }
    printf("%d",ans);
    }
