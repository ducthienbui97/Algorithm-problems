#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <utility>

using namespace std;

string toString(int v) {
  ostringstream oss;
  oss << v;

  return oss.str();
}

map<string, string> folded;

void fold(const string& s) {
  if (folded.count(s) != 0)
    return;

  folded[s] = s;
  //repeats[s][s] = 1;

  for (int i = 1; i < s.size(); ++i) {
    const string p1 = s.substr(0, i);
    const string p2 = s.substr(i);
    fold(p1);
    fold(p2);
    const string p1a = folded[p1];
    const string p2a = folded[p2];

    string t = p1a + p2a;

    if (t.size() < folded[s].size())
      folded[s] = t;

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
        if (t.size() < folded[s].size()) {
          folded[s] = t;
        }
      }
    }
  }
}

int main(int argc, char** argv) {
  int N;
  cin >> N;
  string s;
  cin >> s;

  fold(s);
  cout << folded[s] << endl;

  return 0;
}
