#include <bits/stdc++.h>
using namespace std;
const int Big=1e5;
char s[22];
bool ok[22];
vector<int> A;
vector<int> B;
long long F[22][2][2][2][Big+20];
long long a,b,x;
vector<long long> poww;
bool ck(long long t){
    while(t){
        if(!ok[t%10]) return false;
        t/=10;
    }
    return true;
}
void dobig(){
    int ans=0;
    for(int i=a/x;1ll*i*x<=b;i++)
    if(1ll*i*x>=a && ck(1ll*i*x)) ans++;
    cout<<ans;
}
long long f(int now,bool bg,bool sm,bool zr,int mod){
  //  cerr<<now<<" "<<bg<<" "<<sm<<" "<<zr<<" "<<mod<<endl;
    if(now==A.size()) if(!mod) return 1;
    else return 0;
    if(F[now][bg][sm][zr][mod]>=0) return F[now][bg][sm][zr][mod];
    F[now][bg][sm][zr][mod]=0;
    for(int i=0;i<10;i++)if(ok[i]||(zr&&!i)){
        if((!bg&&i<A[now])||(!sm&&i>B[now])) continue;
        F[now][bg][sm][zr][mod]+=f(now+1,bg||i>A[now],sm||i<B[now],zr&&!i,(mod+i*poww[now])%x);
    }
    return F[now][bg][sm][zr][mod];
}
void dosmall(){
    memset(F,-1,sizeof F);
    while(b){
        B.push_back(b%10);
        b/=10;
    }
    while(a){
        A.push_back(a%10);
        a/=10;
    }
    poww.resize(B.size());
    poww[0]=1;
    for(int i=1;i<B.size();i++)
        poww[i]=(10*poww[i-1])%x;
    reverse(poww.begin(),poww.end());
    A.resize(B.size());
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    cout<<f(0,0,0,1,0);
}
main(){
    ios_base::sync_with_stdio(false);
    cin>>x>>a>>b;
    cin>>s;
    for(int i=strlen(s)-1;i>=0;i--){
        ok[s[i]-'0']=true;
    }
    if(x>=Big) dobig();
    else dosmall();
}

