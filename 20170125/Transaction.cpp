#include <bits/stdc++.h>
using namespace std;
const int MAX =100011;
vector<int> IT[MAX<<3];
int a[MAX];
void init(int node,int l,int r){
    if(l!=r){
        init(node<<1,l,(l+r)>>1);
        init((node<<1)+1,((l+r)>>1)+1,r);
    }
    for(int i=l;i<=r;i++)
        IT[node].push_back(a[i]);
    sort(IT[node].begin(),IT[node].end());
}
int query(int node,int l,int r,int pl,int vl){
    if(l==r) return a[l];
    int tmp = IT[node<<1].size() - (lower_bound(IT[node<<1].begin(),IT[node<<1].end(),vl)-IT[node<<1].begin());
    if(pl <= tmp) return query(node<<1,l,(l+r)>>1,pl,vl);
    else return query((node<<1)+1,((l+r)>>1)+1,r,pl-tmp,vl);
}
main(){
    ios_base::sync_with_stdio(false);
    int t,q;
    cin >> t >> q;
    for(int i=1;i<=t;i++)
        cin >> a[i];
    init(1,1,t);
    for(int i=0;i<q;i++){
        int n,m;
        cin >> m >>n;
        if(t - (lower_bound(IT[1].begin(),IT[1].end(),m)-IT[1].begin()) < n) cout << -1 <<endl;
        else cout <<query(1,1,t,n,m)<<endl;
    }
}
/*
5 5
1 2 3 4 5
3 1
3 4
4 8
1 2
2 3

*/
