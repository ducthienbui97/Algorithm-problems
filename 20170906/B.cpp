#include <bits/stdc++.h>
using namespace std;
const long long inf = 4557430888798830399;
const int Maxn = 1e6 + 20;
vector<pair<int, pair<int,int> > > to;
vector<pair<int, pair<int,int> > > fr;
long long bestFlyTo[Maxn];
long long bestFlyFr[Maxn];
int best[Maxn];
main(){
    ios_base::sync_with_stdio(false);
    int n,m,k;
    memset(bestFlyTo,0x3f,sizeof bestFlyTo);
    memset(bestFlyFr,0x3f,sizeof bestFlyFr);
    cin >> n >> m >> k;
    for(int i=0; i< m; i++){
        int d,f,t,c;
        cin >> d >> f >> t >> c;
        if(!f)
            fr.emplace_back(d,make_pair(t,c));
        else
            to.emplace_back(d,make_pair(f,c));
    }

    sort(fr.begin(),fr.end());
    sort(to.begin(),to.end());

    int cnt = 0;
    memset(best, 0,sizeof best);
    long long currentTotal = 0;
    for(int i = 0; i < to.size(); i++){
        int d = to[i].first;
        int org = to[i].second.first;
        int cos = to[i].second.second;
        if(!best[org]){
            best[org] = cos;
            currentTotal += cos;
            cnt ++;
        }else if(best[org] > cos){
            currentTotal -= best[org];
            best[org] = cos;
            currentTotal += cos;
        }
        if(cnt == n)
            bestFlyTo[d] = min(bestFlyTo[d],currentTotal);
    }
    if(cnt < n){
        cout << -1;
        return 0;
    }
    cnt = 0;
    memset(best, 0,sizeof best);
    currentTotal = 0;
    for(int i = fr.size() - 1; i >= 0; i --){
        int d = fr[i].first;
        int org = fr[i].second.first;
        int cos = fr[i].second.second;
        if(!best[org]){
            best[org] = cos;
            currentTotal += cos;
            cnt ++;
        }else if(best[org] > cos){
            currentTotal -= best[org];
            best[org] = cos;
            currentTotal += cos;
        }
        if(cnt == n)
            bestFlyFr[d] = min(bestFlyFr[d],currentTotal);
    }
    if(cnt < n){
        cout << -1;
        return 0;
    }

    for(int i=1; i < Maxn; i++)
        bestFlyTo[i] = min(bestFlyTo[i-1],bestFlyTo[i]);
    for(int i = Maxn - 1; i > 0; i--)
        bestFlyFr[i] = min(bestFlyFr[i+1],bestFlyFr[i]);

    long long ans = inf;
    for(int i=1; i + k + 1< Maxn; i++){
        ans = min(ans,bestFlyTo[i] + bestFlyFr[i+k+1]);
    }
    if(ans == inf)
        ans = -1;
    cout << ans;
    return 0;

}
