#include <set>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#define elif else if
using namespace std;
vector<int> d;
main() {
    ios_base::sync_with_stdio(false);
    string S1,S2;
    int n1,n2,t;
    cin>>n1>>n2;
    cin>>S1>>S2;
    reverse(S1.begin(),S1.end());
    cin>>t;
    for(int i=1;i<=n1;i++)
        d.push_back(1);
    for(int i=1;i<=n2;i++)
        d.push_back(2);

    while(t--){
        for(int i=1;i<d.size();i++)
            if(d[i-1]==1&&d[i]==2) swap(d[i-1],d[i]),i++;
    }
    int cnt1=0;
    int cnt2=0;
    for(int i=0;i<d.size();i++){
     //   cout<<i<<endl;
        if(d[i]==1){
            putchar(S1[cnt1++]);
        }
        else{
            putchar(S2[cnt2++]);
        }
    }
}
