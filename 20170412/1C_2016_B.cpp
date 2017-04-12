#include <bits/stdc++.h>
using namespace std;
void solve(int numTest){
    long long m,b;
    cin >> b >> m;
    cout <<"Case #"<<numTest<<": ";
    if(m > (1ll<<(b-2))) cout <<"IMPOSSIBLE"<<endl;
    else {
        cout << "POSSIBLE" <<endl;
        string s = "0";
        if(m==(1ll<<(b-2))){
            s += string(b-1,'1');
        }
        else{
            for(int i=0;i<b-2;i++)
                if(m&(1ll<<(b-3-i))) s.push_back('1');
                else s.push_back('0');
            s.push_back('0');
        }
        cout << s <<endl;
        for(int i=2;i<=b;i++){
            cout << string(i,'0') <<string(b-i,'1')<<endl;;
        }
    }
}
main(){
    freopen("B-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}

