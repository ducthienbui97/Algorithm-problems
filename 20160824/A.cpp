#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e5+10;
bool F[Maxn];
int reverse(int x) {
    int rep = 0;
    while(x) {
        rep = rep*10 + x%10;
        x/=10;
        }
    if(rep < Maxn)
        return rep;
    else
        return 1;
    }
main() {
    freopen("A.inp","r",stdin);
    freopen("A.out","w",stdout);
    ios_base::sync_with_stdio(false);
    int n;
    F[1] = 1;
    for(int i=2; i<Maxn; i++)
        if(!F[i])
            for(int j=i+i; j<Maxn; j+=i) {
                F[j] = 1;
                }
    int counter = 0;
    int k;
    cin >> k;
    for(int i=1; i< Maxn; i++)
        if(!F[i]&&i!=reverse(i)&&!F[reverse(i)])
            if(++counter == k)
                cout << i <<endl;
    }
