#include <bits/stdc++.h>
#define elif else if
#define X real()
#define Y imag()
using namespace std;

vector<complex<int> > M[2];
vector<complex<int> > Mp;
bool cmp (const complex<int>& x,const complex<int>& y) {
    if(x.X==y.X) return x.Y<y.Y;
    return x.X<y.X;
}
bool equal (const complex<int>& x,const complex<int>& y){
    return x.X==y.X&&x.Y==y.Y;
}
main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n;
    M[0].resize(n);
    for(int i=0; i<n; i++)
        cin>>M[0][i].X>>M[0][i].Y;
    cin>>m;
    M[1].resize(m);
    for(int i=0; i<m; i++)
        cin>>M[1][i].X>>M[1][i].Y;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
                Mp.push_back(M[1][j]-M[0][i]);
            }
        }
    complex<int> mcs;
    int ans1=0;
    sort(Mp.begin(),Mp.end(),cmp);
    for(int i=0;i<Mp.size();i++){
        int j=i;
        while(j+1<Mp.size()&&equal(Mp[i],Mp[j+1])) j++;
        if(j-i+1>ans1){
            ans1=j-i+1;
            mcs=Mp[i];
        }
        i=j;

    }
    cout<<mcs.X<<" "<<mcs.Y<<endl;
    }


