#include <bits/stdc++.h>
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    int n;
    double h;
    cin >> n >>h;
    double h1 = h*1/sqrt(n);
    for(int i=1;i<n;i++){
        cout <<fixed<<setprecision(15)<< h1*sqrt(i)<<' ';
    }
}

