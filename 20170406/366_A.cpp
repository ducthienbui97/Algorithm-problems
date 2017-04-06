#include <bits/stdc++.h>
using namespace std;
const int Maxn = 3e5+30;
queue<int> que[Maxn];
vector<int> v;
set<pair<int,int> > ms;
main(){
    ios_base::sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    for(int i=0;i<q;i++){
        int t,x;
        cin >> t;
        if(t==1){
            cin >> x;
            que[x].push(i);
            v.push_back(i);
            ms.insert(make_pair(i,x));
        }else if(t==2){
            cin >> x;
            while(!que[x].empty()){
                ms.erase(make_pair(que[x].front(),x));
                que[x].pop();
            }
        }else{
            cin >> x;
            while(!ms.empty() && ms.begin() -> first <= v[x-1]) ms.erase(ms.begin());
        }
        cout << ms.size() <<endl;
    }
}
