// https://www.quora.com/about/challenges
#include <bits/stdc++.h>
#define MAX 100111
using namespace std;
map<string,int> mp;
vector<int> pr;
vector<vector<int> > d;
vector<int> st,fn;
class LIS{
private:
    vector<int> lis;
public:
    int get(int x){
        return lower_bound(lis.begin(),lis.end(),x+1) - lis.begin();
    }
    void update(int x){
        lis.push_back(x);
    }
    void sort(){
        std::sort(lis.begin(),lis.end());
    }
};
class TRIE{
private:
    vector<LIS> trie;
    vector<vector<int> > next;
public:
    TRIE(){
        next.resize(1,vector<int>(256,0));
        trie.resize(1);
    }
    void insert(const string& s,int topicID){
        int cur = 0;
        for(int i=1;i<s.size();i++){
            if(!next[cur][s[i]]){
                next[cur][s[i]] = next.size();
                next.push_back(vector<int>(256,0));
                trie.push_back(LIS());
            }
            cur = next[cur][s[i]];
            trie[cur].update(st[topicID]);
        }
    }
    int get(const string& s,int topicID){
        int cur = 0;
        for(int i=1;i<s.size();i++){
            if(!next[cur][s[i]]){
                return 0;
            }
            cur = next[cur][s[i]];

        }
        return trie[cur].get(fn[topicID]) - trie[cur].get(st[topicID]-1);
    }
    void sort(){
        for(int i=0;i<trie.size();i++)
            trie[i].sort();
    }
};
void parse(string s){
    stringstream ss(s);
    stack<int> st;
    int ls = -1;
    while(ss >> s){
        if(s[0] == '(') st.push(ls);
        else if(s[0] == ')') st.pop();
        else if(st.empty()){
            pr[mp.size()] = -1;
            ls = mp.size();
            mp[s] = ls;
        }else {
            pr[mp.size()] = st.top();
            ls = mp.size();
            mp[s] = ls;
            d[st.top()].push_back(ls);
        }
    }
}
int cnt;
void dfs(int u){
    st[u] = ++cnt;
    for(int v:d[u]) dfs(v);
    fn[u] = cnt;
}
int main(){
    int n;
    cin >> n;
    pr.resize(n);
    st.resize(n);
    fn.resize(n);
    d.resize(n);
    string s;
    getline(cin,s);
    getline(cin,s);
    parse(s);
    for(int i=0;i<n;i++)
        if(pr[i] < 0) dfs(i);
    int m;
    cin >> m;
    TRIE myTrie;
    for(int i=0;i<m;i++){
        cin >> s;
        s.pop_back();
        int topicId = mp[s];
        getline(cin,s);
        myTrie.insert(s,topicId);
    }
    myTrie.sort();
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> s;
        int topicId = mp[s];
        getline(cin,s);
        cout << myTrie.get(s,topicId) <<endl;
    }
}
