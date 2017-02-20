#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct Pair{
    int x, y;
    Pair(){
        x = y = 0;
    }
    Pair(int x, int y){
        this->x = x;
        this->y = y;
    }
};

bool comp(const Pair& p1, const Pair& p2){
    return (p1.x < p2.x) || (p1.x == p2.x && p1.y < p2.y);
}

int N,M, counter = 0;
vector<Pair> edges, result;

void gen(int n, int m){
    int x, y;
    for (int i=0; i<m; i++){
        x = rand() % n + 1;
        y = rand() % n + 1;
        if (x == y)
            continue;
        if (x > y)
            swap(x, y);
        edges.push_back(Pair(x, y));
    }
}


void print(){
}

int main (int no, char** args) {
    int n, m, x, y;
    if (no >= 3){
        //cout<<args[1]<<" "<<args[2]<<endl;
        n = atoi(args[1]);
        m = atoi(args[2]);
    } else{
        n = 10;
        m = 20;
    }
    gen(n, m);
    sort(edges.begin(), edges.end(), comp);
    int counter = edges.size();
    counter = 1;
    for (int i=1; i<edges.size(); i++)
        if (edges[i].x != edges[counter-1].x || edges[i].y != edges[counter-1].y){
            edges[counter++] = edges[i];
        }
    /*
    for (int i=0; i<counter; i++){
        x = rand() % counter;
        y = rand() % counter;
        swap(edges[x], edges[y]);
    }
    for (int i=0; i<counter; i++){
        x = rand()%counter;
        swap(edges[x].x, edges[x].y);
    }/**/
    cout<<n<<" "<<counter<<endl;
    for (int i=0; i<counter; i++)
        cout<<edges[i].x<<" "<<edges[i].y<<endl;
    return 0;
}
