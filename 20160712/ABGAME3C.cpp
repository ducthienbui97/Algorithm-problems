#include <bits/stdc++.h>
using namespace std;
int F[111][111][2][2];
bool done[111][111][2][2];
int x,y,z,n;
string mString;
const int INF = 1e9;
int price(int loc,int l, int r, int swapL,int swapR) {
    if(loc > r || loc <l || mString[loc] == '#') return z;
    bool temp = (mString[loc]=='A');
    if(loc == l && swapL) temp = !temp;
    if(loc == r && swapR) temp = !temp;
    if(temp) return x;
    else return y;
    }
int answer(int l,int r,bool swapL = false,bool swapR = false) {
    if(l>r) return 0;
    if(l==r) {
        if(mString[l] == '#') return 0;
        bool temp = (mString[l]=='A');
        if(swapL) temp = !temp;
        if(swapR) temp = !temp;
        if(temp)
            return z*2;
        else
            return -INF;
        }
    if(done[l][r][swapL][swapR]) return F[l][r][swapL][swapR];
    done[l][r][swapL][swapR] = true;
    F[l][r][swapL][swapR] = INF;
    for(int i = l; i <= r; i++)
        if(mString[i]=='#') {
            int tempL = answer(l,i-1,swapL,false);
            int tempR = answer(i+1,r,false,swapR);
            if(tempL == -INF) return - INF;
            if(tempR == -INF) return - INF;
            return F[l][r][swapL][swapR]=tempL+tempR;
            }
    for(int i = l; i <= r; i++) {
        if(mString[l] == '#') return 0;
        bool temp = (mString[i]=='A');
        if(swapL && i == l) temp = !temp;
        if(swapR && i == r) temp = !temp;
        if(temp) {
            int tempL = answer(l,i-1,swapL,true);
            int tempR = answer(i+1,r,true,swapR);
            int tempSum = tempL + tempR + price(i+1,l,r,swapL,swapR) + price(i-1,l,r,swapL,swapR);
            if(tempL == -INF) tempSum = INF;
            if(tempR == -INF) tempSum = INF;
            F[l][r][swapL][swapR] = min(F[l][r][swapL][swapR],tempSum);
            }
        }
    if(F[l][r][swapL][swapR] == INF)
        F[l][r][swapL][swapR] =  -INF;
    return F[l][r][swapL][swapR];
    }
main() {
    freopen("ABGAME3C.INP","r",stdin);
    freopen("ABGAME3C.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin >> x >> y >> z >> mString;
    n = mString.length();
    cout << max(answer(0,n-1) - 2*z,-1) << endl;
    }
