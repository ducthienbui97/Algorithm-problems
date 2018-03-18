#include <bits/stdc++.h>

using namespace std;
const int Maxn = 1e5+20;
const int base = 1e9;
long long F[40];
int A[Maxn];
vector<deque<int> >IT;
vector<int> lz;
vector<long long> total;
void upgrade(int node, int l,int r){
    for(int i = 0; i < 40; i++)
        IT[node][i] = IT[2*node][i] + IT[2*node + 1][i];
    total[node] = (total[2*node] + total[2*node +1])%base;
}
void init(int node,int l,int r) {
    IT[node].resize(40,0);
    if(l == r) {
        if(A[l] < 40) {
            IT[node][A[l]] = 1;
            total[node] = F[A[l]];
        }
        return;
    }
    init(2*node, l, (l+r)/2);
    init(2*node + 1, (l+r)/2 + 1, r);
    upgrade(node,l,r);
    //cout << node <<" "<<IT[node][1] <<endl;
}
void handle(int node,int l,int r){
    for(int i = 0; i < lz[node]; i++) {
      //  cout << IT[node][1] << endl;
        IT[node].push_front(0);
        IT[node].pop_back();
        //cout << IT[node][1] << endl;
        if(l != r) {
            lz[2*node]++;
            lz[2*node + 1]++;
        } else
            A[l]++;
    }
    lz[node] = 0;
}
void increase(int node,int l,int r,int u,int v) {
    handle(node,l,r);
    for(int i = 0; i < 40; i++)
        total[node] = (total[node] + IT[node][i]*F[i]%base)%base;
    if(u > r || v < l || l > r) return;
    bool done = false;
    if(u <= l && r <= v) {
        lz[node] ++;
        done  = true;
    }
    handle(node,l,r);
    if(!done) {
        increase(2*node,l,(l+r)/2,u,v);
        increase(2*node + 1, (l+r)/2 +1,r,u,v);
        upgrade(node, l, r);
    }
}
long long get(int node,int l,int r,int u,int v) {
    if(u > r || v < l || l > r) return 0;
    handle(node,l,r);
    long long ans = 0;
    if(u <= l && r <= v) {
        return total[node];
    }
     else {
        ans = (ans + get(2*node,l,(l+r)/2,u,v))%base;
        ans = (ans + get(2*node + 1,((l+r)/2)+1,r,u,v))%base;
    }
    return ans;
}

void modify(int node,int l,int r,int idx, int new_val) {
    if(l > idx || r < idx)
        return;
    handle(node,l,r);
    if(l != r) {
        modify(2*node,l,(l+r)/2,idx,new_val);
        modify(2*node +1,(l+r)/2 + 1, r, idx, new_val);
    }
    //cout << A[idx] << endl;
    if(A[idx] < 40)
        IT[node][A[idx]] --;
    if(new_val < 40)
        IT[node][new_val] ++;
}
int main() {
    int n;
    int m;
    cin >> n >> m;
    F[0] =1;
    IT.resize(n*6);
    lz.resize(n*6);
    total.resize(n*6);
    for(int i = 1; i < 40; i++) {
        F[i] = F[i-1]*i%base;
    }

    for(int A_i = 1; A_i <= n; A_i++) {
        cin >> A[A_i];
    }
    init(1,1,n);
    for(int q = 0; q < m; q++) {
        int t,l,r;
        cin >> t >> l >> r;
        switch(t) {
        case 1:
            increase(1,1,n,l,r);
            break;
        case 2:
            cout << get(1,1,n,l,r)%base <<endl;
            break;
        default:
            modify(1,1,n,l,r);
            A[l] = r;
        }
    }
    return 0;
}
