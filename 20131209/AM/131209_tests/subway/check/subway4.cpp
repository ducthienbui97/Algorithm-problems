#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct graph {
  int size;
  vector<vector<int> > al;
};

graph build_graph(const string& s) {
  graph result;
  result.size = s.size()/2 + 1;
  result.al.resize(result.size);

  vector<int> cur_node;
  cur_node.push_back(0);
  int last_used = 0;

  for (size_t i = 0; i < s.size(); ++i) {
    if (s[i] == '0') {
      cur_node.push_back(++last_used);
    } else {
      int parent = cur_node[cur_node.size() - 2];
      int cur = cur_node[cur_node.size() - 1];
      cur_node.pop_back();

      result.al[parent].push_back(cur);
      result.al[cur].push_back(parent);
    }
  }

  return result;
}

string repr(int node, const graph& g, int parent) {
  vector<string> temp;

  for (size_t i = 0; i < g.al[node].size(); ++i) {
    if (g.al[node][i] == parent) continue;

    temp.push_back(repr(g.al[node][i], g, node));
  }

  string ans;
  sort(temp.begin(), temp.end());

  for (size_t i = 0; i < temp.size(); ++i) {
    ans += "0";
    ans += temp[i];
    ans += "1";
  }

  return ans;
}

string canonical(const graph& g) {
  vector<int> height(g.size, -1);
  queue<int> q;

  for (size_t i = 0; i < g.al.size(); ++i) {
    if (g.al[i].size() == 1) {
      q.push(i);
      height[i] = 0;
    }
  }

  while (!q.empty()) {
    int x = q.front();
    q.pop();

    for (size_t j = 0; j < g.al[x].size(); ++j) {
      int y = g.al[x][j];
      if (height[y] < 0) {
        height[y] = height[x] + 1;
        q.push(y);
      }
    }
  }

  int max_height = *max_element(height.begin(), height.end());
  vector<string> ans;

  for (size_t i = 0; i < g.size; ++i) {
    if (height[i] != max_height) continue;

    ans.push_back(repr(i, g, -1));
  }

  return *min_element(ans.begin(), ans.end());
}

string canonical(const string& s) {
  vector<vector<string> > stack;

  for (size_t i = 0; i < s.size(); ++i) {
    if (s[i] == '0') {
      stack.push_back(vector<string>());
    } else {
      vector<string>& children = stack[stack.size()-1];
      string sortedChildren;
      sort(children.begin(), children.end());
      for (size_t j = 0; j < stack[0].size(); ++j) {
        sortedChildren += "0";
        sortedChildren += children[i];
        sortedChildren += "1";
      }

      stack.pop_back();
      stack[stack.size()-1].push_back(sortedChildren);
    }
  }

  string ans;
  sort(stack[0].begin(), stack[0].end());

  for (size_t i = 0; i < stack[0].size(); ++i) {
    ans += "0";
    ans += stack[0][i];
    ans += "1";
  }

  return ans;
}

int main(int argc, char** argv) {
  int n;
  cin >> n;

  set<string> unique;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    unique.insert(canonical(build_graph(s)));
  }

  cout << unique.size() << endl;
}
