//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#define elif else if
#define FORE(i,d) for(__typeof(d.begin()) i=d.begin();i!=d.end();i++)
#define FOR(i,d) for(int i=0;i<d.size();i++)
using namespace std;
#define H first
#define W second
vector<pair<long long,long long> > a;
vector<long long> ans;
const int Maxn=100011;
int next[Maxn],prev[Maxn];
#define input "alake.inp"
#define output "alake.out"
inline void openfile(){
    freopen(input,"r",stdin);
    freopen(output,"w",stdout);
}
main() {
    ios_base::sync_with_stdio(false);
#ifndef HYQ
    openfile();
#endif // HYQ
    int n;
    cin>>n;
    a.resize(n);
    ans.resize(n);
    FOR(i,a) cin>>a[i].W>>a[i].H,next[i]=i+1,prev[i]=i-1;;
    int start=0;
    FOR(i,a) if(a[i].H<a[start].H) start=i;
    long long now=0;
    while(1){
        ans[start]=now+a[start].W;
        if(next[start]>=n&&prev[start]<0) break;
        if(next[start] < n) prev[next[start]]=prev[start];
        if(prev[start] >=0) next[prev[start]]=next[start];
        if(next[start]<n&&(prev[start]<0||a[next[start]].H<a[prev[start]].H)){
            now+=a[start].W*(a[next[start]].H-a[start].H);
            a[next[start]].W+=a[start].W;
            start=next[start];
            while(next[start]<n&&a[next[start]].H<a[start].H) start=next[start];
        }
        elif(prev[start]>=0&&(next[start]>=n||a[prev[start]].H<a[next[start]].H)){
            now+=a[start].W*(a[prev[start]].H-a[start].H);
            a[prev[start]].W+=a[start].W;
            start=prev[start];
            while(prev[start]>=0&&a[prev[start]].H<a[start].H) start=prev[start];
        }
        else break;
    }
    FORE(i,ans) printf("%lld\n",*i);
}
