#include <bits/stdc++.h>
using namespace std;

string s[] = {"h", "he", "li", "be", "b", "c", "n", "o", "f", "ne", "na", "mg", "al", "si", "p", "s", "cl", "ar", "k", "ca", "sc", "ti", "v", "cr", "mn", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr", "rb", "sr", "y", "zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb", "te", "i", "xe", "cs", "ba", "hf", "ta", "w", "re", "os", "ir", "pt", "au", "hg", "tl", "pb", "bi", "po", "at", "rn", "fr", "ra", "rf", "db", "sg", "bh", "hs", "mt", "ds", "rg", "cn", "fl", "lv", "la", "ce", "pr", "nd", "pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu", "ac", "th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr"};
int main() {
    int n;
    int size = 114;
    cin >> n;
    sort(s,s+size);

    for(int i = 0; i < n; i++) {
        string input;
        cin >> input;
        bool F[] = {0,0,1};
        for(int j=0; j < input.size(); j++) {
            string tmp;
            tmp.push_back(input[j]);
            F[j%3] = 0;
            if(F[(j-1+3)%3]&&*lower_bound(s,s+size,tmp) == tmp)
                F[j%3]=1;
            else if(j >= 1 && F[(j-2+3)%3]) {
                tmp.clear();
                tmp.push_back(input[j-1]);
                tmp.push_back(input[j]);
                if(*lower_bound(s,s+size,tmp) == tmp)
                    F[j%3] = 1;
                }
            }
        if(F[(input.size()-1)%3]) puts("YES");
        else puts("NO");
        }
    }
