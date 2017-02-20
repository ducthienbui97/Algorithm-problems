#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(false);
    string s;
    getline(cin,s);
    char cur  = 'a';
    for(int i=0;i<s.size();i++)
    if(s[i] > cur){
        puts("NO");
        return 0;
    }else if(s[i] == cur) cur ++ ;
    puts("YES");
}

