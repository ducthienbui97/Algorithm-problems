#include<bits/stdc++.h>
using namespace std;
char C[]="fedabc";
main(){
    long long n;
    char c;
    cin >> n>>c;
    long long rem = n%4;
    long long k = n/4;
    long long ans;
    if(rem == 0) ans = 16*(k-1)+7;
    else if(rem==2)ans = 16*k+7;
    else ans =16*k;
     for(int i= 0 ;i < 6;i++)
    if(c==C[i]){
        ans+=i+1;
        break;
    }
    cout << ans<<endl;
}
