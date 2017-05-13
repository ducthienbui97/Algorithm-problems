#include <bits/stdc++.h>
using namespace std;
const int Maxn = 3e5+20;
deque<char> c1,c2;
string ans;
main(){
    ios_base::sync_with_stdio(false);
    string s1,s2;
    cin >> s1 >> s2;
    int n = s1.size();
    ans.resize(n);
    int l = 0;
    int r = n -1;
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    for(char c:s1) c1.push_back(c);
    for(char c:s2) c2.push_back(c);
    while(c1.size() > (n+1)/2) c1.pop_back();
        while(c2.size() > n/2) c2.pop_front();
    /*
    s1.clear();
    s2.clear();
    for(char c:c1) s1.push_back(c);
    for(char c:c2) s2.push_back(c);
    */
    for(int i=1;i<=n;i++){
        if(i&1){
            if(c1.front() >= c2.back()){
                ans[r--] = c1.back();
                c1.pop_back();
            }else{
                ans[l++] = c1.front();
                c1.pop_front();
            }
        }else{
            if(c2.back() <= c1.front()){
                ans[r--] = c2.front();
                c2.pop_front();
            }else{
                ans[l++] = c2.back();
                c2.pop_back();
            }
        }
    }
    cout << ans <<endl;
}

