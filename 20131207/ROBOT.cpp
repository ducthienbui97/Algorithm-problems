#include <bits/stdc++.h>
#define elif else if
using namespace std;
long long ansx,ansy;
int n,m;
vector<int> x;
vector<int> y;
int nowx,nowy;
string s;
main() {
    ios_base::sync_with_stdio (false);
    cin>>n>>m;
    x.resize(n);
    y.resize(n);
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
        ansx+=abs(x[i]);
        ansy+=abs(y[i]);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    cin>>s;
    for(int i=0;i<m;i++){
        if(s[i]=='S'){
            nowy++;
            int tmp=lower_bound(y.begin(),y.end(),nowy)-y.begin();
            ansy+=(tmp<<1)-n;
        }
        if(s[i]=='J'){
            nowy--;
            int tmp=upper_bound(y.begin(),y.end(),nowy)-y.begin();
            ansy-=(tmp<<1)-n;
        }
        if(s[i]=='I'){
            nowx++;
            int tmp=lower_bound(x.begin(),x.end(),nowx)-x.begin();
            ansy+=(tmp<<1)-n;
        }
        if(s[i]=='Z'){
            nowx--;
            int tmp=upper_bound(x.begin(),x.end(),nowx)-x.begin();
            ansy-=(tmp<<1)-n;
        }
        printf("%lld\n",ansx+ansy);
    }
}
