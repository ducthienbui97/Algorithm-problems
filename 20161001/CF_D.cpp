#include <bits/stdc++.h>
using namespace std;
set<int> y;
main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        y.insert(x);
    }
    while(true){
        int x = *y.rbegin();
        y.erase(x);

        for(int i = x/2; i != 0; i = i/2){
            if(y.find(i) == y.end()){
                y.insert(i);
                break;
            }
        }
        if(y.size() < n){
            y.insert(x);
            break;
        }
    }
    for(set<int>::iterator it = y.begin(); it != y.end(); it++){
        cout << *it <<' ';
    }
}
