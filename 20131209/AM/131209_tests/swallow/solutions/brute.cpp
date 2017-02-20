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

    string t = p1a + p2a;
    if (t.size() < ans.size())
      ans = t;

    if (p2.size() % p1.size() == 0) {
      int idx = 0;
      bool is_repeated = true;

      while (idx != p2.size()) {
        if (p2.substr(idx, p1.size()) != p1) {
          is_repeated = false;
          break;
        }
        idx += p1.size();
      }

      if (is_repeated) {
        t = toString(p2.size()/p1.size()+1) + "(" + p1a + ")";
        if (t.size() < ans.size()) {
          ans = t;
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
