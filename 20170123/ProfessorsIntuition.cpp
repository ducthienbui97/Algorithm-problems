#include <bits/stdc++.h>
using namespace std;
int S[1000111];
int best[8000111];
int get(int node,int l,int r,int u,int v) {
    if(l>v||r<u) return 0;
    if(u<=l&&r<=v) {
        return best[node];
    }
    int mid = (l+r)>>1;
    int left = get(node<<1,l,mid,u,v);
    int right = get((node<<1)+1,mid+1,r,u,v);
    if(!left) return right;
    if(!right) return left;
    if(1ll*right*S[left]  < 1ll*left*S[right]) return left;
    else return right;
}
int init(int node,int l,int r) {
    if(l==r) best[node] = l;
    else {
        int mid = (l+r)>>1;
        int left = init(node<<1,l,mid);
        int right = init((node<<1)+1,mid+1,r);
        if(1ll*right*S[left] < 1ll*left*S[right]) best[node] =  left;
        else best[node] = right;
    }
    return best[node];
}
int main() {
    for(int i=1; i<=1000000; i++)
        for(int j=i+i; j<=1000000; j+=i)
            S[j] += i;
    init(1,1,1000000);
    int t;
    for(cin>>t;t-->0;){
        int a,b;
        cin >> a>> b;
        cout << get(1,1,1000000,a,b)<<endl;
    }
    return 0;
}

