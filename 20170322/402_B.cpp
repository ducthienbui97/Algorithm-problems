#include <bits/stdc++.h>
using namespace std;
const int Maxn = 5005;
enum Operator {XOR,AND,OR};
enum Type {VALUE,NON_VALUE};
struct {
    int L,R;
    Operator ope;
    string value;
    Type type;
} v[Maxn];
map<string,int> idx;
char cal(char l,char r,Operator ope){
    if(ope == XOR){
        return ((l-'0')^(r-'0')) + '0';
    }
    else if(ope == OR){
        return ((l-'0')|(r-'0')) + '0';
    }
    else if(ope == AND){
        return ((l-'0')&(r-'0')) + '0';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >>m;
    string mx(m,'0'),mn(m,'0');
    idx["?"] = 0;
    v[0].value = string(m,'0');
    for(int i=1; i<=n; i++) {
        string tmp;
        cin >> tmp;
        idx[tmp] = i;
        cin >> tmp;
        cin >> tmp;
        if(tmp[0] == '0' || tmp[0] == '1') {
            v[i].type = VALUE;
            v[i].value = tmp;
        } else {
            v[i].value = string(m,'0');
            v[i].type = NON_VALUE;
            v[i].L = idx[tmp];
            cin >> tmp;
            if(tmp == "XOR") v[i].ope = XOR;
            else if(tmp == "AND") v[i].ope = AND;
            else v[i].ope = OR;
            cin >> tmp;
            v[i].R = idx[tmp];
        }
    }
    for(int i=0; i<m; i++) {
        int cnt[2] = {0,0};
        for(char pos = '0'; pos <= '1'; pos ++) {
            v[0].value[i] = pos;
            for(int j=1; j<=n; j++) {
                if(v[j].type == NON_VALUE){
                    int l = v[j].L;
                    int r = v[j].R;
                    v[j].value[i]  = cal(v[l].value[i],v[r].value[i],v[j].ope);
                }
                if(v[j].value[i] == '1') cnt[pos-'0']++;
            }
        }
        if(cnt[0] < cnt[1]){
            mn[i] = '0';
            mx[i] = '1';
        }else if(cnt[0] > cnt[1]){
            mn[i] = '1';
            mx[i] = '0';
        }else{
            mn[i] = '0';
            mx[i] = '0';
        }
    }
    cout << mn <<" "<<mx<<endl;
}
