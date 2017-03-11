// https://www.quora.com/about/challenges
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> non_i(n),non_d(n);
    vector<int> rev_non_i(n),rev_non_d(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    non_i[0] = 0;
    non_d[0] = 0;
    for(int i=1;i<n;i++){
        if(a[i] >= a[i-1]) non_d[i] = min(non_d[i-1]+1,k-1);
        else non_d[i] = 0;
        if(a[i] <= a[i-1]) non_i[i] = min(non_i[i-1]+1,k-1);
        else non_i[i] = 0;
    }
    rev_non_i[n-1] = 0;
    rev_non_d[n-1] = 0;
    for(int i=n-1;i>0;i--){
        if(a[i] >= a[i-1]) rev_non_d[i-1] = min(rev_non_d[i]+1,k-1);
        else rev_non_d[i-1] = 0;
        if(a[i] <= a[i-1]) rev_non_i[i-1] = min(rev_non_i[i]+1,k-1);
        else rev_non_i[i-1] = 0;
    }
    long long n_inc=0,n_dec=0;
    for(int i=0;i<k;i++){
        n_inc += non_i[i];
        n_dec += non_d[i];
    }
    cout << n_dec - n_inc<<endl;
    for(int i=k;i<n;i++){
        n_inc -= rev_non_i[i-k];
        n_dec -= rev_non_d[i-k];
        n_inc += non_i[i];
        n_dec += non_d[i];
        cout << n_dec - n_inc <<endl;
    }
}
