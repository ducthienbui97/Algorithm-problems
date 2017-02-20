#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <utility>

using namespace std;

const int MAX_SIZE = 1000;

string toString(int v) {
  ostringstream oss;
  oss << v;

  return oss.str();
}

string folded[MAX_SIZE+1][MAX_SIZE+1];

void fold(const string& s, int i, int j) {
  if (!folded[i][j].empty())
    return;

  folded[i][j] = s.substr(i, j-i);
  if (j-i == 1) {
    return;
  }

  for (int k = i+1; k < j; ++k) {
    fold(s, i, k);
    fold(s, k, j);

    const string& p1a = folded[i][k];
    const string& p2a = folded[k][j];

    if (p1a.size() + p2a.size() < folded[i][j].size())
      folded[i][j] = p1a + p2a;

    if ((j-k) % (k-i) == 0) {
      const string& p1 = s.substr(i, k-i);
      int idx = k;
      bool is_repeated = true;

      while (idx != j) {
        if (s.substr(idx, p1.size()) != p1) {
          is_repeated = false;
          break;
        }
        idx += p1.size();
      }

      if (is_repeated) {
        string t = toString((j-k)/p1.size()+1);
        if (t.size() + p1a.size() + 2 < folded[i][j].size()) {
          folded[i][j] = t + "(" + p1a + ")";
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

  fold(s, 0, s.size());
  
  cout << folded[0][s.size()] << endl;

  return 0;
}
