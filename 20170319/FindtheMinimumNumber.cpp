#include <bits/stdc++.h>
// https://www.hackerrank.com/contests/w30/challenges
using namespace std;
string get(int t){
    if(t==1) return "int";
    else return "min(int, "+get(t-1)+")";
}
int main(){
    int n;
    cin >> n;
    cout << get(n);
    return 0;
}

