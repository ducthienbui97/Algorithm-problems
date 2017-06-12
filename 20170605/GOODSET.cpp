#include<bits/stdc++.h>
using namespace std;
bool dont[555];
void solve(){
    memset(dont,0,sizeof dont);
    int n;
    cin >> n;
    vector<int> ans;
    for(int i=1;ans.size() < n;i++)
    if(!dont[i]){
        for(int&v:ans)
            dont[v+i] = true;
        ans.push_back(i);
    }
    for(int&v:ans)
        cout << v<<' ';
    cout << endl;


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i=0;i<t;i++) solve();
}
