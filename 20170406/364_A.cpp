#include <bits/stdc++.h>
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    int n,k;
    double l,v1,v2;
    cin >> n >> l >> v1 >> v2 >> k;
    double ll = l/v2;
    double rr = l/v1;
    for(int i=0;i<100;i++){
        double mm = (ll + rr)/2;
        double dis = l - mm*v1;
        double tra = dis/(v1+v2);
        double onbus =  dis/(v2-v1);
        double time = 0;
        double cur = 0;
        for(int f = 0; f < n; f+=k){
            time += onbus;
            cur += onbus*v1;
            if(f+k < n){
                cur += tra*v1;
                time += tra;
            }
        }
        if(time <= mm) rr = mm;
        else  ll = mm;
    }
    printf("%.10f",ll);
}
