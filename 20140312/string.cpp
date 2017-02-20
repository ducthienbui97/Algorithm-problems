#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
int n,m;
bool ok[111];
string s;
vector<int> d[111];
bool check(string& S){
    int p=0;
    for(int i=0;i<S.size();i++){
        if(S[i]=='*') p++;
        if((1<<p)>=n) return true;
    }
    return false;
}
void bt(int i,int lo){
//    cerr<<i<<" "<<s<<endl;

    if(lo>=m){
        if(!mp.count(s)) mp[s]=mp.size();
        d[i].push_back(mp[s]);
        return;
    }
    if(s[lo]!='*') bt(i,lo+1);
    else{
        s[lo]='0';
        bt(i,lo+1);
        s[lo]='*';
        s[lo]='1';
        bt(i,lo+1);
        s[lo]='*';
    }
}
bool vs[111];
int X[1111111],Y[111];
bool dfs(int x){
    if(vs[x]) return false;
    if(!x) return true;
    vs[x]=true;
    for(int i=0;i<d[x].size();i++)
    if(dfs(X[d[x][i]])){
        Y[x]=d[x][i];
        X[d[x][i]]=x;
        return true;
    }
    return false;

}
main(){
   // freopen("input0.txt","r",stdin);
    ios_base::sync_with_stdio(false);
   cin>>n>>m;
   int c=0,_c;
   for(int i=1;i<=n;i++){
    cin>>s;
    ok[i]=check(s);
    if(!ok[i]) bt(i,0);
    else ++c;
   }
   do{_c=c;
    memset(vs,0,sizeof vs);
    for(int i=1;i<=n;i++)
    if(!ok[i]&&!Y[i]&&dfs(i))++c;
   }while(_c<c);
    cout<<c<<endl;
}
