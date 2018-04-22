#include <bits/stdc++.h>
using namespace std;
vector<int> ls[20];
map<int,int> start;
int n,k;
long long p;
void calF(int c) {
    if(c == n)
        return;
    int remaining = n - c;
    int determined = start.size();
    if(start.find(c) != start.end()){
        putchar(start[c] + '0');
        start.erase(c);
        calF(c + 1);
    }else{
        if(remaining - determined - 1 >= 60){
            putchar('0');
            calF(c + 1);
        }else{
            long long counter = 1ll<<(remaining - determined - 1);
            if(counter >= p){
                putchar('0');
                calF(c + 1);
            }else{
                putchar('1');
                p -= counter;
                calF(c + 1);
            }
        }
    }
}
void solve(int ntest) {
    cin >> n >> k >> p;
    vector<int> a(k),b(k),c(k);
    for(int i=0; i < k; i++) {
        cin >> a[i] >> b[i] >> c[i];
        start[a[i] - 1] = c[i];
    }

    cout << "Case #" << ntest <<": ";
    calF(0);
    cout << endl;
}
main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    for(int i=1; i <= t; i ++)
        solve(i);
}

