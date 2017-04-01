#include <bits/stdc++.h>
using namespace std;
const int Maxn = 3e5+20;
long long H[Maxn],H_L[Maxn << 3], H_R[Maxn <<3], lz[Maxn << 3];
int M[Maxn << 3], M_L[Maxn << 3], M_R[Maxn << 3], R[Maxn << 3], L[Maxn <<3], len[Maxn <<3];
void join(int node) {
    int node_l = node << 1;
    int node_r = node_l + 1;
    H_L[node] = H_L[node_l];
    H_R[node] = H_R[node_r];
    len[node] = len[node_l] + len[node_r];
    R[node] = R[node_r];
    L[node] = L[node_l];
    M_L[node] = M_L[node_l];
    M_R[node] = M_R[node_r];
    M[node] = max(M[node_l],M[node_r]);
    if (H_R[node_l] < H_L[node_r]) {
        M[node] = max(M[node], R[node_l] + M_L[node_r]);
        if (R[node_l] == len[node_l]) {
            M_L[node] = R[node_l] + M_L[node_r];
        }
        if (M_R[node_r] == len[node_r]) {
            M_R[node] = R[node_l] + M_R[node_r];
        }
        if (R[node_r] == len[node_r]) {
            R[node] = R[node_l] + R[node_r];
        }
    }
    if (H_R[node_l] > H_L[node_r]) {
        M[node] = max(M[node], M_R[node_l] + L[node_r]);
        if (M_L[node_l] == len[node_l]) {
            M_L[node] = M_L[node_l] + L[node_r];
        }
        if (L[node_r] == len[node_r]) {
            M_R[node] = M_R[node_l] + L[node_r];
        }
        if (L[node_l] == len[node_l]) {
            L[node] = L[node_l] + L[node_r];
        }
    }

}
void init(int node,int l,int r) {
    if(l==r) {
        H_L[node] = H_R[node] = H[l];
        M[node] = M_L[node] = M_R[node] = R[node] = L[node] = len[node] = 1;
        return;
    }
    int mid = (l+r)>>1;
    init(node << 1, l, mid);
    init((node<<1)+1,mid+1,r);
    join(node);
}
void push(int node){
    int node_l = node << 1;
    int node_r = node_l + 1;
    H_L[node_l] += lz[node];
    H_R[node_l] += lz[node];
    lz[node_l] += lz[node];
    H_L[node_r] += lz[node];
    H_R[node_r] += lz[node];
    lz[node_r] += lz[node];
    lz[node] = 0;
}
void update(int node,int l,int r,int u,int v,int val){
    if(u <= l && r <= v){
        H_L[node] += val;
        H_R[node] += val;
        lz[node] += val;
        return;
    }
    if(l > v || r < u) return;
    push(node);
    update(node << 1, l, (l + r) >> 1, u, v, val);
    update((node<<1)+1,((l+r)>>1)+1,r, u, v, val);
    join(node);
}
main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> H[i];
    init(1,1,n);
    int m;
    cin >> m;
    for(int i=1;i<=m;i++){
        int l,r,v;
        cin >> l >> r >> v;
        update(1,1,n,l,r,v);
        printf("%d\n",M[1]);
    }
}
