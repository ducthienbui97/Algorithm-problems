#include <bits/stdc++.h>
using namespace std;
vector<int> d[2222];
int root[2222];
vector<int> pre,post;
void preOrder(int v){
    pre.push_back(v);
    for(auto&u:d[v])
        preOrder(u);
}

void postOrder (int v){
    for(auto&u:d[v])
        postOrder(u);
    post.push_back(v);
}

int findRoot(int u){
    if(u == root[u])
        return u;
    return root[u] = findRoot(root[u]);
}

void solve(int ntest){
    int K,N;
    cin >> N >> K;
    pre.clear();
    post.clear();
    for(int i = 1; i <= N; i++){
        d[i].clear();
        root[i] = i;
        int A,B;
        cin >> A >> B;
        if(A != 0)
            d[i].push_back(A);
        if(B != 0)
            d[i].push_back(B);
    }
    preOrder(1);
    postOrder(1);
    for(int i = 0; i < N; i++){
        root[findRoot(pre[i])] = root[findRoot(post[i])];
    }
    set<int> roots;
    for(int i = 1; i <= N; i++)
        roots.insert(findRoot(i));
    map<int,int> r2l;
    cout << "Case #" << ntest << ":";
    if(roots.size() < K)
        cout << " Impossible\n";
    else {
        for(int i = 1; i <= N; i++){
            int r = findRoot(i);
            if(r2l.find(r) == r2l.end())
                r2l[r] = min((int)r2l.size(), K);
            cout <<" " << r2l[r];
        }
        cout << endl;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
        solve(i);
}
