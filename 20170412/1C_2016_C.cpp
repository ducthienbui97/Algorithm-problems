#include <bits/stdc++.h>
using namespace std;

void solve(int numTest){
    int J,P,S,K;
    cin >> J >> P >> S >> K;
    cout <<"Case #"<<numTest<<": ";
    if(K>=S){
        cout << J*P*S<<endl;;
        for(int i=1;i<=J;i++)
            for(int j=1;j<=P;j++)
                for(int l=1;l<=S;l++)
                    cout << i <<" "<<j <<" "<<l<<endl;
        }
    else{
        cout << J*P*K << endl;
        for(int i=1;i<=J;i++)
            for(int j=1;j<=P;j++)
                for(int l=1;l<=K;l++)
                    cout <<i <<" "<<j <<" "<<(i+j+l)%S+1<<endl;
        }

}
main(){
    freopen("C-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}
