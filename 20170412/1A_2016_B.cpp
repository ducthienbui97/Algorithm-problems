#include <bits/stdc++.h>
using namespace std;
bool lost[2555];
void solve(int nTest){
    memset(lost,0,sizeof lost);
    int n;
    cin >> n;
    for(int i=1;i<2*n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            lost[x] = !lost[x];
        }
    }
    cout <<"Case #"<<nTest<<":";
    for(int i=0;i<=2500;i++)
        if(lost[i])
            cout <<' '<<i;
    cout <<endl;

}
main(){
     freopen("B-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
    }

