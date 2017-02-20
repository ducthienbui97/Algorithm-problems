#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

string canonical(const string& s) {
  vector<string> parts;
  int zeros = 0;
  int ones = 0;
  int current_start = 1;

  for (size_t i = 0; i < s.size(); ++i) {
    if (s[i] == '0') {
      zeros += 1;
    } else {
      ones += 1;
    }

    if (zeros == ones) {
      parts.push_back("0" + canonical(s.substr(current_start, i-current_start+1)) + "1");
      current_start = i + 2;
    }
  }

  string ans;
  sort(parts.begin(), parts.end());

  for (size_t i = 0; i < parts.size(); ++i) {
    ans += parts[i];
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
