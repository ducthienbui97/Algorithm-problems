#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <utility>
#define elif else if
using namespace std;
void openfile() {
    freopen("PASSWORD.inp","r",stdin);
    freopen("PASSWORD.out","w",stdout);
    }
int n;
string S;
int f[2222][2222][2];
bool done[2222][2222][2];
int next[2222][333];
int prev[2222][333];
int F(int l,int r,int val) {
    if(l>=r) return 0;
    if(done[l][r][val]) return f[l][r][val];
    done[l][r][val]=true;
    f[l][r][val]=max(F(l+1,r,val),F(l,r-1,val));
    if((!val&&S[l]==S[r])||(val&&S[l]!=S[r])) f[l][r][val]=max(f[l][r][val],F(l+1,r-1,!val)+2);
    return f[l][r][val];
    }
int ans;
string dp[2222][2222][2];
string trace(int l,int r,int t) {
    if(l>r) return "";
    if(dp[l][r][t].size()) return dp[l][r][t];
    if(t) {
        for(int i='a',done=false; i<'z' && !done; i++) {
            for(int j='a'; j<'z'; j++)
                if(i!=j&&prev[r][j]!=-1&&next[l][i]!=-1)
                    if(next[l][i]<prev[r][j]&&F(next[l][i],prev[r][j],t)==F(l,r,t)) {
                        string tmp=(char) i+trace(next[l][i]+1,prev[r][j]-1,!t)+(char)j;
                        if(dp[l][r][t]==""||dp[l][r][t]>tmp)
                            dp[l][r][t]=tmp;
                        done=true;
                        }
            }
        }
    else
        for(int i='a'; i<'z'; i++)
            if(prev[r][i]!=-1&&next[l][i]!=-1)
                if(next[l][i]<prev[r][i]&&F(next[l][i],prev[r][i],t)==F(l,r,t))
                    return dp[l][r][t]=(char) i+trace(next[l][i]+1,prev[r][i]-1,!t)+ (char) i;
    return dp[l][r][t];
    }
main() {
#ifndef HYQ
    openfile();
#endif // HYQ
    ios_base::sync_with_stdio(false);
    cin>>n;
    cin>>S;
    for(int j='a'; j<'z'; j++) {
        int pr=-1;
        for(int i=0; i<n; i++) {
            if(S[i]==j) pr=i;
            prev[i][j]=pr;
            }
        }
    for(int j='a'; j<'z'; j++) {
        int nx=-1;
        for(int i=n-1; i>=0; i--) {
            if(S[i]==j) nx=i;
            next[i][j]=nx;
            }
        }
    ans=F(0,n-1,0);
    cout<<trace(0,n-1,0);
    }
