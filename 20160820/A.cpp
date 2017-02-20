#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(false);
    int m,n;
    set<string> ms = set<string>();
    cin>>m>>n;
    for(int i=0;i<m*n;i++){
        string s;
        cin >>s;
        ms.insert(s);
    }
    if(ms.find("C") != ms.end() ||
       ms.find("M") != ms.end() ||
       ms.find("Y") != ms.end())
       cout << "#Color";
    else
        cout <<  "#Black&White";

}
