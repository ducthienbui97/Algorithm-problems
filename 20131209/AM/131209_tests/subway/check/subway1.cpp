#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> parts(const string& s) {
  vector<string> ans;
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
      ans.push_back(s.substr(current_start, i-current_start+1));
      current_start = i + 2;
    }
  }

  return ans;
}

bool compare(const string& x, const string& y) {
  const vector<string>& a = parts(x);
  vector<string> b = parts(y);

  if(a.size() != b.size()) return false;

  for (size_t i = 0; i < a.size(); ++i) {
    bool foundMatch = false;
    for (size_t j = 0; j < b.size(); ++j) {
      if (compare(a[i], b[j])) {
        b.erase(b.begin()+j);
        foundMatch = true;
        break;
      }
    }
    if (!foundMatch)
      return false;
  }

  return true;
}

int main(int argc, char** argv) {
  int n;
  cin >> n;

  vector<string> unique;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    bool foundMatch = false;
    for (size_t j = 0; j < unique.size(); ++j) {
      if (compare(s, unique[j])) {
        foundMatch = true;
        break;
      }
    }

    if (!foundMatch) {
      unique.push_back(s);
    }
  }

  cout << unique.size() << endl;
}
