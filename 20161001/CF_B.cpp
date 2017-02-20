#include <bits/stdc++.h>
using namespace std;
bool check[333];
char vowels[]={'a','e','i','o','u','y'};
main(){
    ios_base::sync_with_stdio(false);
    int n;
    for(int i = 0; i< 6; i++)
        check[vowels[i]] = true;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<a.size();i++)
        cin >> a[i];
    vector<string> s(n);
    getline(cin,s[0]);
    for(int i = 0; i < s.size();i++)
        getline(cin,s[i]);
    for(int i = 0; i < s.size();i++){

        int cnt = 0;
        for(int j = 0; j < s[i].size();j++){
            cnt += check[s[i][j]];

        }

        if(cnt != a[i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
