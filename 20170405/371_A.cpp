#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string q;
        string t;
        cin >> q;
        if(q[0] == '+'){
            long long x;
            cin >> x;
            while(x >0){
                t.push_back(x%2 + '0');
                x/=10;
            }
            while(t.size() < 18) t.push_back('0');
            mp[t]++;
        }else if(q[0] == '-'){
            long long x;
            cin >> x;
            while(x >0){
                t.push_back(x%2 + '0');
                x/=10;
            }
            while(t.size() < 18) t.push_back('0');
            mp[t]--;
        }else{
            cin >> t;
            reverse(t.begin(),t.end());
            while(t.size() < 18) t.push_back('0');
            cout << mp[t] <<endl;
        }
    }
}
