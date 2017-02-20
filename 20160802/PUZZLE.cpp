#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > Q;

int n;
int X[]={-1,0,1,0};
int Y[]={0,-1,0,1};
class board{
    public:
    vector<int> v;
    int x,y,value;
    bool calculatedH,calculatedV;
    int hash_value;
    int cal_hash(){
        if(calculatedH) return hash_value;
        calculatedH = true;
        hash_value  = 0;
        for(int i = 0;i<v.size();i++)
            hash_value = hash_value*17+v[i]+1;
        return hash_value;
    }
    int cal_value(){
        if(calculatedV) return value;
        value = 0;
        for(int i=0;i<v.size();i++){
            value += abs(i/n-v[i]/n)+abs(i%n-v[i]%n);
        }
        return value;
    }
};
vector<pair<pair<int,int>,pair<int,int> > > ans;
map<int,board*> md;
map<int,int> parent;
map<int,int> done;
void trace(int value){
    if(parent[value] == -1) return;
    int p = parent[value];
    board * ch = md[value];
    board * pr = md[p];
    ans.push_back(make_pair(make_pair(ch->x,ch->y),make_pair(pr->x,pr->y)));
    trace(p);
}
bool between(int l,int r,int v){
    return l<=v&&v<r;
}
main(){
    //freopen("PUZZLE.INP","r",stdin);
    //freopen("PUZZLE.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin >> n;
    board* b = new board;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            x -- ;
            b -> v.push_back(x);
            if(x == n*n - 1){
                b -> x = i;
                b -> y = j;
            }

        }
    Q.push(make_pair(b->cal_value(),b->cal_hash()));
    parent[b -> cal_hash()] = -1;
    md[b -> cal_hash()] = b;
    done[b->cal_hash()] = b->cal_value();
    while(!Q.empty()){
        int value = Q.top().first;
        int has = Q.top().second;
        Q.pop();
        if(value == 0){
            trace(has);
            break;
        }
        else{
            board *bb = md[has];
            for(int i=0;i<4;i++){
                if(between(0,n,(bb->x) + X[i])&&between(0,n,(bb->y)+Y[i])){
                    board *newV =new board;
                    newV -> x = bb->x + X[i];
                    newV -> y = bb->y + Y[i];
                    newV -> v = bb->v;
                    swap(newV->v[bb->x*n+bb->y],newV->v[(bb->x+X[i])*n+bb->y+Y[i]]);
                    if(done.find(newV->cal_hash())==done.end()||done[newV->cal_hash()] > newV -> cal_value()){
                        done[newV->cal_hash()] = newV->cal_value();
                        md[newV->cal_hash()] = newV;
                        parent[newV->cal_hash()] = bb->cal_hash();
                        Q.push(make_pair(newV->cal_value(),newV->cal_hash()));
                    }
                }
            }
        }
    }
    cout<<ans.size() <<endl;
    for(int i=ans.size()-1;i>=0;i--)
        cout << ans[i].first.first+1 <<" "<<ans[i].first.second+1 <<" "<<ans[i].second.first+1 <<" " <<ans[i].second.second+1 <<endl;
}
/*
2
4 1
3 2
*/
