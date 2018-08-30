#include <bits/stdc++.h>

using namespace std;
struct node {
    unordered_map<char,int> NX;
    int cnt = 0;
};
vector<node> tree;
void insert(const string& s){
    int current = 0;
    for(char c: s){
        tree[current].cnt ++;
        if(tree[current].NX.find(c) == tree[current].NX.end()){
            tree[current].NX[c] = tree.size();
            tree.push_back(node());
        }
        current = tree[current].NX[c];
    }

}
main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        tree.clear();
        tree.push_back(node());
        int n;
        string s;
        cin >> n;
        bool zero = false;
        getline(cin,s);
        for(int i = 0; i < n; i++){
            getline(cin,s);
            insert(s);
            zero |= !s.size();
        }
        int current = 0;
        s.clear();
        while(!zero && tree[current].NX.size() == 1 && tree[current].cnt == n){
            s.push_back(tree[current].NX.begin() -> first);
            current = tree[current].NX.begin() -> second;
        }
        cout << s << endl;
    }
}

