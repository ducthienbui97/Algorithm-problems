#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include  <queue>
using namespace std;
int trie[2000111][26];
int retrie[2000111][26];
int st[2000111],rest[2000111];
int triesize=1,retriesize=1;
long long  ans;
int H[2000111];
int reH[2000111];
vector<string> S;
int n;
inline bool cmp(const string & X,const string & Y){
    return  X.size()<Y.size();
}
void insert1(int t){
    int p=0;
    for(int i=0;i<S[t].size();i++){
        if(!trie[p][S[t][i]-'a'])trie[p][S[t][i]-'a']=triesize++;
        p=trie[p][S[t][i]-'a'];
    }
    st[p]++;
}
void insert2(int t){
    int p=0;
    for(int i=S[t].size()-1;i>=0;i--){
        if(!retrie[p][S[t][i]-'a']) retrie[p][S[t][i]-'a']=retriesize++;
        p=retrie[p][S[t][i]-'a'];
    }
    rest[p]++;
}
void find1(int t){
    int p=0;
    for(int i=0;i<S[t].size();i++){
        if(!retrie[p][S[t][i]-'a']) return;
        p=retrie[p][S[t][i]-'a'];
        if(H[i+1]==reH[i+1]) ans+=1ll*rest[p];
    }
}
void find2(int t){
    int p=0;
    for(int i=S[t].size()-1;i>=0;i--){
        if(!trie[p][S[t][i]-'a']) return;
        p=trie[p][S[t][i]-'a'];
        if(H[i]==reH[i])ans+=1ll*st[p];

    }
}
main(){
    freopen("pals.inp","r",stdin);
    freopen("pals.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;
    int x;
    S.resize(n);
    for(int i=0;i<n;i++){
        cin>>x>>S[i];
    }
    sort(S.begin(),S.end(),cmp);
    for(int i=0;i<n;i++){
        insert1(i);
        H[S[i].size()]=reH[S[i].size()]=0;
        int p=1;
        for(int j=S[i].size()-1;j>=0;j--){
            H[j]=H[j+1]*31+S[i][j]-'a';
            reH[j]=reH[j+1]+(S[i][j]-'a')*p;
            p*=31;
        }
        find1(i);
        H[0]=reH[0]=0;
        p=1;
        for(int j=1;j<=S[i].size();j++){
            H[j]=H[j-1]*31+S[i][j-1]-'a';
            reH[j]=reH[j-1]+(S[i][j-1]-'a')*p;
            p*=31;
        }
        find2(i);
        insert2(i);
    }
    cout<<ans<<endl;
}
