#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <cstdarg>
#include <cstdio>
#include <utility>

using namespace std;

int N;
string message;

string ansCompression;

string constCompression;

const int MAX_SIZE = 1000;

string toString(int v) {
  ostringstream oss;
  oss << v;

  return oss.str();
}

int toInt(const string& v) {
  istringstream iss(v);

  int ans;
  iss >> ans;
  return ans;
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

pair<bool,string> decompress(const string& s) {
  string ans;

  for (size_t i = 0; i < s.size(); ++i) {
    if ('A' <= s[i] && s[i] <= 'Z') {
      ans += s[i];
      continue;
    }

    string snum;
    while (i < s.size() && '0' <= s[i] && s[i] <= '9') {
      snum += s[i++];
    }

    if (i >= s.size() || s[i] != '(') {
      return make_pair<bool, string>(false, "");
    }

    int start_idx = ++i;
    int num_open = 1;

    while (i < s.size() && num_open > 0) {
      if (s[i] == '(') ++num_open;
      if (s[i] == ')') --num_open;
      ++i;
    }
    --i;

    string subseq = s.substr(start_idx, i-start_idx);

    pair<bool, string> decsubseq = decompress(subseq);

    if (!decsubseq.first) return make_pair<bool, string>(false, "");

    for (int j = toInt(snum); j > 0; --j)
      ans += decsubseq.second;
  }

  return make_pair(true, ans);
}

/* Call this to assign the score. The reason takes a printf-style
 * format string. It does not return.
 */
static void givescore(int score, const char *reason, ...)
{
    va_list ap;

    printf("Score:  %d\nReason: ", score);
    va_start(ap, reason);
    vprintf(reason, ap);
    va_end(ap);
    printf("\n");
    exit(0);
}

void readin(istream &in)
{
    in.exceptions(ios::failbit);

    /* Read input from in. Do not close it at the end */
    in >> N;
    in >> message;
}

static void readin(const string &fname)
{
    if (fname != "")
    {
        ifstream in(fname.c_str());
        assert(in);
        readin(in);
    }
    else
        readin(cin);
}

static void solve()
{
  fold(message, 0, message.size());
  ansCompression = folded[0][message.size()];
}

static void writeout(ostream &out)
{
    out.exceptions(ios::failbit);

    out << ansCompression << endl;
    /* Write the output to out. Do not close it afterwards */
}

static void writeout(const string &fname)
{
    if (fname != "")
    {
        ofstream out(fname.c_str());
        assert(out);
        writeout(out);
    }
    else
        writeout(cout);
}

static void readout(const string &fname)
{
    ifstream out(fname.c_str());
    assert(out);
    out.exceptions(ios::failbit);
    try
    {
      out >> constCompression;
    }
    catch (ios_base::failure &e)
    {
        givescore(0, "Invalid formatting");
    }
}

static void evaluate()
{
  pair<bool, string> constDecompression = decompress(constCompression);
  if (!constDecompression.first) {
    givescore(0, "Invalid compression string: bad formatting");
    return;
  }

  if (constDecompression.second != message) {
    givescore(0, "Invalid compression string: wrong message encoded");
    return;
  }

  if (constCompression.size() > ansCompression.size()) {
    givescore(0, "Compressed message unoptimal");
    return;
  }

  if (constCompression.size() < ansCompression.size()) {
    givescore(9001, "Compressed message superoptimal - ERROR: FIX MARKER");
    return;
  }

  givescore(10, "Correct answer");
}

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        readin("");
        solve();
        writeout("");
    }
    else
    {
        assert(argc > 2);
        cout << "Reading input file" << endl;
        readin(argv[1]);
        cout << "Solving problem" << endl;
        solve();
        cout << "Reading output file" << endl;
        readout(argv[2]);
        cout << "Evaluating" << endl;
        evaluate();
    }
    return 0;
}
