#include <bits/stdc++.h>
using namespace std;
int X[4] = {1,0,-1,0};
int Y[4] = {0,1,0,-1};
deque<pair<int,int> > snakeq;
set<pair<int,int> > snakes;
set<pair<int,int> > eaten;
vector<pair<int,char> > change;
int r,c;
int dir;

bool move(){
    int x = snakeq.front().first;
    int y = snakeq.front().second;
    int newX = (x+X[dir]+r)%r;
    int newY = (y+Y[dir]+c)%c;
    if((newX+newY)%2 && eaten.find(make_pair(newX,newY))== eaten.end()){
        eaten.emplace(newX,newY);
    }else{
        snakes.erase(snakeq.back());
        snakeq.pop_back();
    }
    snakeq.emplace_front(newX,newY);
    snakes.emplace(newX,newY);
    return snakeq.size() == snakes.size();
}
void solve(int nTest) {
    int n;
    double ans = 0;
    dir = 1;
    eaten.clear();
    snakeq.clear();
    snakes.clear();
    cin >>n >> r >> c;
    change.resize(n);
    for(int i=0;i<n;i++)
        cin >> change[n-i-1].first>>change[n-i-1].second;
    snakeq.emplace_back(0,0);
    snakes.emplace(0,0);
    int last = change[0].first;
    for(int st = 0; st < 1000000000; st++){
        if(change.size() && change.back().first == st){
            if(change.back().second == 'R') dir = (dir + 3)%4;
            else dir = (dir + 1)%4;
            change.pop_back();
        }
        if(!move()||st - last > 2*(r+c)) break;
    }

    cout << "Case #"<<nTest<<": "<<snakeq.size()<<endl;
}
main() {
    freopen("D-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}



