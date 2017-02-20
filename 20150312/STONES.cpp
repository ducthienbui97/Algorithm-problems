#include <bits/stdc++.h>
using namespace std;
const int Max=2e5+20;
priority_queue<int,vector<int>,greater<int> > pr[Max];
int IT[Max<<3];
void update(int node,int l,int r,int k){
    if(l>k||r<k) return;
    if(l==r){
        IT[node]=k;
        return ;
    }
    update(node<<1,l,(l+r)>>1,k);
    update((node<<1)+1,((l+r)>>1)+1,r,k);
    if(pr[IT[node<<1]].empty()) IT[node] = IT[(node<<1)+1];
    else if(pr[IT[(node<<1)+1]].empty()) IT[node] = IT[node<<1];
    else if(pr[IT[(node<<1)+1]].top()<pr[IT[node<<1]].top()) IT[node] = IT[node<<1];
    else IT[node] = IT[(node<<1)+1];
}
main(){
   // freopen("STONES.INP","r",stdin);
   // freopen("STONES.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>m>>n;
    while(m --> 0){
        int x,y,z;
        cin>>x;
        if(x==1){
            cin>>y>>z;
            pr[y].push(z);
            update(1,1,n,y);
        }else{
            printf("%d\n",pr[IT[1]].top());
            pr[IT[1]].pop();
            update(1,1,n,IT[1]);
        }
    }
}


