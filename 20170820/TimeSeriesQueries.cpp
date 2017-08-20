#include <bits/stdc++.h>

using namespace std;
void initial(vector<int> & IT,vector<int> & p, int node,int l, int r){
    if(l == r){
        IT[node] = p[l - 1];
    }
    else{
        initial(IT,p,2*node,l,(l+r)/2);
        initial(IT,p,2*node+1,(l+r)/2+1,r);
        IT[node] = max(IT[2*node],IT[2*node+1]);
    }
}
int get1(vector<int> & IT,vector<int> & t,int node,int l,int r,int val){
    if(val > IT[node]) return -1;
    if(l==r){
        return t[l-1];
    }
    if(val <= IT[2*node]) return get1(IT,t,2*node,l,(l+r)/2,val);
    else return get1(IT,t,2*node+1,(l+r)/2+1,r,val);
}
int get2(vector<int> &IT, int node, int l, int r, int u, int v){
    if(u > v || u > r || v < l) return -1;
    if(u <= l && r <= v) return IT[node];
    return max(get2(IT,2*node,l,(l+r)/2,u,v),
               get2(IT,2*node+1,(l+r)/2+1,r,u,v));
}
int main() {
    int n;
    int q;
    cin >> n >> q;
    vector<int> IT(n<<3);
    vector<int> t(n);
    for(int t_i = 0; t_i < n; t_i++){
       cin >> t[t_i];
    }
    vector<int> p(n);
    for(int p_i = 0; p_i < n; p_i++){
       cin >> p[p_i];
    }
    initial(IT,p,1,1,n);
    for(int a0 = 0; a0 < q; a0++){
        int _type;
        int v;
        cin >> _type >> v;
        if(_type == 1) cout << get1(IT, t, 1, 1, n, v) <<endl;
        else{
            int idx = lower_bound(t.begin(),t.end(),v) - t.begin() + 1;
            cout << get2(IT,1,1,n,idx,n) << endl;
        }
    }
    return 0;
}

