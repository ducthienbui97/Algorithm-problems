#include <bits/stdc++.h>
using namespace std;
const int base = 1e9+7;
typedef long long ll;
ll F[255][10][2][2555];
ll C[255][10][2][2555];
bool done[255][10][2][2555];
int n;
char S[255];
void update(int idx, long long v,ll BIT[]) {
    for(int i = idx; i < 2555; i += (i&-i))
        BIT[i] = (BIT[i] + v)%base;
}
long long get(int idx, ll BIT[]) {
    long long r = 0;
    for(int i = idx; i > 0; i -= (i&-i))
        r = (r + BIT[i])%base;
    return r;
}
pair<ll,ll> find(int idx,int last, bool sml, int sum) {
    if(sum < 1)
        return {0,0};
    if(idx >= n) {
        if(sum == 1)
            return {1,last};
        return {0,0};
    }
    if(done[idx][last][sml][sum])
        return {
        get(sum, C[idx][last][sml]) - get(sum - 1, C[idx][last][sml]),
        get(sum, F[idx][last][sml])
    };
    done[idx][last][sml][sum] = true;
    long long tmpC = 0, tmpF = 0;
    for(int i = 0; i < 10; i++) {
        if(!sml && i + '0' > S[idx + 1])
            break;
        auto u = find(idx+1,i,sml || i + '0' < S[idx + 1], sum - i);
        tmpC = (tmpC + u.first)%base;
        auto v = find(idx+1,i,sml || i + '0' < S[idx + 1], sum - i - 1);
        tmpF = (tmpF + v.second)%base;
    }
    for(int i = last - 1; i>=0; i--){
        auto u = find(idx, i, true, sum - 1);
        tmpF += u.first;
    }
    if(tmpC){
        update(sum,tmpC, C[idx][last][sml]);
        update(sum,tmpF - get(sum - 1, F[idx][last][sml]), F[idx][last][sml]);
    }
    return {
        get(sum, C[idx][last][sml]) - get(sum - 1, C[idx][last][sml]),
        get(sum, F[idx][last][sml])
    };
}
int main() {
    ios_base::sync_with_stdio(false);
    S[0] = '0';
    cin >> &S[1];
    n = strlen(&S[1]);
    long long ans = 0;
    for(int i=1; i<= 12;i++)
        cout << find(0,0,false,i).second << endl;
    return 0;
}
