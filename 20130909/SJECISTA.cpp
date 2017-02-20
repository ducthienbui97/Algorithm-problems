#include <set>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#define elif else if
using namespace std;
main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    cout<<n*(n-1)*(n-2)*(n-3)/(4*3*2);
}
