#include <stack>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cstdio>
#define elif else if
#define int long long
#define lo first
#define cost second
using namespace std;
const int Maxn=55000;
int n,g,b,d;
typedef pair<int,int> GS;
GS a[Maxn];
int next[Maxn];
stack<int> st;
main() {
    freopen("fuel.inp","r",stdin);
   freopen("fuel.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n>>g>>b>>d;
    for(int i=1;i<=n;i++)
        cin>>a[i].lo>>a[i].cost;
    sort(a+1,a+n+1);
    a[n+1].lo=d;
    a[n+1].cost=0;
    int price=0;
    int last=0;
    int now;
    st.push(n+1);
    for(int i=n;i>0;i--){
        while(a[i].cost<a[st.top()].cost) st.pop();
        next[i]=st.top();
        st.push(i);
    }
    for(int i=1;i<=n;i++){
        b-=(a[i].lo-last);
        last=a[i].lo;
        if(b<0){
            puts("-1");
            return 0;
        }
        now=b;
        if(a[next[i]].lo-last>b) b=a[next[i]].lo-last;
        if(b>g) b=g;
        price+=(b-now)*a[i].cost;
    }
    b-=(d-last);
    if(b<0) {
        puts("-1");
        return 0;
    }
    cout<<price<<endl;
}
