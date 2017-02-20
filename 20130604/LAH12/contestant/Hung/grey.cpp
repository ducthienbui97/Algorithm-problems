#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define maxn 1009

using namespace std;

string dec2gray(int index, int M) {
    string ret = "";
    int x, y = index;
    while (M > 0) {
        if (y > ((1 << M) - 1) / 2) {
            ret.push_back('1');
            x = (1 << M) - 1 - y;
        } else {
            ret.push_back('0');
            x = y;
        }
        M--;
        y = x;
    }
    return ret;
}

int main(){
    freopen("grey.inp","r",stdin);
    freopen("grey.out","w",stdout);
    int n;
    int i;
    int ct=0;
    int res;
    scanf ("%d",&n);
    res=1<<n;
    while (true) {
        cout<<dec2gray(ct,n)<<"\n";
        ct++;
        if (ct==res) break;
    }
}
