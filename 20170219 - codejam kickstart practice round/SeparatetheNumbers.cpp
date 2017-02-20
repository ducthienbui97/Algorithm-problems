#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int ok = false;
        for(int i=0;i<s.size()/2 && !ok;i++){
            long long starter = 0;
            long long cc = 0;
            for(int j=0;j<=i;j++)
                starter = starter*10 + s[j] - '0';
            cc = starter;
            string t = to_string(starter);
            while(t.size() < s.size()) t+=to_string(++starter);
            if(t == s){
                ok = true;
                cout << "YES "<<s.substr(0,i+1) <<endl;
            }
        }
        if(!ok) cout <<"NO\n";
    }
    return 0;
}
