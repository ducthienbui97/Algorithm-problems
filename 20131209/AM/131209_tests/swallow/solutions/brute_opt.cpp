#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const int MAX_SIZE = 500;

string toString(int v) {
  ostringstream oss;
  oss << v;

  return oss.str();
}

string fold(const string& s) {
  if (s.size() == 1)
    return s;

  string ans = s;
  for (int i = 1; i < s.size(); ++i) {
    const string p1 = s.substr(0, i);
    const string p2 = s.substr(i);
    const string p1a = fold(p1);
    const string p2a = fold(p2);

    if (p1a.size() + p2a.size() < ans.size())
      ans = p1a + p2a;

    if (p2.size() % p1.size() == 0) {
      int idx = 0;
      bool is_repeated = true;

      while (is_repeated && idx != p2.size()) {
        for (int i = 0; i < p1.size(); ++i) {
          if (p2[idx+i] != p1[i]) {
            is_repeated = false;
            break;
          }
        }
        idx += p1.size();
      }

      if (is_repeated) {
        string t = toString(p2.size()/p1.size()+1);
        if (t.size() + p1a.size() + 2 < ans.size()) {
          ans = t + "(" + p1a + ")";
        }
      }
    }
  }

  return ans;
}

int main(int argc, char** argv) {
  int N;
  cin >> N;
  string s;
  cin >> s;
  cout << fold(s) << endl;

  return 0;
}
