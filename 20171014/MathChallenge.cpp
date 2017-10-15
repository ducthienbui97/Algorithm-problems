#include <bits/stdc++.h>

using namespace std;
const long long base = 1e9+7;
const long long p1 = 2, p2 = (base - 1)/2;
// 1 = 250000002*p1 - 1*p2
// 1 = 1*p2 - 250000001*p1
const long long maxN = 1e6+20;
long long Frac[maxN];
long long cnt[maxN];
long long pow(long long x,long long y, long long b){
    if(y == 0)
        return 1;
    if(y == 1)
        return x%b;
    if(y&1)
        return pow(x,y-1,b)*x%b;
    long long tmp = pow(x,y/2,b);
    return tmp*tmp%b;
}
long long edg(long long a, long long b){
    if (a == 0)
        return b;
}
long long cal(long long b,long long c){
    long long m1 = (cnt[b] - cnt[c] - cnt[b - c]) == 0;
    long long m2 = Frac[b]*pow(Frac[c]*Frac[b-c]%p2,p2 - 2,p2)%p2;
    return ((m2*250000002%(base - 1)*p1%(base - 1)) + (m1 * 1 * p2%(base - 1)))%(base - 1);
}
int main() {
//    freopen("test.txt","r",stdin);
    Frac[0] = 1;
    cnt[0] = 0;
    for(long long i = 1; i < maxN; i++){
        Frac[i] = Frac[i-1]*i%p2;
        cnt[i] = cnt[i-1];
        for(int tmp = i; tmp > 1 && tmp%2 ==0; tmp /= 2)
            cnt[i]++;
    }
    long long t;
    cin >> t;
    for(long long i = 0; i < t; i++){
        long long a,b,c;
        cin >> a >> b >> c;
        cout << pow(a, cal(b,c),base) << endl;
    }
}


