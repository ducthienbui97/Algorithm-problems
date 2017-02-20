#include <bits/stdc++.h>
using namespace std;
vector<int> ls[20];
bool check[20];
main() {
    ios_base::sync_with_stdio(false);
    int n;
    int m;
    vector<int> id;
    cin >>n>>m;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pr;
    vector<int> v(m);
    int lcm = 1;
    for(int i=0; i<m; i++) {
        cin >> v[i];
        lcm = lcm*v[i]/__gcd(lcm,v[i]);
        if(!ls[v[i]].size())
            pr.push(make_pair(0,i));
        ls[v[i]].push_back(i);
        }
    int cnt = 0;
    for(int i=0; i<m; i++)
        cnt += lcm/v[i];
    n=n%cnt;
    for(int i=0; i<n;) {
        int temp = pr.top().first;
        id.clear();
        while(!pr.empty()&&pr.top().first==temp) {
            id.push_back(pr.top().second);
            pr.pop();
            }
        int s = 0;
        for(int j = 0 ; j < id.size(); j++)
            s += ls[v[id[j]]].size();
        if(i + s < n) {
            for(int j = 0; j< id.size(); j++)
                pr.push(make_pair(temp+v[id[j]],id[j]));
            i += s;
            }
        else {
            s = n - i;
            for(int j = 0 ; j < id.size(); j++) {
                check[v[id[j]]] = true;
                }
            for(int j = 0; j < m; j ++)
                if(check[v[j]]) {
                    if(--s==0) {
                        cout <<j + 1 <<endl;
                        return  0;
                        }
                    }
            }
        }
    }
