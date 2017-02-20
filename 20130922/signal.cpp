#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define elif else if
#define input "signal.inp"
#define output "signal.out"
void openfile() {
    freopen(input,"r",stdin);
    freopen(output,"w",stdout);
    }
const int Maxn=1e6+10;
long long Node[Maxn<<3],Lazy[Maxn<<3];
int n,m,l;
void update(const int& node,const int& l,const int& r,const int& u,const int& v,const long long& val) {
    if(l>r||r<u||l>v) return; /*l---r*/ /*u---v*/
    if(u<=l&&r<=v) {
        Node[node]+=val;
        Lazy[node]+=val;
        return;
        }
    update(node<<1,l,(l+r)>>1,u,v,val);
    update((node<<1)+1,((l+r)>>1)+1,r,u,v,val);
    Node[node]=max(Node[node<<1],Node[(node<<1)+1])+Lazy[node];
    }
main() {
#ifndef HYQ
    openfile();
#endif
    ios_base::sync_with_stdio(false);
    cin>>n>>l>>m;
    n=n-l+1;
    int x,y;
    long long z;
    while(m--) {
        cin>>x;
        x--;
        if(x) {
            printf("%lld\n",Node[1]);
            }
        else {
            cin>>y>>z;
            update(1,1,n,y-l+1,y,z);
            }
        }
    }
