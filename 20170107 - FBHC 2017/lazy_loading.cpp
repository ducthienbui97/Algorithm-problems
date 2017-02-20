#include <bits/stdc++.h>
using namespace std;
void run(int testnum){
    deque<int> w;
    int n;
    cin >> n;
    w.resize(n);
    for(int i=0;i < n; i++)
        cin >> w[i];
    sort(w.begin(),w.end());
    int ans = 0;
    while(!w.empty() && w.back()*w.size() >= 50){
        ans ++;
        int t = (49/w.back());
        w.pop_back();
        while(t--) w.pop_front();
    }
    cout << "Case #" << testnum << ": " << ans<<endl;
}
int main(){
    freopen("lazy_loading.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i ++)
        run(i);
}
