#include <bits/stdc++.h>
using namespace std;
const int Maxn=1e6+1;
int counter[Maxn];
set<pair<int,int> > box;
int main(){
    freopen("C.inp","r",stdin);
    freopen("C.out","w",stdout);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int input;
        cin >> input;
        if(!counter[input]++){
            box.insert(make_pair(0,input));
        }
        box.erase(make_pair(-counter[input]+1,input));
        box.insert(make_pair(-counter[input],input));
        cout << box.begin()->second << endl;
    }
}
