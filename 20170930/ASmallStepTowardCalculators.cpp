#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int a = s[0] - '0';
    int b = s[2] - '0';
    if(s[1] == '+')
        cout << a + b;
    else
        cout << a - b;
    return 0;
}
