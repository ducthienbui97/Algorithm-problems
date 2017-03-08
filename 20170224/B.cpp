#include <bits/stdc++.h>
using namespace std;
bool F[100011];
main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    bool ok = false;
    n ++ ;
    F[1] = true;
    for(int i=2;i <= n; i++)
        if(!F[i])
        for(int j = i+i;j<=n;j+=i)
            F[j] = true,ok = true;
    cout << 1 + ok << endl;
    for(int i=2;i<=n;i++)
        cout << 1 + F[i] <<' ';
}
