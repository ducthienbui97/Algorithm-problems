#include <bits/stdc++.h>
using namespace std;
void solve(int numTest){
    int n;
    cin >> n;
    priority_queue<pair<int,int> > p;
    vector<string> ans;
    int senates = 0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        p.push(make_pair(x,i));
        senates += x;
    }
    while(!p.empty()){
        int num = p.top().first;
        int pt = p.top().second;
        p.pop();
        if(!num) continue;
        if(2*num == senates){
            int num2 = p.top().first;
            int pt2 = p.top().second;
            p.pop();
            senates -= 2;
            ans.push_back({pt+'A',pt2+'A'});
            p.push(make_pair(num-1,pt));
            p.push(make_pair(num2-1,pt2));
        }else{
            ans.push_back({pt+'A'});
            senates -=1;
            p.push(make_pair(num-1,pt));
        }
    }

    cout <<"Case #"<<numTest<<':';
    for(int i=0;i<ans.size();i++)
        cout <<' '<<ans[i];
    cout <<endl;
}
main(){
    freopen("A-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}
