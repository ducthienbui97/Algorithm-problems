#include <bits/stdc++.h>
#define elif else if
#define mp(a,b,c) make_pair(make_pair(a,b),c)
using namespace std;
set<pair<pair<int,int>,int> > ms;
set<pair<pair<int,int>,int> >::iterator it;
string S;
pair<int,int> a[200111];
main(){
    int x,y,n;
    ios_base::sync_with_stdio(false);
    cin>>n;
    int cnt=0;
    while(n--){
        cin>>S;
        if(S=="D"){
            cin>>x>>y;
            a[++cnt]=make_pair(x,y);
            ms.insert(mp(x,y,cnt));
        }
        else{
            cin>>x;
            y=-1;
            it=ms.upper_bound(make_pair(a[x],x));
            while(it!=ms.end()){
                if((*it).first.second>=a[x].second){
                    y=it->second;
                    it=ms.end();
                }
                else it++;
            }
            if(y==-1) puts("NE");
            else printf("%d\n",y);
        }
    }
}
