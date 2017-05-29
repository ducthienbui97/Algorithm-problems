#include <bits/stdc++.h>
using namespace std;
bool Wrong[1<<26];
void push(int num){
    if(Wrong[num]) return;
    Wrong[num] = true;
    for(int i=num;i>0;i-=i&-i)
        push(num - (i&-i));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    int full = 0;
    Wrong[0] = true;
    for(auto&u:v){
        cin >> u;
        full |= u;
    }
    for(auto&u:v){
        push(full&(~u));
    }
    int ans = full;
    int cnt = __builtin_popcount(full);
    for(int i=1;i<full;i++)
        if(!Wrong[i] && __builtin_popcount(i) < cnt){
            cnt = __builtin_popcount(i);
            ans = i;
        }
    printf("%d",ans);
    return 0;
}
