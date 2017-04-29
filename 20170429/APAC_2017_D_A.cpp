#include <bits/stdc++.h>
using namespace std;
bool done[2222][2222];
double F[2222][2222];
int n,m;
double cal(int A,int B){
    if(A <= B || A > n || B > m) return 0;
    if(A==n&&B==m) return 1;
    if(done[A][B]) return F[A][B];
    done[A][B] = true;
    int rmA = (n-A);
    int rmB = (m-B);
    return F[A][B] = cal(A+1,B)*rmA/(rmA+rmB) + cal(A,B+1)*rmB/(rmA+rmB);
}
void solve(int nTest) {
    memset(done,0,sizeof done);
    cin >> n >> m;
    cout << "Case #"<<nTest<<": " << cal(1,0)*n/(n+m) <<endl;

}
main() {
    freopen("A-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}



