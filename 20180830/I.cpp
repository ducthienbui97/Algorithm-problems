#include <bits/stdc++.h>

using namespace std;
bool isvowel(char c){
    switch(tolower(c)){
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}
main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        string s;
        cin >> n;
        getline(cin,s);
        getline(cin,s);
        vector<char> v;
        for(char&c:s){
            if(isvowel(c))
                v.push_back(c);
        }
        for(char&c:s){
            if(isvowel(c)){
                c = v.back();
                v.pop_back();
            }
        }
        cout << s << endl;
    }
}



