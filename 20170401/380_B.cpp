#include <bits/stdc++.h>
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    int n,a,b,k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    int cnt = 0;
    int space = 0;
    for(char c:s){
        if(c=='1'){
            space += cnt/b;
            cnt = 0;
        }
        else cnt ++;
    }
    space += cnt/b;
    cnt = 0;
    space -= a - 1;
    cout << space <<endl;
    for(int i=0;i<s.size();i++){
        if(!space) break;
        if(s[i]=='1'){
            cnt = 0;
        }
        else{
            cnt ++;
            if(cnt == b){
                cnt = 0;
                space--;
                cout << i+1 <<' ';
            }
        }
    }
}
