#include <bits/stdc++.h>
using namespace std;
int n,r,p,s;
vector<int> cnt(int layer,char choice){
    char l,r;
    vector<int> rep(3);
    if(layer){
        vector<int> l,r;
        if(choice == 'R'){
            l = cnt(layer - 1,choice);
            r = cnt(layer - 1,'S');
        }
        else if(choice =='P'){
            l = cnt(layer - 1,choice);
            r = cnt(layer - 1,'R');
        }
        else {
            l = cnt(layer - 1,choice);
            r = cnt(layer - 1,'P');
        }
        for(int i=0;i<3;i++)
            rep[i] = l[i] + r[i];
    }
    else{
        if(choice == 'R'){
            rep[0] = 1;
        }
        else if(choice =='P'){
            rep[1] = 1;
        }
        else {
            rep[2] = 1;
        }
    }
    return rep;
}
string get(int layer, char choice){
    if(layer){
        string l,r;
        if(choice == 'R'){
            l = get(layer-1,'R');
            r = get(layer-1,'S');

        }
        else if(choice == 'P'){
            l = get(layer-1,'P');
            r = get(layer-1,'R');
        }
        else{
            l = get(layer-1,'P');
            r = get(layer-1,'S');
        }
        if(l>r) return r + l;
        else return l + r;
    }else
        return string(1,choice);
}
void solve(int nTest){
    string ans = "IMPOSSIBLE";
    vector<int> r (3);
    cin >> n >>r[0] >> r[1] >> r[2];

    if(cnt(n,'R') == r){
        ans = get(n,'R');
    }
    if(cnt(n,'P') == r){
        string tmp = get(n,'P');
        if(ans == "IMPOSSIBLE" || ans > tmp)
            ans = tmp;
    }
    if(cnt(n,'S') == r){
        string tmp = get(n,'S');
        if(ans == "IMPOSSIBLE" || ans > tmp)
            ans = tmp;
    }
    cout << "Case #"<<nTest<<": "<<ans<<endl;
}
main(){
    freopen("A-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}
