#include <bits/stdc++.h>
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a=__gcd(a,abs(x-i));
    }
    vector<int> ans;
    for(int i=1;i<=a;i++)
        if(!(a%i)) ans.push_back(i);
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);

}
