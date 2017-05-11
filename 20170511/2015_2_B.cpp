#include <bits/stdc++.h>
using namespace std;
double X,V;
bool equal(double l, double r){
    return abs(l-r) < 1e-9;
}
void solve(int nTest){
    int n,m;
    cin >> n >> V >> X;
    double r0,x0,r1,x1;
    if(n == 1){
        cin >> r0 >> x0;
        if(!equal(x0,X)) cout << "Case #"<<nTest<<": IMPOSSIBLE\n";
        else cout <<"Case #"<<nTest<<": "<<fixed <<setprecision(15)<<V/r0<<endl;
    }else if(n == 2){
        cin >> r0 >> x0 >> r1 >> x1;
        cout << "Case #"<<nTest<<": ";
        if(equal(x0,X) && equal(x1,X)){
            double R = r0 + r1;
            cout << fixed <<setprecision(15) << V/R <<endl;
        }else if(equal(x0,X)){
            cout << fixed <<setprecision(15) << V/r0 <<endl;
        }else if(equal(x1,X)){
            cout << fixed <<setprecision(15) << V/r1 <<endl;
        }
        else{
            double t1 = ((X - x0)/(x1-x0))*(V/r1);
            double t0 = (V - r1*t1)/r0;
            if(t1 < 0 || t0 < 0) cout <<"IMPOSSIBLE\n";
            else cout <<fixed <<setprecision(15)<< max(t1,t0)<<endl;
        }
    }
}
main(){
    freopen("B-small-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}

