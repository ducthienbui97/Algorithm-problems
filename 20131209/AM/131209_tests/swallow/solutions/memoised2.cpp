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
map<string, map<string, int> > repeats;

void fold(const string& s) {
  if (folded.count(s) != 0)
    return;


  folded[s] = s;
  repeats[s] = map<string, int>();
  repeats[s][s] = 1;

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

    if (repeats[p2].count(p1) != 0) {
        repeats[s][p1] = repeats[p2][p1]+1;
        t = toString(repeats[p2][p1]+1) + "(" + p1a + ")";
        if (t.size() < folded[s].size()) {
          folded[s] = t;
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
