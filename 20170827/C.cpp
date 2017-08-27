#include <bits/stdc++.h>
using namespace std;
double dist(int x1,int y1,int z1,int x2, int y2, int z2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2);
}
void solve(int ntest){
    vector<int> x(3),y(3),z(3);
    vector<double> d;
    double ans;
    for(int i=0;i<3;i++)
        cin >> x[i] >> y[i] >> z[i];
    for(int i=0; i < 3; i++)
        for(int j=0; j < i; j++)
            d.push_back(sqrt(dist(x[i],y[i],z[i],x[j],y[j],z[j])));
    sort(d.begin(),d.end());
    if(d[0] + d[1] >= d[2] - 1e-6 && d[0] + d[1] <= d[2] + 1e-6){
        ans =  d[2]/6;
    }else{
        double r = (d[0]*d[1]*d[2])/sqrt((d[0]+d[1]+d[2])*(-d[0]+d[1]+d[2])*(d[0]-d[1]+d[2])*(d[0]+d[1]-d[2]));
        if(r/2 >= d[2]/4)
            ans = d[2]/4;
        else
            ans = r/2;
    }
    cout << "Case #" << ntest <<": " << fixed <<setprecision (10) << ans <<endl;
}
main(){
    freopen("test.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    for(int i = 1; i <= test; i++)
        solve(i);
}