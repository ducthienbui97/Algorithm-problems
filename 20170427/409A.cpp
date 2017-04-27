#include <bits/stdc++.h>
using namespace std;
vector<int> a,b;
int main(){
    ios_base::sync_with_stdio(false);
    int n,p;
    cin >> n >> p;
    a.resize(n);
    b.resize(n);
    long long s = 0;
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
        s+= a[i];
    }
    double ans = 0;
    double l = 0,r = 1e16;
    if(p >= s) cout << -1 <<endl;
    else{
        for(int it=0;it<100;it++){
            double time = (l+r)/2;
            double sum = 0;
            for(int i=0;i<n;i++){
                sum += max(0.,(double)  a[i]-b[i]/time);
                }
            if(sum <= p){
                l = time;
                ans = time;
            }else{
                r = time;
            }
        }
        cout << ans <<endl;

    }
}
