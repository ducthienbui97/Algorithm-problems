#include <bits/stdc++.h>

using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    int a,f,d;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> a >> f >> d;
        if ((d == 0 && a == f)||(d != 0 && (f - a)%d == 0 && (f - a)/d >= 0)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
