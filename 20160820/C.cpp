#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(false);
    long long a;
    int m,n;
    cin >> a;
    int sqr = int(sqrt(a));
    for(int i=1; i <= sqr; i++) {
        if(a%i == 0) {
            m = i;
            n = a/i;
            if(n>m) swap(m,n);
            if((m-n)%2 == 0) {
                int X = (m-n)/2;
                int Y = (m+n)/2;
                long long b = 2ll*X*Y;
                long long c = 1ll*X*X+1ll*Y*Y;
                if(a*a+b*b == c*c&& a+b>c) {
                    cout << b<<" "<<c;
                    return 0;
                    }
                }
            }
        if(a%2==0 &&(a/2) %i ==0) {
            m = i;
            n = (a/2)/i;
            if(n>m) swap(m,n);
            long long b=1ll*m*m-1ll*n*n;
            long long c=1ll*m*m+1ll*n*n;
            if(a*a+b*b == c*c&& a+b>c) {
                cout << b<<" "<<c;
                return 0;
                }
            }
        m = i;
        n = int(sqrt(a-1ll*m*m));
        if(1ll*m*m+1ll*n*n==a) {
            if(n>m) swap(m,n);
            long long b = 2ll*m*n;
            long long c = 1ll*m*m - 1ll*n*n;
            if(a*a==b*b+c*c && b+c>a) {
                cout<<b<<" "<<c;
                return 0;
                }
            }
        }

    cout <<-1;
    return 0;
    }
