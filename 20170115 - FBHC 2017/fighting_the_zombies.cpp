#include <bits/stdc++.h>
using namespace std;
int x[55],y[55];
bool between(int l,int r,int val){
    return val <= r && val >= l;
}
void run(int numtest){
    int n,r;
    cin >> n >>r;
    for(int i=0; i < n;i++)
        cin >> x[i] >> y[i];
    int ans = 0;
    for(int i=0; i < n;i++)
        for(int j=0; j < n; j++)
            for(int l = 0; l < n; l++)
                for(int k = 0 ; k < n; k++){
                    int x1 = x[i],x2 = x[j];
                    int y1 = y[l],y2 = y[k];
                    int cnt = 0;
                    for(int it = 0; it < n; it++){
                        if(between(x1-r,x1,x[it])&&between(y1-r,y1,y[it])) cnt ++;
                        else if(between(x2-r,x2,x[it])&&between(y2-r,y2,y[it])) cnt ++;
                    }
                    if(cnt > ans) ans = cnt;
                }
    cout<<"Case #"<<numtest<<": "<<ans <<endl;
    cerr<<"Case #"<<numtest<<": "<<ans <<endl;

}
main(){
    freopen("fighting_the_zombies.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i <= t; i++)
        run(i);
}
