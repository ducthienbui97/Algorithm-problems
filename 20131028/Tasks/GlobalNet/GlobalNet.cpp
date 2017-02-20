#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define debug 0
using namespace std;

int N,M, counter = 0, Smax = 1, S2, number;
vector<int> low, d, trace, belongs, result;
vector<vector<int> > edges;
stack<int> st;

void read(){
    cin>>N>>M;
    d.clear();

    low.resize(N + 1);     d.resize(N + 1, 0);
    edges.resize(N + 1);   trace.resize(N + 1);
    result.clear();  belongs.resize(N + 1, 0);

    for (int i=0; i<M; i++) {
      int a,b;
      cin >> a >> b;
      edges[a].push_back(b);
      edges[b].push_back(a);
    }
}

void dfs (const int& x) {
    if (d[x])
        return;
    number++;
    st.push(x);
    counter++;
    d[x] = counter;
    low[x] = counter;
    int y;
    for (int i=0; i<edges[x].size(); i++){
        y = edges[x][i];
        if (d[y] == 0){
            trace[y] = x;
            dfs(y);
            /*if (low[y] > d[x]){
                belongs[x] += 2;
                belongs[y] += 2;
                if (st.top() == y)
                    st.pop();
                else
                    if (debug)
                        cout<<"wrong algorithm"<<endl;
            }/**/
            low[x] = min(low[x], low[y]);
        }
        if (trace[x] != y)
            low[x] = min(low[x], d[y]);
    }
    if (trace[x] != 0 && low[x] >= d[trace[x]]){
        int t = 0, tmp;
        while (true){
            t++;
            tmp = st.top();
            if (debug) cout<<tmp<<" ";
            st.pop();
            belongs[tmp]++;
            if (tmp == x)
                break;

        }
        if (debug)
            cout<<trace[x]<<endl;
        belongs[trace[x]]++;
        Smax = max(t + 1, Smax);
    }
    if (debug) cout<<"low["<<x<<"] = "<<low[x]<<endl;
}

void print(){
    int total = 0;
    sort(result.begin(), result.end());
    for(int i=1; i<=N; i++)
        if (belongs[i] > 1){
            total++;
            result.push_back(i);
        }
    cout<<total<<" "<<Smax<<endl;
    for(int i=0; i<result.size(); i++)
        cout<<result[i]<<endl;
}

int main () {
    freopen("globalnet.inp", "r", stdin);
    if (!debug)    freopen("globalnet.out", "w", stdout);
    read();
    S2 = 0;
    for(int i=1; i<=N; i++){
        while (!st.empty())
            st.pop();
        number = 0;
        dfs(i);
        if (number == 2)
            S2++;
    }
    print();
    return 0;
}
