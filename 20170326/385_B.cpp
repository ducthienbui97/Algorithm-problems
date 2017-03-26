#include <bits/stdc++.h>
using namespace std;
int ans[1024];
main(){
    memset(ans,0x3f,sizeof ans);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int bit=0;bit<10;bit++){
        int cnt = 0;
        for(int i=0;i < n;i++)
            if((i>>bit)&1) cnt ++;
        if(!cnt) continue;
        cout << cnt;
        for(int i=0;i < n;i++)
            if((i>>bit)&1) cout<<' ' <<i+1;cout <<endl;
        for(int i=0;i<n;i++){
            int tmp;
            cin >> tmp;
            if((i>>bit)&1) continue;
            ans[i] = min(ans[i],tmp);
        }
        if(cnt==n) continue;
        cout << n-cnt;
        for(int i=0;i<n;i++)
            if((i>>bit)&1) continue;
            else  cout<<' ' << i +1;cout <<endl;
        for(int i=0;i<n;i++){
            int tmp;
            cin >> tmp;
            if((i>>bit)&1) ans[i] = min(ans[i],tmp);
        }

    }
    cout <<-1<<endl;
    for(int i=0;i<n;i++)
        cout << ans[i] <<endl;
}
