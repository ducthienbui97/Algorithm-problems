#include <bits/stdc++.h>
using namespace std;

vector<double> f;
int n;

int run(){
    int res;
    f.clear();
    cin>>n;
    double a,b;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        if(a==0) continue;
        f.push_back(b/a);
    }
    sort(f.begin(),f.end());
    res=f.size();
    for(int i=1;i<f.size();i++){
        if(f[i]-f[i-1]<0.000000001) --res;
    }
    cout<<res<<endl;
}

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        run();
    }
}
