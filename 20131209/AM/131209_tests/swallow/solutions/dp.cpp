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

void fold(const string& s) {

  for (int w = 1; w <= s.size(); ++w) {
    for (int i = 0; i < s.size()-w+1; ++i) {
      folded[i][i+w] = s.substr(i, w);
      for (int j = 1; j < w; ++j) {
        string t = folded[i][i+j] + folded[i+j][i+w];
        if (t.size() < folded[i][i+w].size()) {
          folded[i][i+w] = t;
        }

        if (w % j == 0) {
          int d = j;
          bool is_repeated = true;

          while (d != w) {
            if (s.substr(i+d, j) != s.substr(i, j)) {
              is_repeated = false;
              break;
            }
            d += j;
          }

          if (is_repeated) {
            t = toString(w/j) + "(" + folded[i][i+j] + ")";
            if (t.size() < folded[i][i+w].size()) {
              folded[i][i+w] = t;
            }
          }
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
  
  cout << folded[0][s.size()] << endl;

  return 0;
}
