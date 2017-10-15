#include <bits/stdc++.h>

using namespace std;
const long double PI = 3.141592653589793238L;
long double degree[266];
int d;
long double cal(long double x, long double y){
    long double dis = min(fabs(x - y), 360 - fabs(x - y));
    return d*sqrt(2 - 2*cos(dis*PI / 180));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> d;
    string s;
    for(int i = 0; i< 26; i++){
        cin >> s;
        cin >> degree[(int)s[0]];
    }
    char last = 0;
    long double ans = d;
    while(cin >> s){
        for(auto&c:s) if(isalpha(c)){
            if(isalpha(last)){
                ans += cal(degree[toupper(last)], degree[toupper(c)]);
            }
            last = c;
        }
    }
    cout << ceil(ans);
}





