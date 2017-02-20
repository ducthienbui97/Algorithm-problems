#define elif else if
#define X first
#define Y second
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn=111;
char s[Maxn];
vector<pair<int,int> > lis;
inline  int cal(int n){return n*(n-1)*(n-2)/6;}
inline bool equa(int a,int b,int c){return a==b&&b==c;}
inline bool check(int a,int b,int c){
    if(equa(lis[a].X,lis[b].X,lis[c].X)||equa(lis[a].Y,lis[b].Y,lis[c].Y)) return true;
    if((lis[a].Y==lis[b].Y)||(lis[c].Y==lis[b].Y)) return false;
    return (lis[a].X-lis[b].X)*(lis[b].Y-lis[c].Y)==(lis[c].X-lis[b].X)*(lis[b].Y-lis[a].Y);
}
main(){
    int ans=0;
    int n;
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        int d;
        for(int j=1;j<=n;j++){
            if(s[j-1]!='.') lis.push_back(make_pair(i,j));
        }
    }
    for(int i=0;i<lis.size();i++)
        for(int j=0;j<i;j++)
            for(int k=0;k<j;k++){
                if(check(i,j,k)) ans++;
            }
    cout<<ans<<endl;
}
