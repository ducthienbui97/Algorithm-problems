#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include<set>
#define elif else if
#define int long long
using namespace std;
map<int,int> mp;
map<int,int> :: iterator it;
int a;
inline int cal(char x){
    if('a'<=x&&x<='z') return x-'a';
    else return 26+x-'A';
}

int n;
string S;
int ans;
main() {
    freopen("hyper.inp","r",stdin);
    freopen("hyper.out","w",stdout);
    ios_base::sync_with_stdio(false);
   int T;
    cin>>n;
    cin>>S;
    mp[0]=1;
    for(int i=0;i<n;i++){
        a^=(1ll<<cal(S[i]));
        mp[a]++;
    }
    for(map<int,int>::iterator i=mp.begin();i!=mp.end();i++){
            ans+=(((i->second)*(i->second-1)));
            T=i->first;
            for(int j=0;j<52;j++){
                T^=(1ll<<j);
                it=mp.find(T);
                if(it!=mp.end()) ans+=1ll*(i->second)*(it->second);
                 T^=(1ll<<j);
            }
    }
    cout<<(ans>>1)<<endl;
}
