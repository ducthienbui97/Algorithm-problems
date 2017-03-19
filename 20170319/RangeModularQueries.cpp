#include <bits/stdc++.h>
//https://www.hackerrank.com/contests/w30/challenges
using namespace std;
vector<int> big[40004];
vector<int> small[202][202];
int main(){
    ios_base::sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        big[x].push_back(i);
        for(int j=1;j<=200;j++)
            small[j][x%j].push_back(i);
    }
    for(int i=0;i<q;i++){
        int l,r,x,y;
        cin >> l >> r >> x >> y;
        int ans = 0;
        if(x <= 200){
            ans = lower_bound(small[x][y].begin(),small[x][y].end(),r+1) - lower_bound(small[x][y].begin(),small[x][y].end(),l);
        }else{
            for(;y<40004;y+=x)
                ans += lower_bound(big[y].begin(),big[y].end(),r+1) - lower_bound(big[y].begin(),big[y].end(),l);
        }
        cout << ans <<endl;
    }
}
