#include <bits/stdc++.h>
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    int m,n,s,r,p;
    cin >>m>>n>>s>>r>>p;
    for(int i = max(max(m,n),max(s,r))/p; i <=1e8; i++){
        int temp = i*p;
        if(temp > max(max(m,n),max(s,r)))
        if(temp%m&&temp%n&&temp%s&&temp%r){
            cout << temp;
            return 0;
        }
    }
}
