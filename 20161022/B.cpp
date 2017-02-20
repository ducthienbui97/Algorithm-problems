#include<bits/stdc++.h>
using namespace std;
char C[]="fedabc";
main(){
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    long long n = 0;
    for(int i = 0; i < s.size()-1;i++)
        n = n*10 + (s[i]-'0');
        n--;
    char c = s[s.size()-1];

    long long sec = (n/4)*13+(n%2)*6+(n/4)*3 + n%2;

    for(int i= 0 ;i < 6;i++)
    if(c==C[i]){
        sec+=i+1;
        break;
    }
    cout << sec<<endl;
}
