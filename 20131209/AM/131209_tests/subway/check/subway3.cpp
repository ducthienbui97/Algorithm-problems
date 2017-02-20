#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

string canonical(const string& s) {
  vector<vector<string> > stack;
  stack.push_back(vector<string>());

  for (size_t i = 0; i < s.size(); ++i) {
    if (s[i] == '0') {
      stack.push_back(vector<string>());
    } else {
      vector<string>& children = stack[stack.size()-1];
      string sortedChildren;
      sort(children.begin(), children.end());
      for (size_t j = 0; j < children.size(); ++j) {
        sortedChildren += "0";
        sortedChildren += children[j];
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

    unique.insert(canonical(s));
  }

  cout << unique.size() << endl;
}
