#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#define mp make_pair
#define elif else if
using namespace std;
const int Maxn=3e5+10;
template <class T> void getmax(T& x,T y){if(x<y) x=y;}
template <class T> void getmin(T& x,T y){if(y<x) x=y;}
template <class T> void clear(T& x){ while(!x.empty()) x.pop();}
int R[Maxn],L[Maxn],a[Maxn],n;
stack<int> ms;
void findleft(){
    clear(ms);
    for(int i=1;i<=n;i++){
        while(!ms.empty()&&a[ms.top()]<=a[i]) ms.pop();
        L[i]=ms.empty()?0:ms.top();
        ms.push(i);
    }
}
void findright(){
    clear(ms);
    for(int i=n;i>0;i--){
        while(!ms.empty()&&a[ms.top()]<a[i]) ms.pop();
        R[i]=ms.empty()?(n+1):ms.top();
        ms.push(i);
    }
}
long long ans;
main(){
    freopen("differ.inp","r",stdin);
    freopen("differ.out","w",stdout);
    ios_base::sync_with_stdio(false);
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i];
    int t=2;
    while(t--){
        for(int i=1;i<=n;i++)
            a[i]=-a[i];
        findleft();
        findright();
        for(int i=1;i<=n;i++)
            ans+=1ll*a[i]*(R[i]-i)*(i-L[i]);
    }
    cout<<ans<<endl;
}
