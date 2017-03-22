#include <bits/stdc++.h>
using namespace std;
const int Max = 2e5+20;
int Nx[Max][26];
bool rm[Max];
string s,p;
int n;
vector<int> v;
bool check(int x){
    for(int i=1;i<=n;i++)
        rm[i] = false;
    for(int i=0;i<x;i++)
        rm[v[i]] = true;
    int cur = 1;
    for(int i=0;i<p.size();i++){
        while(rm[Nx[cur][p[i]-'a']]&&cur<=n) cur++;
        if(!Nx[cur][p[i]-'a']||cur > n) return false;
        cur = Nx[cur][p[i]-'a']+1;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin >> s >> p;
    n = s.size();
    for(int i = n; i > 0; i--){
        for(int j=0;j<26;j++)
            Nx[i][j] = Nx[i+1][j];
        Nx[i][s[i-1] - 'a'] = i;
    }
    v.resize(n);
    for(int &u:v)
        cin >> u;
    int ans = 0;
    int l = 1;
    int r = n;
    while(l<=r){
        int mid = (l+r)>>1;
        if(check(mid)){
            l = mid + 1;
            ans = mid;
        }else{
            r = mid - 1;
        }
    }
    cout << ans<<endl;
}
