#include <bits/stdc++.h>
using namespace std;
string constructName(int i){
    string rep;
    if(i>=26) rep.push_back('B');
    else rep.push_back('A');
    rep.push_back('a'+i%26);
    return rep;
}
string done[55];
int main(){
    ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<string> s(n-k+1);
    for(int i=0;i<n-k+1;i++)
        cin >> s[i];
    for(int i=0;i<k-1;i++){
        done[i] =  constructName(i);
    }
    for(int i=k-1;i<n;i++){
        if(s[i-k+1] == "NO"){
            done[i] = done[i-k+1];
        }else{
            done[i] = constructName(i);
        }
    }
    for(int i=0;i<n;i++)
        cout << done[i] <<" ";
}
