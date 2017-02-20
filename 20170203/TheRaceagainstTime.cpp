#include <bits/stdc++.h>
using namespace std;
const int inf = 1000;
int dist[111][111];
int main() {
    int V, s;
    cin >> V;
    cin >> s;
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++) {
            cin >> dist[i][j];
            if(!dist[i][j]) dist[i][j] = inf;
        }
        dist[i][i] = 0;
    }
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for (int i = 0; i < V; i++)
        cout << i << ':' << dist[s][i] << endl;
}
