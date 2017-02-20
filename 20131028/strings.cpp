#include <bits/stdc++.h>
#define elif else if
using namespace std;
string S;
string s1,tmp;
int child[1000111][30];
int fn[1000111];
int F[1000111];
int cnt;
void insert(const string& s) {
    int p=0;
    for(int i=0; i<s.length(); i++) {
        if(!child[p][s[i]-'a'])child[p][s[i]-'a']=++cnt;
        p=child[p][s[i]-'a'];
        }
    fn[p]=true;
    }
void dp(int I) {
    int p=0;
    for(int i=I; i<S.length();) {
        if(!child[p][S[i]-'a']) return;
        p=child[p][S[i]-'a'];
        F[I]+=F[++i]*fn[p];
        F[I]%=18102008;
        }
    }
main() {
    freopen("strings.inp","r",stdin);
    freopen("strings.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>S;
    int n;
    cin>>n;
    while(n--) {
        cin>>s1;
        insert(s1);
        }
    n=S.length();
    F[n]=1;
    for(int i=n-1; i>=0; i--) {
        dp(i);
        }
    cout<<F[0]%18102008;
    }
