#include <bits/stdc++.h>
#define mp make_pair
#define int long long
using namespace std;
const int Max=1e5+30;
int L[Max],A[Max],K[Max],F[Max];
int tl[Max],ta[Max],tk[Max];
int n;
int S[Max<<3],D[Max<<3];
vector<int> lis;
void update(int node,int l,int r,int u,int v,int s,int d){
    if(l>r||u>r||v<l) return;
    if(S[node]>0&&S[node]+D[node]*(max(L[l],L[u])-L[l])<=s+d*(max(L[l],L[u])-L[u])
    && S[node]+D[node]*(min(L[v],L[r])-L[l])<=s+d*(min(L[v],L[r])-L[u])) return;
    if(u<=l&&r<=v){
        if(S[node]==-1||(S[node]>=s+d*(L[l]-L[u])
        && S[node]+D[node]*(L[r]-L[l])>=s+d*(L[r]-L[u]))){
            S[node]=s+d*(L[l]-L[u]);
            D[node]=d;
            return;
        }
   }
    update(node<<1,l,(l+r)>>1,u,v,s,d);
    update(((node<<1)+1),((l+r)>>1)+1,r,u,v,s,d);

}
int get(int node,int l,int r,int v){
    if(l<=v&&v<=r){
        int tmp=S[node]+D[node]*(L[v]-L[l]);
        if(S[node]==-1) tmp=1000000000000000000ll;
        if(l==r) return tmp;
        return min(tmp,min(get(node<<1,l,(l+r)>>1,v),get((node<<1)+1,((l+r)>>1)+1,r,v)));
    }
    return 1000000000000000000ll;
}
int get(int t){
    if(t<1||t>n) return 1000000000000000000ll;
    return get(1,1,n,t);
}
int id[Max];
bool cmp(int x,int y){
    return tl[x]<tl[y];
}
void doit(){
    int d,s,t;
    cin>>n>>d>>s>>t;
    lis.clear();
    bool d1=false,d2=false;
    memset(F,-1,sizeof F);
    memset(S,-1,sizeof S);
    memset(D,-1,sizeof D);
    for(int i=1;i<=n;i++){
        cin>>tl[i]>>ta[i]>>tk[i];
        lis.push_back(tl[i]);
        id[i]=i;
    }
    sort(id+1,id+n+1,cmp);
    for(int i=1;i<=n;i++){
        L[i]=tl[id[i]];
        A[i]=ta[id[i]];
        K[i]=tk[id[i]];
        if(!d1&&s==id[i]) d1=true,s=i;
        if(!d2&&t==id[i]) d2=true,t=i;
    }

    sort(lis.begin(),lis.end());
    int l=lower_bound(lis.begin(),lis.end(),L[s]-K[s])-lis.begin()+1;
    int r=upper_bound(lis.begin(),lis.end(),L[s]+K[s])-lis.begin();
    int Tl=l,Tr=r;
    update(1,1,n,l,s,(L[s]-L[l])*A[s],-A[s]);
    update(1,1,n,s,r,0,A[s]);
    F[s]=0;
    l=s-1;
    r=s+1;
    while(l>=Tl||r<=Tr){
        int ll,rr,tmp1,tmp2;
        if(l>=Tl) tmp1=get(l);
        else tmp1=get(0);
        if(r<=Tr) tmp2=get(r);
        else tmp2=get(0);
        if(tmp1>tmp2){
            F[r]=tmp2;
             ll=lower_bound(lis.begin(),lis.end(),L[r]-K[r])-lis.begin()+1;
             rr=upper_bound(lis.begin(),lis.end(),L[r]+K[r])-lis.begin();
            update(1,1,n,ll,r,F[r]+d+(L[r]-L[ll])*A[r],-A[r]);
            update(1,1,n,r,rr,F[r]+d,A[r]);
            ++r;
        }
        else{
            F[l]=tmp1;
             ll=lower_bound(lis.begin(),lis.end(),L[l]-K[l])-lis.begin()+1;
             rr=upper_bound(lis.begin(),lis.end(),L[l]+K[l])-lis.begin();
            update(1,1,n,ll,l,F[l]+d+(L[l]-L[ll])*A[l],-A[l]);
            update(1,1,n,l,rr,F[l]+d,A[l]);
            --l;
        }
        Tl=min(Tl,ll);
        Tr=max(Tr,rr);
    }
    printf("%lld\n",F[t]);
}
main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) doit();
}

