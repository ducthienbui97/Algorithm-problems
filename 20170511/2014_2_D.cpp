#include <bits/stdc++.h>
using namespace std;
int n,m;
int ans1,ans2;
string s[44];
int as[44];
int cnt[44];
int node[44];
vector<unordered_map<char,int> > trie[44];
void check(){
    //cout <<"X"<<endl;
    for(int i=0;i<m;i++) trie[i].clear(),trie[i].push_back(unordered_map<char,int>()),node[i] = 1;
    for(int i=0;i<n;i++){
        int no = as[i];
        int cur = 0;
        for(char c:s[i]){
            if(!trie[no][cur][c]){
                trie[no][cur][c] = node[no];
                node[no] ++;
                trie[no].push_back(unordered_map<char,int>());
            }
            cur = trie[no][cur][c];
        }
    }
    int sum =0;
    for(int i=0;i<m;i++)
        sum += node[i];
    if(sum > ans1) ans1 = sum,ans2 = 0;
    if(sum == ans1) ans2 ++;
}
void bt(int t){
    if(t == n){
        for(int i=0;i<m;i++)
            if(!cnt[i]) return;
        check();
        return;
    }
    for(int i=0;i<m;i++){
        as[t] = i;
        cnt[i] ++;
        bt(t+1);
        cnt[i] --;
    }

}
void solve(int nTest){
    ans1 = ans2 = 0;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> s[i];
    bt(0);
    cerr << nTest <<endl;
    cout << "Case #"<<nTest<<": "<<ans1 <<" "<<ans2<<endl;
    }
main(){
    freopen("D-small-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}


